#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#include "estructures.h"
#include "back_functions.h"
#include "interface_functions.h"

void carregar_data(FILE *f, persona_t *us)
{
    fscanf(f, "%hd/%hd/%hd", (short*)&us->data_neix.dia, (short*)&us->data_neix.mes, &us->data_neix.any); /* Cal fer casting a short per tal de poder llegir correctament
                                                                                                           les dades. Quan es guardin, ja es guarden en un char */
}

bool carregar_usuari(FILE *f, persona_t *usuari)
{
    char dummy[MAX_DUMMY], n_elem_dummy;
    fscanf(f, "%hd\n", &usuari->id);
    fgets(dummy, MAX_DUMMY, f);
    n_elem_dummy = strlen(dummy) + 1; // +1 pel caràcter \0.
    usuari->nom = malloc(sizeof(char)*n_elem_dummy);
    if (usuari->nom == NULL) return false;
    strcpy(usuari->nom, dummy);

    fgets(dummy, MAX_DUMMY, f);
    n_elem_dummy = strlen(dummy) + 1; // +1 pel caràcter \0.
    usuari->genere = malloc(sizeof(char)*n_elem_dummy);
    if (usuari->genere == NULL) return false;
    strcpy(usuari->genere, dummy);

    fgets(dummy, MAX_DUMMY, f);
    n_elem_dummy = strlen(dummy) + 1; // +1 pel caràcter \0.
    usuari->ciutat = malloc(sizeof(char)*n_elem_dummy);
    if (usuari->ciutat == NULL) return false;
    strcpy(usuari->ciutat, dummy);

    carregar_data(f, usuari);
    return true;
}

short carregar_usuaris(persona_t **usuaris)
{
    FILE *f = fopen("data/usuaris.fpb", "r");
    short n_usuaris; // short perquè com a màxim serà de 10000 (definit a l'enunciat de la pràctica".)
    bool correcte = true;
    if(f != NULL)
    {
        fscanf(f, "%hd", &n_usuaris);
        *usuaris = malloc(sizeof(persona_t)*n_usuaris);
        if(*usuaris != NULL) // S'ha pogut crear la taula.
        {
            for(short i = 0; i < n_usuaris && correcte; i++)
            {
                correcte = carregar_usuari(f, &((*usuaris)[i]));
            }
            if(!correcte) n_usuaris = -1;
        }
        else
            n_usuaris = -1; // No s'ha pogut crear la taula amb malloc.
    }
    else // Problemes en l'obertura del fitxer.
        n_usuaris = -1;
    fclose(f);
    return(n_usuaris);    
}

void guardar_data(FILE *f, persona_t *usuari) // Es passa per referència per evitar sobresaturar la pila.
{
    fprintf(f, "%hd", (short)usuari->data_neix.dia); // Fem casting a short per guardar els char, al final es guardarà el nombre.
    fprintf(f, "%c", '/');
    fprintf(f, "%hd", (short)usuari->data_neix.mes);
    fprintf(f, "%c", '/');
    fprintf(f, "%hd", usuari->data_neix.any);
}

void guardar_usuari(FILE *f, persona_t *usuari)
{
   fprintf(f, "%hd\n", usuari->id);
   fprintf(f, "%s", usuari->nom);
   fprintf(f, "%s", usuari->genere);
   fprintf(f, "%s", usuari->ciutat);
   guardar_data(f, usuari); // Es passa per referència per evitar sobresaturar la pila innecessàriament.
   fprintf(f, "\n\n"); // Separador estètic entre usuaris.
}

bool guardar_dades(persona_t *usuaris, char *amistats, short n_elem, bool usuaris_editats, bool amistats_editades)
{
    bool resultat = false;
    if(amistats_editades && !usuaris_editats) // Només s'ha editat l'arxiu d'amistats.
    {
        FILE *fitxer_amistats = fopen("data/propers.fpb", "w"); /* S'obre el fitxer de propers (totes les amistats del sistema) per escriure. A diferència del d'usuaris, aquest
                                                                s'ha de reescriure sencer, ja que pot patir modificacions intermitges o addicions de columnes. En cas que no
                                                                existeixi, s'intentarà crear, ja que ja es té la informació de totes les amistats*/
        if(fitxer_amistats != NULL)
        {
            resultat = true;
            guardar_amistats(amistats, n_elem, fitxer_amistats);
        }
        fclose(fitxer_amistats);
    }
    else if (usuaris_editats) // S'ha editat l'arxiu d'usuaris cal actualitzar ambdós.
    {
        FILE *fitxer_usuaris = fopen("data/usuaris.fpb", "r+"); // S'obre el fitxer d'usuaris per llegir/escriure. Així es força a que l'arxiu ja existeixi prèviament (s'eviten sobreescriure dades inútilment).
        FILE *fitxer_amistats = fopen("data/propers.fpb", "w"); /* S'obre el fitxer de propers (totes les amistats del sistema) per escriure. A diferència del d'usuaris, aquest
                                                                s'ha de reescriure sencer, ja que pot patir modificacions intermitges o addicions de columnes. En cas que no
                                                                existeixi, s'intentarà crear, ja que ja es té la informació de totes les amistats*/
        if(fitxer_usuaris != NULL && fitxer_amistats != NULL)
        {
            resultat = true;
            guardar_usuaris(usuaris, n_elem, fitxer_usuaris);
            guardar_amistats(amistats, n_elem, fitxer_amistats);
        }
        fclose(fitxer_amistats);
        fclose(fitxer_usuaris);
    }
    return resultat;
}

void guardar_usuaris(persona_t *t, short n_elem, FILE *f)
{
    short n_elem_antics, iteracions;
    fscanf(f, "%hd", &n_elem_antics);
    iteracions = n_elem - n_elem_antics; // Nombre d'usuaris nous que s'afegeixen a la base d'usuaris.
    rewind(f); // Es torna a l'inici de l'arxiu.
    fprintf(f, "%hd", n_elem); // Es reescriu el nombre d'usuaris.
    fseek(f, 0L, SEEK_END);
    for(short i = n_elem - iteracions; i < n_elem; i++)
        guardar_usuari(f, &t[i]);
}

void guardar_amistats(char *amistats, short n_elem, FILE *f)
{
    int valors = (n_elem*(n_elem+1))/2;
    fprintf(f, "   %hd\n", n_elem);
    for(int dir = 0; dir < valors; dir++) // Files.
    {
        fprintf(f, "  "); // Dos espais en blanc, d'acord amb el format dels fitxers proporcionats a la pràctica.
        while(amistats[dir] != 0) // Quan s'arriba al 0, es guarda aquest valor i es deixen de guardar dades.
        {
            if(amistats[dir] >= 0) fprintf(f, "%c", ' '); // En cas que el primer element sigui major o igual a 0, s'afegeix un espai més. Si no, aquesta posició l'ocuparà el signe negatiu.
            fprintf(f, "%d ", amistats[dir]);
            dir++; // j++;
        }
        fprintf(f, " 0\n"); // Sentinella 0 + salt de línia per separar files.
    }        
}

short actualitzacio_usuaris(persona_t **usuaris, short n_usuaris, short n_nous)
{
    short n_finals = n_usuaris + n_nous;
    bool correcte = true;
    *usuaris = realloc(*usuaris, sizeof(persona_t)*n_finals); // Ampliació del vector d'usuaris. CONSIDERAR CANVIAR PER CONTROL D'ERRORS.
    if (*usuaris != NULL)
    {
        for(short i = n_usuaris, j = 1; i < n_finals && correcte; i++, j++)
        {
            printf("Nou usuari %hd\n", j);
            correcte = afegir_usuari(&((*usuaris)[i]));
            ((*usuaris)[i]).id = i; // S'afegeix l'identificador aquí per evitar sobresaturar la funció afegir_usuari().
        }
        if(!correcte) n_finals = -1;   
    }
    else
        n_finals = -1;
    return(n_finals);
}   

bool actualitzacio_amistats(char **amistats, short n_usuaris, short n_nous)
{
    short n_finals = n_usuaris + n_nous;
    bool correcte;
    *amistats = realloc(*amistats, sizeof(char)*(((n_finals * (n_finals + 1)) / 2))); // Amplicació de la taula amistats.
    if (*amistats != NULL)
    {
        correcte = true;
        int dir;
        for (short i = n_usuaris; i < n_finals; i++)
        {
            dir = (i * (i + 1))/2;
            for(short j = 0; j < i; j++, dir++)
            {
                (*amistats)[dir] = (char)genera_aleatori(1, 9); // Casting necessari per no provocar conflictes al heap.
            }
            (*amistats)[dir] = 0; // Sentinella 0.
        }
    }
    else
        correcte = false;
    return correcte;
}

short afegir_usuaris(persona_t **usuaris, char **amistats, short n_usuaris)
{
    persona_t *temp_usuaris = *usuaris;
    char *temp_amistats = *amistats; // Taules temporals per controlar els realloc.
    demanar_n_usuaris_nous();
    short n_maxim = MAX_USUARIS - n_usuaris;
    short n_nous = demanar_opcio(n_maxim, 1);
    
    short n_final = actualitzacio_usuaris(&temp_usuaris, n_usuaris, n_nous);
    if(n_final != -1)
    {
        if(!actualitzacio_amistats(&temp_amistats, n_usuaris, n_nous))
        {
            n_final = -1;
            free(temp_usuaris);
            free(temp_amistats); // No s'ha acabat de completar el guardat de noves dades, free a les temporals.
        }
        else // S'ha executat correctament.
        {
            *usuaris = temp_usuaris;
            *amistats = temp_amistats; // Col·locació d'adreces amb tota la info carregada als paràmetres.
        }
    }
    else
    {
        free(temp_usuaris); // Buidem el que s'hagi omplert.
    }
    
    return(n_final);
}

bool data_compatible(char dia, char mes, short any)
{
    bool correcte;
    if(mes == 2 && dia == 29) // Comprovació cas any estacionari.
        correcte = (any % 4 == 0 && ((any % 100 == 0 && any % 400 == 0) || any % 100 != 0)); // Fórmula per veure si un any és estacionari.
    else if (dia < 0) correcte = false; // S'evita ocupar la pilla innecessàriament.
    else
    {
        int dies_mes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        correcte = 0 < dia && dia <= dies_mes[mes - 1];
    }
    return correcte;
}

void ini_llavor()
{
    srand(time(NULL));
}

int genera_aleatori(int min, int max)
{
    return(min + rand()%(max-min+1));
}

short obtenir_usuari(char *argv[], short n_elem)
{
    short id = atoi(argv[1]); // Converteix la cadena de caràcters ASCII a un Integer(int).
    if (((id > n_elem - 1) || (id < 0)) || (id == 0 && (argv[1][0] != '0' || argv[1][1] != 0))) // Comprova que no s'hagui introduït un id inexistent o un caràcter no numèric.
        id = -1;
    return (id);
}

bool carregar_amistats(char **amistats)
{
    bool resultat = true;
    int dir = 0, n_elem;
    short i, j, fila_columna;
    FILE *fitxer = fopen("data/propers.fpb", "r"); // Obrim fitxer amb les dades d'amistats.
    short temp; // To charge values without over exceeding.

    if (fitxer == NULL)
    {
        resultat = false;
    }
    else
    {
        fscanf(fitxer, "%hd", &fila_columna); // Guardem el número de d'elements de cada fila/columna equivalent al número d'usuaris al sistema.
        n_elem = (((fila_columna * (fila_columna + 1)) / 2)); // Mètode d'adreçament = ((N * (N + 1)) / 2)
        *amistats = malloc(sizeof(char) * n_elem);             // Assignació dinàmica de memória.
        if (*amistats == NULL)
            resultat = false;
        else
        {
            resultat = true;
            for (i = 0; i < fila_columna; i++)
            {
                for (j = 0; j <= i; j++, dir++)
                {
                    fscanf(fitxer, "%hd", &temp);
                    (*amistats)[dir] = (char)temp;
                }
            }
        }
    }
    fclose(fitxer);
    return resultat;
}

void afegir_amistat(persona_t *usuaris, char **amistats, short n_usuaris, short usuari)
{
    int columna;
    bool correcte = false;
    short opcio, confirmacio;

    mostrar_compatibles(usuaris, *amistats, n_usuaris, usuari);

    while (!correcte)
    {
        missatge_seleccio_amistat();
        opcio = demanar_opcio(n_usuaris - 1, -1);

        if (opcio == -1) correcte = true; // Es surt del programa.
        else if (opcio == usuari)
        {
            printf("¡NO TE PUEDES AÑADIR TU MISMO COMO AMIGO!");
        }
        else
        {
            if (opcio < usuari)
            {
                columna = (((usuari * (usuari + 1)) / 2) + opcio); // Cerca de fila
            }
            else
            {
                columna = (((opcio * (opcio + 1)) / 2) + usuari); // Cerca de columna
            }

            if (((*amistats)[columna]) == -1)
            {
                printf("¡YA ES TU AMIGO!");
            }
            else if (((*amistats)[columna]) > COMPATIBILIDAD)
            {
                avis_compatibilitat_dolenta();
                confirmar(&confirmacio, DENEGAR, ACCEPTAR);
                if (confirmacio == ACCEPTAR)
                {
                    correcte = true;
                    ((*amistats)[columna]) = -1;
                }
            }
            else
            {
                correcte = true;
                ((*amistats)[columna]) = -1;
            }
        }
    }
}

void eliminar_amistat(char **amistats, short n_usuaris, short usuari)
{
    int columna;
    short opcio, confirmacio;
    bool correcte = false;

    printf("mostar_amistats()");

    while (!correcte)
    {
        missatge_esborrat_amistat();
        opcio = demanar_opcio(n_usuaris - 1, 0);

        if (opcio == usuari)
        {
            printf("¡NO TE PUEDES ELIMINAR TU MISMO COMO AMIGO!");
        }
        else
        {
            if (opcio < usuari)
            {
                columna = (((usuari * (usuari + 1)) / 2) + opcio); // Cerca de fila
            }
            else
            {
                columna = (((opcio * (opcio + 1)) / 2) + usuari); // Cerca de columna
            }

            if (((*amistats)[columna]) == -1)
            {
                printf("¡ELIMINAR AMISTAD!");
                confirmar(&confirmacio, DENEGAR, ACCEPTAR);

                if (confirmacio == ACCEPTAR)
                {
                    correcte = true;
                    ((*amistats)[columna]) = genera_aleatori(COMPATIBILIDAD, 9);
                }
            }
            else
            {
                printf("¡NO ES TU AMIGO!");
            }
        }
    }
}

void alliberacio_memoria(persona_t *usuaris, char *amistats, short n_usuaris)
{
    for(short i = 0; i < n_usuaris; i++)
    {
        free(usuaris[i].nom);
        free(usuaris[i].genere);
        free(usuaris[i].ciutat);
    }
    free(usuaris);
    free(amistats);
}

bool string_copy_without_trash(char origin[], char **dest)
{
    short last_index, i;
    bool correcte;
    for (i = 0; origin[i] != '\n'; i++)
        if(origin[i] != ' ') last_index = i;
    last_index++;
    origin[last_index] = '\0'; // additional spaces ignored.
    char new_lenght = strlen(origin); // length fins el caràcter sentinella \0.
    new_lenght+=2; // Pel caràcter \n.
    *dest = malloc(sizeof(char)*new_lenght);
    if(*dest == NULL)
        correcte = false;
    else
    {
        correcte = true;
        strcpy(*dest, origin);
        /* Les següents modificacions poden ser estudiades per veure si realment calen, però per evitar problemes de format
           i de heap s'inclouen */
        (*dest)[new_lenght-2] = '\n'; // Caràcter necessari per fer correctament els printf.
        (*dest)[new_lenght-1] = '\0'; // Caràcter per indicar fi sentinella.
    }
    return correcte;
}