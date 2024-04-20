#include <stdio.h>
#include <stdlib.h>

#include "estructures.h"
#include "back_functions.h"
#include "interface_functions.h"

int main()
{
    // PROVA CARREGA USUARIS
    // persona_t *usuaris;
    // short n_elem = carregar_usuaris(&usuaris);
    // realloc(usuaris, sizeof(persona_t)*11);
    // usuaris[10].id = 130;    

    // for(int i = 0; i < n_elem; i++)
    // {
    //     printf("ID: %hd\n", usuaris[i].id);
    //     printf("NOM: %s\n", usuaris[i].nom);
    //     printf("GENERE: %s\n", usuaris[i].genere);
    //     printf("CIUTAT: %s\n", usuaris[i].ciutat);
    //     printf("DATA NAIXEMENT: %hd/%hd/%hd\n", (short)usuaris[i].data_neix.dia, (short)usuaris[i].data_neix.mes, (short)usuaris[i].data_neix.any);
    // }

    // PROVA GUARDAT D'USUARIS
    // if(!guardar_usuaris(usuaris, 11)) printf("GUARDAT INCORRECTE"); else printf("GUARDAR CORRECTE");

    // PROVA OBTENIR_OPCIO_CONVERTIDA
    // printf("Introdueix un nombre de 4 dígits\n");
    // short opcio = obtenir_opcio_convertida();
    // printf("La vostra opció és %hd", opcio);
    
    // PROVA GUARDAR AMISTATS
    // int prova[10] = {0, 1, 0, 1, 2, 0, 1, 2, 3, 0};
    // (guardar_amistats(prova, 4)) ? (printf("GUARDAT INCORRECTE")) : (printf("GUARDAT CORRECTE"));

    return 0;
}