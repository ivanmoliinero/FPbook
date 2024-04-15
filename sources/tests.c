#include <stdio.h>
#include <stdlib.h>

#include "estructures.h"
#include "back_functions.h"
#include "interface_functions.h"

int main()
{
    persona_t *usuaris; // Punter a taula d'usuaris.
    short n_elem = carregar_usuaris(usuaris); // Nombre d'usuaris registrats al sistema.
    printf("%d", n_elem);
    return 0;
}