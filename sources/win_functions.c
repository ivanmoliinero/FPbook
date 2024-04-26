#include <gtk/gtk.h>
#include "estructures.h"
#include "win_functions.h"

void setup(finestra_t *win)
{
    win->main = gtk_window_new(GTK_WINDOW_TOPLEVEL); 
    win->titol = gtk_label_new("FPbook"); 
    win->missatge_benvinguda = gtk_label_new("Benvingut/da a FPbook!"); 
    win->perfil = gtk_button_new_with_label("Mostrar perfil"); 
    win->mostrar_amistats = gtk_button_new_with_label("Mostrar amistats");
    win->afegir_amistats = gtk_button_new_with_label("Afegir amistats");
    win->eliminar_amistats = gtk_button_new_with_label("Eliminar amistats");
    win->afegir_usuaris = gtk_button_new_with_label("Mostrar usuaris");

    win->main_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    win->main_third_row_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    win->main_fourth_row_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    gtk_box_pack_start(GTK_BOX(win->main_box), win->titol, TRUE, TRUE, 5);
    gtk_box_pack_start(GTK_BOX(win->main_box), win->missatge_benvinguda, TRUE, TRUE, 2);
    gtk_box_pack_start(GTK_BOX(win->main_third_row_box), win->perfil, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(win->main_third_row_box), win->mostrar_amistats, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(win->main_third_row_box), win->afegir_amistats, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(win->main_fourth_row_box), win->eliminar_amistats, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(win->main_fourth_row_box), win->afegir_usuaris, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(win->main_box), win->main_third_row_box, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(win->main_box), win->main_fourth_row_box, TRUE, TRUE, 0);

    gtk_container_add(GTK_CONTAINER(win->main), win->main_box);

    gtk_widget_show_all(win->main);
}

void main_screen_functionalities(finestra_t *win)
{
    g_signal_connect(win->main, "delete_event", G_CALLBACK (close_window), NULL); // Creu per tancar el programa.
}

void functionalities(finestra_t *win)
{
    main_screen_functionalities(win);
}

void close_window(GtkWidget *wid, gpointer ptr)
{
    gtk_main_quit();
}