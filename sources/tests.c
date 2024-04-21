#include <stdio.h>
#include <stdlib.h>

#include "estructures.h"
#include "back_functions.h"
#include "interface_functions.h"

int main()
{
    // PROVA CARREGA USUARIS I AMISTATS
    persona_t *usuaris;
    int *amistats;
    short n_elem = carregar_usuaris(&usuaris);    
    if(!carregar_amistats(&amistats)) printf("ERROR EN CÀRREGA D'AMISTATS\n");

    // PROVA ACTUALITTZACIÓ AMISTATS.
    // ini_llavor();
    // int taula[15] = {0, 1, 0, 1, 2, 0, 1, 2, 3, 0, 1, 2, 3, 4, 0}; // 5 usuarios.
    // int *amistats = taula; // Change of pointer access to test.
    // actualitzacio_amistats(&amistats, 5, 3); // n_elem queda actualitzat per actualització usuaris.
    // for(int i = 0; i < 8; i++)
    // {
    //     for(int j = 0, dir = (i*(i+1))/2; j <= i; j++, dir++) 
    //         printf("%d ", amistats[dir]);
    //     printf("\n");
    // }

    // PROVA AFEGIR USUARIS
    int n_final = afegir_usuaris(&usuaris, &amistats, n_elem);

    // for(int i = 0; i < n_elem; i++)
    // {
    //     printf("ID: %hd\n", usuaris[i].id);
    //     printf("NOM: %s\n", usuaris[i].nom);
    //     printf("GENERE: %s\n", usuaris[i].genere);
    //     printf("CIUTAT: %s\n", usuaris[i].ciutat);
    //     printf("DATA NAIXEMENT: %hd/%hd/%hd\n", (short)usuaris[i].data_neix.dia, (short)usuaris[i].data_neix.mes, (short)usuaris[i].data_neix.any);
    // }

    // PROVA GUARDAT D'USUARIS
    // if(!guardar_usuaris(usuaris, n_elem)) printf("GUARDAT INCORRECTE"); else printf("GUARDAR CORRECTE");

    // PROVA OBTENIR_OPCIO_CONVERTIDA
    // printf("Introdueix un nombre de 4 dígits\n");
    // short opcio = obtenir_opcio_convertida();
    // printf("La vostra opció és %hd", opcio);

    // PROVA GUARDAR AMISTATS
    (guardar_amistats(amistats, n_final)) ? (printf("GUARDAT CORRECTE")) : (printf("GUARDAT INCORRECTE"));    

    return 0;
}