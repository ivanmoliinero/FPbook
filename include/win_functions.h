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
 * @brief Defineix les diferents funcionalitats dels diferents botons que el programa té per actuar degudament.
 * @param win Estructura amb tota la informació de la finestra principal del programa.
*/
extern void functionalities(finestra_t *win);

/**
 * @brief Tanca la finestra i finalitza el programa.
 * @param wid Widget que provoca la crida a aquesta funció.
 * @param ptr Punter obligatori de funcions handler en cas de retorn de quelcom necessari (no és el cas, però cal posar-lo).
*/
extern void close_window(GtkWidget *wid, gpointer ptr);

/**
 * @brief Defineix les funcionalitats de la pantalla del programa principal.
 * @param win Estructura amb tota la informació de la finestra principal del programa.
*/
extern void main_screen_functionalities(finestra_t *win);

#endif