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
 * @brief Inicia les funcionalitats del menú afegir amistats, mostrar amistats i eliminar amistats.
 * @param dades_sis (E/S) Dades de TOT el programa.
*/
extern void amistats_functionalities(info_t *dades_sis);

/**
 * @brief Genera el menú d'afegir amistats i el mostra per pantalla.
 * @param origin Widget que provoca la crida a la funció callback.
 * @param ptr Punter amb la informació necessària pel programa (en aquest cas tota la info del sistema).
*/
extern void generar_afegir_amistats(GtkWidget *origin, gpointer ptr);

/**
 * @brief Genera alguns dels widgets d'afegir_amistats, eliminar amistats i mostrar amistats (els constants).
 * @param win (E/S) Finestra principal del programa.
*/
extern void amistats_setup(finestra_t *win);

/**
 * @brief Canvia de la pantalla d'afegir amistats, eliminar amistats o mostrar al menú principal.
 * @param wid (E) Widget que provoca la crida (en aquest cas l'ignorem):
 * @param ptr Punter enviat des del callback. En aquesta funció, la finestra principal del programa.
*/
extern void amistats_to_main_window(GtkWidget *wid, gpointer ptr);

/**
 * @brief Afegeix l'amistat seleccionada (en cas d'haver-hi alguna opció seleccinada).
 * @param wid (E) Widget que crida a la funció de callback (no s'empra per res en aquesta funció).
 * @param ptr (E/S) Punter amb les dades enviades des del callback. En aquesta funció, tota la informació del sistema.
*/
extern void afegir_amistats_win(GtkWidget *wid, gpointer ptr);

/**
 * @brief Genera el menú per eliminar amistats.
 * @param wid (E) Widget que provoca la trucada a la funció, no s'empra en la funció.
 * @param ptr (E/S) Punter passat des de la crida de la funció handler per callback. En aquesta funció, tota la informació del sistema.
*/
extern void generar_eliminar_amistats(GtkWidget *wid, gpointer ptr);

/**
 * @brief Elimina l'amistat seleccionada (en cas d'haver-hi alguna opció seleccionada).
 * @param wid (E) Widget que provoca la trucada a la funció (no s'empra en aquesta funció).
 * @param ptr (E/S) Punter passat des de la crida de la funció per callback. En aquesta funció, tota la info del sistema.
*/
extern void eliminar_amistats_win(GtkWidget *wid, gpointer ptr);

/**
 * @brief Genera el menú per mostrar amistats.
 * @param wid (E) Widget que provoca la trucada a la funció (no s'empra en aquesta funció).
 * @param ptr (E/S) Punter passat des de la crida de la funció per callback. En aquesta funció, tota la info del sistema.
*/
extern void generar_mostrar_amistats(GtkWidget *wid, gpointer ptr);

/**
 * @brief Inicialitza els estils de la finestra.
 * @param dades_sis (E/S) Informació de tot el programa.
*/
extern void styles_setup(info_t *dades_sis);

/**
 * @brief Defineix les classes de les instàncies del menú principal.
 * @param dades_sis (E/S) Informació de tot el programa.
*/
extern void main_window_styles(info_t *dades_sis);

/**
 * @brief Defineix les classes de les instàncies del menú principal.
 * @param dades_sis (E/S) Informació de tot el programa.
*/
extern void afegir_usuaris_styles(info_t *dades_sis);

/**
 * @brief Assigna les classes corresponents a cadascun dels elements creats en les funcions per generar afegir, mostrar i eliminar amistats.
 * @param dades_sis (E/S) Informació de tot el programa.
 * @pre TOTS ELS WIDGETS NECESSARIS DE LES FINESTRES A GENERAR HAN D'ESTAR CREATS ABANS DE CRIDAR AQUESTA FUNCIÓ.
*/
extern void amistats_styles_dynamic(info_t *dades_sis);

/**
 * @brief Defineix les classes dels widgets/instàncies del menú de mostrar perfil.
 * @param dades_sis (E/S) Informació de tot el programa.
*/
extern void mostrar_perfil_styles(info_t *dades_sis);

#endif