#ifndef win_functions_h
#define win_functions_h

#include <gtk/gtk.h>
#include <estructures.h>
#include <stdbool.h>

#define MAX_CHAR_DATE 11
#define MAX_DUMMY 100

/**
 * @brief Crea tots els widgets de la finestra principal del programa.
 * @param dades_sis (E/S) Estructura amb TOTES les dades del programa.
*/
extern void setup(info_t *dades_sis);

/**
 * @brief Defineix les diferents funcionalitats dels diferents botons que el programa té per actuar degudament.
 * @param dades_sis (E/S) Estructura amb tota la informació del programa.
*/
extern void functionalities(info_t *dades_sis);

/**
 * @brief Tanca la finestra i finalitza el programa.
 * @param wid (E) Widget que provoca la crida a aquesta funció.
 * @param event (E) Event que fa que la senyal s'executi (automàtic per GTK).
 * @param ptr (E/S) Punter obligatori de funcions handler en cas de retorn de quelcom necessari (no és el cas, però cal posar-lo).
*/
extern void close_window(GtkWidget *wid, GdkEvent *event, gpointer ptr);

/**
 * @brief Defineix les funcionalitats de la pantalla del programa principal.
 * @param dades_sis (E/S) Dades de tot el programa.
*/
extern void main_screen_functionalities(info_t *dades_sis);

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
 * @brief Funció per passar del menú de mostrar perfil a la finestra principal del programa.
 * @param wid (E) Widget que provoca la crida a aquesta funció.
 * @param ptr (E/S) Finestra principal.
*/
extern void mostrar_perfil_to_main_window(GtkWidget *wid, gpointer ptr);

/**
 * @brief Mostra la info del perfil de l'usuari.
 * @param wid (E) Widget que provoca la crida a aquesta funció.
 * @param ptr (E/S) Finestra principal.
*/
extern void mostrar_perfil_activate(GtkWidget *wid, gpointer ptr);

/**
 * @brief Setup del menú mostrar_perfil.
 * @param dades_sis (E/S) Estructura amb totes les dades del sistema.
*/
extern void mostrar_perfil_setup(info_t *dades_sis);

/**
 * @brief Setup del menú afegir_usuaris.
 * @param win (E/S) Finestra principal del programa.
*/
extern void afegir_usuaris_setup(finestra_t *win);

/**
 * @brief Funcionalitats del menú d'afegir usuaris.
 * @param dades_sis (E/S) Dades de TOT el programa.
*/
extern void afegir_usuaris_functionalities(info_t *dades_sis);

/**
 * @brief Mostra la pantalla per afegir usuaris.
*/
extern void afegir_usuaris_activate(GtkWidget *wid, gpointer ptr);

/**
 * @brief Funció per passar de mostrar perfil a la finestra principal del programa.
*/
extern void afegir_usuaris_to_main_window(GtkWidget *wid, gpointer ptr);

/**
 * @brief Afegeix un nou usuari a la base de dades.
 * @pre EL PUNTER PASSAT CORRESPON AL PUNTER QUE APUNTA ON ES TROBEN TOTES LES DADES DEL SISTEMA.
*/
extern void afegir_usuari_entry(GtkWidget *wid, gpointer ptr);

/**
 * @brief Rep la informació d'un usuari de la info introduïda pel terminal.
 * @param dades_sis (E) TOTA la info del sistema.
 * @param temp_usuaris (E/S) Punter que apunta a la taula d'usuaris temporal en el procés de creació d'un nou usuari.
 * @return short n_finals en cas d'execució correcta, -1 en cas d'error.
*/
extern short actualitzacio_usuaris_win(info_t *dades_sis, persona_t **temp_usuaris);

/**
 * @brief Copia una string a una altra sense espais addicionals al darrere (ADAPTAT PER LA VERSIÓ DE FINESTRA, ON L'ÚLTIM CARÀCTER ÉS 0).
 * @param origin (E) String origen.
 * @param dest (S) Punter a l'string destí.
 * @pre Cal que origin tingui el caràcter sentinella '\0'.
 * @return bool True si s'ha pogut completar l'operació i no s'ha passat com a paràmetre original una string buida (o plena d'espais), false altrament.
*/
extern bool string_copy_without_trash_for_win(char origin[], char **dest);

/**
 * @brief Inicia les funcionalitats del menú mostrar amistats.
 * @param dades_sis (E/S) Dades de TOT el programa.
*/
extern void mostrar_amistats_functionalities(info_t *dades_sis);

/**
 * @brief Genera el menú de mostrar amistats i el mostra per pantalla.
 * @param origin Widget que provoca la crida a la funció callback.
 * @param ptr Punter amb la informació necessària pel programa (en aquest cas tota la info del sistema).
*/
extern void generar_mostrar_amistats(GtkWidget *origin, gpointer ptr);

/**
 * @brief Genera alguns dels widgets de mostrar_amistats (els constants).
 * @param win Finestra principal del programa.
*/

#endif