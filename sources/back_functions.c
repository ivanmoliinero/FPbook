#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "estructures.h"
#include "back_functions.h"

#define MAX_DATA 11 // Longitud màxima del string de la data que es llegeix dels arxius.
#define MAX_TEMP 4 // Longitud màxima possible de cada dada (any).

void carregar_dia(persona_t *us, char data[], unsigned char *index)
{
    char temp[MAX_TEMP];
    unsigned char i = 0;
    while(data[*index] != '/')
    {
        temp[i] = data[*index];
        (*index)++;
        i++;
    }
    temp[i] = '\0';
    (*index)++; // Deixa l'índex preparat per la lectura del mes.
    us->data_neix.dia = (char)atoi(temp);
}

void carregar_mes(persona_t *us, char data[], unsigned char *index)
{
    char temp[MAX_TEMP];
    unsigned char i = 0;
    while(data[*index] != '/')
    {
        temp[i] = data[*index];
        (*index)++;
        i++;
    }
    temp[i] = '\0';
    (*index)++; // Deixa l'índex preparat per la lectura de l'any.
    us->data_neix.mes = (char)atoi(temp);
}

void carregar_any(persona_t *us, char data[], unsigned char *index)
{
    char temp[MAX_TEMP];
    unsigned char i = 0;
    while(data[*index] != 0)
    {
        temp[i] = data[*index];
        (*index)++;
        i++;
    }
    temp[i] = '\0';
    us->data_neix.any = (short)atoi(temp);
}

void carregar_data(FILE *f, persona_t *us) // COM SEPARAR DATES PER INCLOURE-HO DINS D'UN STRUCT.
{
    char data[MAX_DATA];
    fscanf(f, "%s", data);
    unsigned char i = 0;
    carregar_dia(us, data, &i);
    carregar_mes(us, data, &i);
    carregar_any(us, data, &i);
}

void carregar_usuari(FILE *f, persona_t *usuari)
{
    fscanf(f, "%hd", &usuari->id);
    fscanf(f, "%s", usuari->nom);
    fscanf(f, "%s", usuari->genere);
    fscanf(f, "%s", usuari->ciutat);
    carregar_data(f, usuari);
}

short carregar_usuaris(persona_t **usuaris)
{
    FILE *f = fopen("data/usuaris.fpb", "r");
    short n_usuaris; // short perquè com a màxim serà de 10000 (definit a l'enunciat de la pràctica".)
    if(f != NULL)
    {
        fscanf(f, "%hd", &n_usuaris);
        *usuaris = malloc(sizeof(persona_t)*n_usuaris);
        if(*usuaris != NULL) // S'ha pogut crear la taula.
        {
            for(short i = 0; i < n_usuaris; i++)
            {
                carregar_usuari(f, &((*usuaris)[i]));
            }
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
   fprintf(f, "%hd", usuari->id);
   fprintf(f, "%s", usuari->nom);
   fprintf(f, "%s", usuari->nom);
   fprintf(f, "%s", usuari->ciutat);
   guardar_data(f, usuari); // Es passa per referència per evitar sobresaturar la pila innecessàriament.
   fprintf(f, "%c", '\n'); // Separador estètic entre usuaris.
}

bool guardar_usuaris(persona_t *t, short n_elem)
{
    FILE *f = fopen("data/usuaris.fpb", "r+"); // S'obre el fitxer d'usuaris per llegir/escriure. Així es força a que l'arxiu ja existeixi prèviament (s'eviten sobreescriure dades inútilment).
    bool res;
    short n_elem_antics, iteracions;
    if(f == NULL)
        res = false; 
    else
    {   
        fscanf(f, "%hd", &n_elem_antics);
        iteracions = n_elem - n_elem_antics; // Nombre d'usuaris nous que s'afegeixen a la base d'usuaris.
        fprintf(f, "%hd", n_elem); // Es reescriu el nombre d'usuaris.
        res = fseek(f, 0L, SEEK_END); // Es retorna 0 i es guarda en res. 0L perquè es demana un nombre de tipus long. Es col·loca el punter de l'arxiu al final d'aquest.
        if(!res) // Com es retorna 0 (false), s'ha de mirar el contrari (1, cert) per entrar al condicional. 
            res = false;
        else
        {
            fprintf(f, "%c", '\n'); // S'escriu el separador estètic per l'arxiu de salt de línia.
            for(short i = n_elem - iteracions; i < n_elem; i++)
                guardar_usuari(f, &t[i]);
        }
    }
    fclose(f);
    return(res);
}

bool guardar_amistats(int *amistats, short n_elem)
{
    FILE *f = fopen("data/propers.fpb", "w"); /* S'obre el fitxer de propers (totes les amistats del sistema) per escriure. A diferència del d'usuaris, aquest
                                                 s'ha de reescriure sencer, ja que pot patir modificacions intermitges o addicions de columnes. En cas que no
                                                 existeixi, s'intentarà crear, ja que ja es té la informació de totes les amistats*/
    bool res;
    if(f == NULL) 
        res = false; // L'arxiu s'ha creat (o no), no s'ha trobat un arxiu d'usuaris, no es pot guardar la informació correctament. Se suposa que com a mínim un arxiu tindrà el nombre d'usuaris.
    else
    {
        fprintf(f, "%hd\n", n_elem);
        for(short i = 0; i < n_elem; i++) // Files.
        {
            fprintf(f, "%s", "  "); // Dos espais en blanc, d'acord amb el format dels fitxers proporcionats a la pràctica.
            for(short j = 0; j < n_elem; j++) // Columnes.
            {
                if(amistats[i*n_elem+j] >= 0)  fprintf(f, "%c", ' '); // En cas que el primer element sigui major o igual a 0, s'afegeix un espai més. Si no, aquesta posició l'ocuparà el signe negatiu.
                fprintf(f, "%d ", amistats[i*n_elem+j]);
            }
            fprintf(f, "%c", '\n'); // Salt de línia per separar files.
        }        
    }
    fclose(f);
    return(res);
}

void afegir_usuari()
{
    
}