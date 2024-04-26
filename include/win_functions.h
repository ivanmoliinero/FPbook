#ifndef win_functions_h
#define win_functions_h

#include <gtk/gtk.h>
#include <estructures.h>

/**
 * @brief Crea tots els widgets de la finestra principal del programa.
 * @param win Punter amb tota la informació de la finestra principal del codi.
*/
extern void setup(finestra_t *win);

/**
 * @brief Mostra la finestra passada com a paràmetre.
 * @param win Finestra a mostrar.
*/
extern void show_window(GtkWindow *win);

#endif