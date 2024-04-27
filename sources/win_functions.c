#include <gtk/gtk.h>
#include "estructures.h"
#include "win_functions.h"
#include <stdio.h>

void setup(finestra_t *win, persona_t *usuaris, short usuari)
{
    win->main = gtk_window_new(GTK_WINDOW_TOPLEVEL); 
    main_window_setup(win);
    mostrar_perfil_setup(win, usuaris, usuari);
    show_main_window(win);
}

void main_window_setup(finestra_t *win)
{
    win->finestra_principal.titol = gtk_label_new("FPbook"); 
    win->finestra_principal.missatge_benvinguda = gtk_label_new("Benvingut/da a FPbook!"); 
    win->finestra_principal.perfil = gtk_button_new_with_label("Mostrar perfil"); 
    win->finestra_principal.mostrar_amistats = gtk_button_new_with_label("Mostrar amistats");
    win->finestra_principal.afegir_amistats = gtk_button_new_with_label("Afegir amistats");
    win->finestra_principal.eliminar_amistats = gtk_button_new_with_label("Eliminar amistats");
    win->finestra_principal.afegir_usuaris = gtk_button_new_with_label("Mostrar usuaris");
    win->finestra_principal.main_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    win->finestra_principal.main_third_row_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    win->finestra_principal.main_fourth_row_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    gtk_box_pack_start(GTK_BOX(win->finestra_principal.main_box), win->finestra_principal.titol, TRUE, TRUE, 5);
    gtk_box_pack_start(GTK_BOX(win->finestra_principal.main_box), win->finestra_principal.missatge_benvinguda, TRUE, TRUE, 2);
    gtk_box_pack_start(GTK_BOX(win->finestra_principal.main_third_row_box), win->finestra_principal.perfil, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(win->finestra_principal.main_third_row_box), win->finestra_principal.mostrar_amistats, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(win->finestra_principal.main_third_row_box), win->finestra_principal.afegir_amistats, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(win->finestra_principal.main_fourth_row_box), win->finestra_principal.eliminar_amistats, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(win->finestra_principal.main_fourth_row_box), win->finestra_principal.afegir_usuaris, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(win->finestra_principal.main_box), win->finestra_principal.main_third_row_box, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(win->finestra_principal.main_box), win->finestra_principal.main_fourth_row_box, TRUE, TRUE, 0);
}

void mostrar_perfil_setup(finestra_t *win, persona_t *usuaris, short usuari)
{
    win->mostrar_perfil.main_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    win->mostrar_perfil.main_label = gtk_label_new("El meu perfil");
    win->mostrar_perfil.back_button = gtk_button_new_with_label("<--"); // La resta de widgets no s'inicialitzen ja que depenen de l'usuari.
    win->mostrar_perfil.name_label = gtk_label_new(usuaris[usuari].nom);
    win->mostrar_perfil.genre_label = gtk_label_new(usuaris[usuari].genere);
    char date[MAX_CHAR_DATE];
    sprintf(date, "%hd/%hd/%hd", (short)usuaris[usuari].data_neix.dia, (short)usuaris[usuari].data_neix.mes, (short)usuaris[usuari].data_neix.any);
    win->mostrar_perfil.date_label = gtk_label_new(date);
    gtk_box_pack_end(GTK_BOX(win->mostrar_perfil.main_box), win->mostrar_perfil.back_button, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(win->mostrar_perfil.main_box), win->mostrar_perfil.main_label, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(win->mostrar_perfil.main_box), win->mostrar_perfil.name_label, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(win->mostrar_perfil.main_box), win->mostrar_perfil.genre_label, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(win->mostrar_perfil.main_box), win->mostrar_perfil.date_label, TRUE, TRUE, 0);
}

void mostrar_perfil_activate(GtkWidget *wid, gpointer ptr)
{
    finestra_t *win = ptr;
    win->finestra_principal.main_box = g_object_ref(win->finestra_principal.main_box);
    gtk_container_remove(GTK_CONTAINER(win->main), win->finestra_principal.main_box); 
    gtk_container_add(GTK_CONTAINER(win->main), win->mostrar_perfil.main_box);
    gtk_widget_show_all(win->main);
}

void main_screen_functionalities(finestra_t *win)
{
    g_signal_connect(win->main, "delete_event", G_CALLBACK (close_window), NULL); // Creu per tancar el programa.
    g_signal_connect(win->finestra_principal.perfil, "clicked", G_CALLBACK (mostrar_perfil_activate), (gpointer)win);
}

void functionalities(finestra_t *win)
{
    main_screen_functionalities(win);
    mostrar_perfil_functionalities(win);
}

void close_window(GtkWidget *wid, gpointer ptr)
{
    gtk_main_quit();
}

void show_main_window(finestra_t *win)
{
    gtk_container_add(GTK_CONTAINER(win->main), win->finestra_principal.main_box);
    gtk_widget_show_all(win->main);
}

void callback_show_main_window(GtkWidget *wid, gpointer ptr)
{
    finestra_t *win = ptr; // Es transforma el punter general en un finestra_t *.
    win->mostrar_perfil.main_box = g_object_ref(win->mostrar_perfil.main_box);
    gtk_container_remove(GTK_CONTAINER(win->main), win->mostrar_perfil.main_box);
    gtk_container_add(GTK_CONTAINER(win->main), win->finestra_principal.main_box); // Es torna a ficar dins de main la box amb la info del menú principal.
    gtk_widget_show_all(win->main); // Es torna a mostrar la finestra.
}

void mostrar_perfil_functionalities(finestra_t *win)
{
    g_signal_connect(win->mostrar_perfil.back_button, "clicked", G_CALLBACK (callback_show_main_window), (gpointer)win);
}