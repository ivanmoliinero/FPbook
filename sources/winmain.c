#include <gtk/gtk.h> // Dona error però compilant amb Makefile va bé.
#include "win_functions.h"
#include "estructures.h"
#include "back_functions.h"
#include <stdbool.h>

#include <stdio.h> // De manera temporal.

int main(int argc, char *argv[])
{
    if (argc != 2) // No s'ha passat com a paràmetre l'identificador d'usuari
        printf("No s'ha introduït usuari\n");
    else
    {
        info_t dades_sis; // TOTA LA INFO DEL PROGRAMA.
        dades_sis.n_elem = carregar_usuaris(&(dades_sis.usuaris));
        if (dades_sis.n_elem == -1)
            printf("No s'han pogut carregar correctament els usuaris\n");
        else
        {
            dades_sis.usuari = obtenir_usuari(argv, dades_sis.n_elem);
            if (dades_sis.usuari == -1)
                printf("L'usuari passat com a paràmetre no es troba al sistema\n");
            else
            {
                ini_llavor(); // Per poder generar aleatoris correctament.
                if (!carregar_amistats(&(dades_sis.amistats)))
                    printf("No s'han pogut carregar les amistats\n");
                else
                {
                    dades_sis.amistats_editades = false, dades_sis.usuaris_editats = false;
                    gtk_init(&argc, &argv); // Passa els paràmetres del main al gtk per poder treballar correctament.
                    setup(&dades_sis); // Prepara la finestra principal del programa.
                    functionalities(&dades_sis);
                    gtk_main(); // Prepara el programa per anar executant les instruccions d'actualització de la finestra.
                }
            }
        }
    }
    return 0;
}