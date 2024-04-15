#include <stdio.h>
#include <stdlib.h>

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
    return(n_usuaris);    
}

char guardar_usuaris()
{

}

char guardar_amistats()
{
    
}