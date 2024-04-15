#include <stdio.h>
#include <stdlib.h>

#include "estructures.h"
#include "back_functions.h"
void carregar_usuari(FILE *f, persona_t *t, short usuari)
{
    fscanf(f, "%d", t[usuari].id);
    // TODO: Funció per obtenir cadena de caràcters a partir de fitxer (nom).
    // TODO: Funció per obtenir cadena de caràcters a partir de fitxer (ciutat).
}
short carregar_usuaris(persona_t *t)
{
    FILE *f = fopen("data/usuaris.fpb", "r");
    short n_usuaris; // short perquè com a màxim serà de 10000 (definit a l'enunciat de la pràctica".)
    if(f!=NULL)
    {
        fscanf(f, "%d", &n_usuaris);
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