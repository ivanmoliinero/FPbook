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
        persona_t *usuaris; // Vector amb tota la informació dels usuaris del sistema.
        short n_elem = carregar_usuaris(&usuaris);
        if (n_elem == -1)
            printf("No s'han pogut carregar correctament els usuaris\n");
        else
        {
            short usuari = obtenir_usuari(argv, n_elem);
            if (usuari == -1)
                printf("L'usuari passat com a paràmetre no es troba al sistema\n");
            else
            {
                ini_llavor(); // Per poder generar aleatoris correctament.
                char *amistats; // Matriu amb tota la informació de les amistats i distàncies d'usuaris.
                if (!carregar_amistats(&amistats))
                    printf("No s'han pogut carregar les amistats\n");
                else
                {
                    bool amistats_editades = false, usuaris_editats = false; // REVISAR ON GUARDAR AQUESTES VARIABLES.
                    gtk_init(&argc, &argv); // Passa els paràmetres del main al gtk per poder treballar correctament.
                    finestra_t win; // Struct amb tota la informació de la finestra principal del programa.
                    setup(&win); // Prepara la finestra principal del programa.
                    functionalities(&win);
                    gtk_main(); // Prepara el programa per anar executant les instruccions d'actualització de la finestra.
                }

                
            }
            
        }
        
    }
    return 0;
}