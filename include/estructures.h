#ifndef estructures_h
#define estructures_h // En cas de no estar definit, definir les estructures i constants presents en aquest arxiu de capceleres.

#include <gtk/gtk.h> // Capçaleres per l'struct per les dependències gràfiques.

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
    GtkWidget *main; // Finestra principal.
    main_t finestra_principal;
    mostrar_perfil_t mostrar_perfil;
} finestra_t;

#endif