#include <stdio.h>
#include <stdlib.h>

#include "estructures.h"
#include "back_functions.h"
#include "interface_functions.h"

int main()
{
    persona_t *usuaris; // Punter a taula d'usuaris.
    short n_elem = carregar_usuaris(&usuaris); // Nombre d'usuaris registrats al sistema.
    for (int i = 0; i < n_elem; i++)
    {
        printf("ID: %hd\n", usuaris[i].id);
        printf("NOM: %s\n", usuaris[i].nom);
        printf("GÈNERE: %s\n", usuaris[i].genere);
        printf("CIUTAT: %s\n", usuaris[i].ciutat);
        printf("DATA: %d/%d/%d\n", (int)usuaris[i].data_neix.dia, (int)usuaris[i].data_neix.mes, (int)usuaris[i].data_neix.any);
    }
    return 0;
}