#include <stdio.h>
#include <stdlib.h>

#include "estructures.h"
#include "back_functions.h"
#include "interface_functions.h"

int main()
{
    persona_t *usuaris;
    short n_elem = carregar_usuaris(&usuaris);
    for(int i = 0; i < n_elem; i++)
    {
        printf("ID: %hd\n", usuaris[i].id);
        printf("NOM: %s\n", usuaris[i].nom);
        printf("GENERE: %s\n", usuaris[i].genere);
        printf("CIUTAT: %s\n", usuaris[i].ciutat);
        printf("DATA NAIXEMENT: %hd/%hd/%hd\n", (short)usuaris[i].data_neix.dia, (short)usuaris[i].data_neix.mes, (short)usuaris[i].data_neix.any);
    }
    return 0;
}