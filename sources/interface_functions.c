#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "estructures.h"
#include "interface_functions.h"

short obtenir_opcio_convertida()
{
    char o[MAX_OPCIO];
    scanf("%s", o); // Obté l'opció escrita com un caràcter.
    short res = (short)atoi(o);
    if(res == 0 && (o[0] != '0' || o[1] != 0)) // Si el retorn de l'atoi és 0 però l'usuari no havia introduït el dígit 0:
        res = -1;                              // error, introducció de caràcter.
    return(res); // Conversió a enter, es guarda en short (màxima longitud de nombre emprada en el programa.)
}

short demanar_n_usuaris_nous()
{
    short n_nous;
    do
    {
        printf("Quants usuaris nous vols introduir?\n");
        n_nous = obtenir_opcio_convertida();
        if(n_nous <= 0 || n_nous > MAX_USUARIS) printf("Introdueix un nombre positiu menor a %hd\n", MAX_USUARIS);
        
    } while (0 >= n_nous || n_nous >= MAX_USUARIS);
    
    return(n_nous);
}

void demanar_data(persona_t *usuari) // IMPLEMENTAR CON FUNCION DO - WHILE GENÉRICA ERIC.
{
    short temp;
    bool mes_correcte;
    do
    {
        printf("Introdueix el mes de naixement de l'usuari:\n");
        temp = obtenir_opcio_convertida();
        if(temp < 1 || temp > 12) printf("Introdueix un més vàlid, entre 1 i 12\n");
    } while (temp < 1 || temp > 12);
    usuari->data_neix.mes = (char)temp;
    do
    {
        printf("Introdueix l'any de naixement de l'usuari:\n");
        temp = obtenir_opcio_convertida();
        if(temp < 0) printf("Introdueix un any vàlid, no negatiu.\n");
    } while (temp < 0);
    do
    {
        printf("Introdueix el dia de naixement de l'usuari:\n");
        temp = obtenir_opcio_convertida();
        mes_correcte = data_compatible(temp, usuari->data_neix.any, usuari->data_neix.mes);
        if(!mes_correcte) printf("Introdueix un dia vàlid per aquest mes\n");
    } while (!mes_correcte);
    usuari->data_neix.dia = (char)temp;   
}

void afegir_usuari(persona_t *usuari) // CAL REAJUSTAR PER OBTENIR OPCIONS CORRECTES EN DATA.
{
    printf("Introdueix el nom del nou usuari\n");
    scanf("%s", usuari->nom);
    printf("Introdueix el gènere del nou usuari\n");
    scanf("%s", usuari->genere);
    printf("Introdueix la ciutat del nou usuari\n");
    scanf("%s", usuari->ciutat);
    demanar_data(usuari);
}