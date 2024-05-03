#ifndef estructures_h
#define estructures_h // En cas de no estar definit, definir les estructures i constants presents en aquest arxiu de capceleres.

#include <gtk/gtk.h> // Capçaleres per l'struct per les dependències gràfiques.
#include <stdbool.h>

typedef struct 
{
    char dia, mes;
    short any;
} data_t;

typedef struct
{
    short id;
    char *nom;
    char *genere;
    char *ciutat;
    data_t data_neix;
} persona_t;

typedef struct
{
    GtkWidget *perfil; // Punter a botó per mostrar perfil.
    GtkWidget *mostrar_amistats; // Punter a botó per mostrar amistats.
    GtkWidget *afegir_amistats; // Punter a botó per afegir amistats.
    GtkWidget *eliminar_amistats; // Punter a botó per eliminar amistats.
    GtkWidget *afegir_usuaris; // Punter a botó per afegir usuaris.
    GtkWidget *titol; // Titol principal del programa.
    GtkWidget *missatge_benvinguda; // Missatge de benvinguda al programa.
    GtkWidget *main_box;
    GtkWidget *main_third_row_box;
    GtkWidget *main_fourth_row_box; // Boxes per guardar de manera ordenada els widgets de la finestra principal.
} main_t;

typedef struct 
{
    GtkWidget *main_label; // Etiqueta principal del menú.
    GtkWidget *name_label; // Etiqueta del nom.
    GtkWidget *genre_label; // Etiqueta del gènere.
    GtkWidget *city_label; // Etiqueta de la ciutat.
    GtkWidget *date_label; // Etiqueta de la data de naixement de l'usuari.
    GtkWidget *back_button; // Botó per tornar al menú principal.
    GtkWidget *main_box; // Main box de mostrar perfil.
} mostrar_perfil_t;

typedef struct 
{
    GtkWidget *main_label; // Afegir usuaris.
    GtkWidget *name_label;
    GtkWidget *genre_label;
    GtkWidget *city_label;
    GtkWidget *date_label;
    GtkWidget *bar_label1;
    GtkWidget *bar_label2; // Per separar dd/mm/aaaa.
    GtkWidget *name_entry;
    GtkWidget *genre_entry;
    GtkWidget *city_entry;
    GtkWidget *day_entry;
    GtkWidget *month_entry;
    GtkWidget *year_entry;
    GtkWidget *confirm_button;
    GtkWidget *go_back_button;
    GtkWidget *main_box;
    GtkWidget *funct_box;
    GtkWidget *labels_box;
    GtkWidget *entry_box;
    GtkWidget *date_box; // Per l'organització en la UI de la data.
} afegir_usuari_t;

typedef struct
{
    GtkWidget *main_label;
    GtkWidget *main_box;
    GtkListStore *friend_list;
    GtkWidget *tree_view; // Per poder mostrar la friends_list.
    GtkCellRenderer *text_renderer; // Per poder mostrar el text.
    GtkWidget *confirm_button; // Per afegir amistats.
    GtkWidget *eliminar_button; // Per eliminar amistats.
    GtkWidget *go_back_button;
    GtkWidget *buttons_box; 
    GtkWidget *scrolled_window; // Per poder lliscar les opcions d'amistats.
    GtkWidget *blank_label; // Label buida per mantenir simetria entre les diferents finestres.
} amistats_t;

typedef struct
{
    GtkWidget *main; // Finestra principal.
    GdkPixbuf *logo; // Logotip de l'aplicació.
    main_t finestra_principal;
    mostrar_perfil_t mostrar_perfil;
    afegir_usuari_t afegir_usuari;
    amistats_t amistats;
} finestra_t;

typedef struct
{
    finestra_t win;
    persona_t *usuaris;
    char *amistats;
    short usuari;
    short n_elem;
    bool usuaris_editats, amistats_editades;
} info_t;

#endif