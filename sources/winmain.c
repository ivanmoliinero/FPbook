#include <gtk/gtk.h> // Dona error però compilant amb Makefile va bé.
#include "win_functions.h"
#include "estructures.h"

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv); // Passa els paràmetres del main al gtk per poder treballar correctament.
    finestra_t win; // Struct amb tota la informació de la finestra principal del programa.
    setup(&win);
    return 0;
}