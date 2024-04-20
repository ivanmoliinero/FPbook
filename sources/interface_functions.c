#include <stdio.h>
#include <stdlib.h>

#include "estructures.h"
#include "interface_functions.h"

short obtenir_opcio_convertida()
{
    char o[MAX_OPCIO];
    scanf("%s", o); // Obté l'opció escrita com un caràcter.
    return((short)atoi(o)); // Conversió a enter, es guarda en short (màxima longitud de nombre emprada en el programa.)
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