#include <stdio.h>
#include <stdlib.h>

#include "estructures.h"
#include "back_functions.h"
#include "interface_functions.h"

int main()
{
    int amistats[9] = {1, 2, 3,
                      -1, 5, 6,
                       7, 8, 9}; // Vector com a matriu.
    bool fet = guardar_amistats(amistats, 3); // 3 = n_usuaris
    fet ? (printf("GUARDAT")) : (printf("NO GUARDAT"));
    return 0;
}