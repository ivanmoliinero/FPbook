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