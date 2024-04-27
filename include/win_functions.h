#ifndef win_functions_h
#define win_functions_h

#include <gtk/gtk.h>
#include <estructures.h>

/**
 * @brief Crea tots els widgets de la finestra principal del programa.
 * @param win (S) Punter amb tota la informació de la finestra principal del codi.
*/
extern void setup(finestra_t *win);

/**
 * @brief Defineix les diferents funcionalitats dels diferents botons que el programa té per actuar degudament.
 * @param win (E/S) Estructura amb tota la informació de la finestra principal del programa.
*/
extern void functionalities(finestra_t *win);

/**
 * @brief Tanca la finestra i finalitza el programa.
 * @param wid (E) Widget que provoca la crida a aquesta funció.
 * @param ptr (E/S) Punter obligatori de funcions handler en cas de retorn de quelcom necessari (no és el cas, però cal posar-lo).
*/
extern void close_window(GtkWidget *wid, gpointer ptr);

/**
 * @brief Defineix les funcionalitats de la pantalla del programa principal.
 * @param win (E/S) Estructura amb tota la informació de la finestra principal del programa.
*/
extern void main_screen_functionalities(finestra_t *win);

/**
 * @brief Prepara els widgets del menu principal del programa.
 * @param win (S) Finestra principal del programa.
*/
extern void main_window_setup(finestra_t *win);

/**
 * @brief Inicialitza i mostra la finestra principal del programa.
 * @param win (E) Finestra principal del programa.
*/
extern void show_main_window(finestra_t *win);

/**
 * @brief Defineix les funcionalitats de la pantalla de mostrar perfil.
 * @param win (E) Finestra principal del programa.
*/
extern void mostrar_perfil_functionalities(finestra_t *win);

/**
 * @brief Funció per mostrar la finestra principal amb callbacks.
 * @param wid (E) Widget que provoca la crida a aquesta funció.
 * @param ptr (E/S) Finestra principal.
*/
extern void callback_show_main_window(GtkWidget *wid, gpointer ptr);

/**
 * @brief Mostra la info del perfil de l'usuari.
 * @param wid (E) Widget que provoca la crida a aquesta funció.
 * @param ptr (E/S) Finestra principal.
*/
extern void mostrar_perfil_activate(GtkWidget *wid, gpointer ptr);

/**
 * @brief Setup del menú mostrar_perfil.
 * @param win (E/S) Finestra principal del programa.
*/
extern void mostrar_perfil_setup(finestra_t *win);

#endif