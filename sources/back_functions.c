#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "estructures.h"
#include "back_functions.h"

void carregar_data(FILE *f, persona_t *us)
{
    fscanf(f, "%hd/%hd/%hd", (short*)&us->data_neix.dia, (short*)&us->data_neix.mes, &us->data_neix.any); /* Cal fer casting a short per tal de poder llegir correctament
                                                                                                           les dades. Quan es guardin, ja es guarden en un char */
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
        rewind(f); // Es torna a l'inici de l'arxiu.
        fprintf(f, "%hd", n_elem); // Es reescriu el nombre d'usuaris.
        res = fseek(f, 0L, SEEK_END); // Es retorna 0 i es guarda en res. 0L perquè es demana un nombre de tipus long. Es col·loca el punter de l'arxiu al final d'aquest.
        if(!res) // Com es retorna 0 (false), s'ha de mirar el contrari (1, cert) per entrar al condicional. 
        {
            res = true;
            fprintf(f, "\n\n"); // S'escriu el separador estètic per l'arxiu de salt de línia.
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
        short dir; // Variable per evitar recalcular constantment i * n_elem+ j
        fprintf(f, "%hd\n", n_elem);
        for(short i = 0; i < n_elem; i++) // Files.
        {
            fprintf(f, "  "); // Dos espais en blanc, d'acord amb el format dels fitxers proporcionats a la pràctica.
            dir = (i * (i + 1))/2; // j = 0;
            while(amistats[dir] != 0) // Quan s'arriba al 0, es guarda aquest valor i es deixen de guardar dades.
            {
                if(amistats[dir] >= 0)  fprintf(f, "%c", ' '); // En cas que el primer element sigui major o igual a 0, s'afegeix un espai més. Si no, aquesta posició l'ocuparà el signe negatiu.
                fprintf(f, "%d ", amistats[dir]);
                dir++; // j++;
            }
            fprintf(f, " 0\n"); // Sentinella 0 + salt de línia per separar files.
        }        
    }
    fclose(f);
    return(res);
}

void afegir_usuaris(persona_t **usuaris, short n_usuaris)
{
    // TODO: Demanar nombre nous usuaris en variable n_nous.
    // short n_finals = n_usuaris + n_nous;
    // realloc(*usuaris, sizeof(persona_t)*n_finals);
    // for(short i = n_usuaris; i < n_finals; i++)
    //     afegir_usuari(&(*usuaris)[i]); // Implementar en interface_functions.  

}