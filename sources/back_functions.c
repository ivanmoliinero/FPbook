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
    (*index)++; // Deixa l'índex preparat per la lectura del mes.
    us->data_neix.dia = atoi(temp);
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
    (*index)++; // Deixa l'índex preparat per la lectura de l'any.
    us->data_neix.mes = atoi(temp);
}

void carregar_any(persona_t *us, char data[], unsigned char *index)
{
    char temp[MAX_TEMP];
    unsigned char i = 0;
    while(data[*index] != 0)
    {
        temp[i] = data[*index];
        (*index)++;
    }
    us->data_neix.any = atoi(temp);
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

void carregar_usuari(FILE *f, persona_t *t, short usuari)
{
    fscanf(f, "%hd", &t[usuari].id);
    fscanf(f, "%s", t[usuari].nom);
    fscanf(f, "%s", t[usuari].genere);
    fscanf(f, "%s", t[usuari].ciutat);
    carregar_data(f, &t[usuari]);
}

short carregar_usuaris(persona_t *t)
{
    FILE *f = fopen("data/usuaris.fpb", "r");
    short n_usuaris; // short perquè com a màxim serà de 10000 (definit a l'enunciat de la pràctica".)
    if(f!=NULL)
    {
        fscanf(f, "%hd", &n_usuaris);
        t = malloc(sizeof(persona_t)*n_usuaris);
        for(short i = 0; i < n_usuaris; i++)
        {
            carregar_usuari(f, t, i);
        }
    }
    else
        n_usuaris = -1;
    fclose(f);
    return(n_usuaris);    
}

void guardar_data(FILE *f, persona_t *usuari) // Es passa per referència per evitar sobresaturar la pila.
{
    fprintf(f, "%c", usuari->data_neix.dia); // REVISAR COMO GUARDAR CHAR.
    fprintf(f)
}

void guardar_usuari(FILE *f, persona_t *t, short usuari)
{
   fprintf(f, "%hd", t[usuari].id);
   fprintf(f, "%s", t[usuari].nom);
   fprintf(f, "%s", t[usuari].nom);
   fprintf(f, "%s", t[usuari].ciutat);
   guardar_data(f, &t[usuari]); // Es passa per referència per evitar sobresaturar la pila innecessàriament.
}

bool guardar_usuaris(persona_t *t, short n_elem)
{
    FILE *f = fopen("data/usuaris.fpb", "w"); // S'obre el fitxer d'usuaris.
    bool res;
    short n_elem_antics, iteracions;
    if(f = NULL || feof(f))
        res = false; // L'arxiu s'ha creat (o no), no s'ha trobat un arxiu d'usuaris, no es pot guardar la informació correctament. Se suposa que com a mínim un arxiu tindrà el nombre d'usuaris.
    else
    {   
        fscanf(f, "%hd", &n_elem_antics);
        iteracions = n_elem - n_elem_antics; // Nombre d'usuaris nous que s'afegeixen a la base d'usuaris.
        fprintf(f, "%hd", n_elem); // Es reescriu el nombre d'usuaris.
        res = fseek(f, 0L, SEEK_END); // Es retorna 0 i es guarda en res. 0L perquè es demana un nombre de tipus long. Es col·loca el punter de l'arxiu al final d'aquest.
        if(!res) 
            res = false;
        else
        {
            fprintf(f, "%c", '\n'); // S'escriu el separador estètic per l'arxiu de salt de línia.
            for(char i = n_elem - iteracions; i < n_elem; i++)
            {
                guardar_usuari(f, t, i);
            }
        }
    }
    fclose(f);
    return(res);
}

bool guardar_amistats()
{

}