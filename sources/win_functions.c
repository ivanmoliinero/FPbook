#include <gtk/gtk.h>
#include "estructures.h"

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

    win->grid = gtk_grid_new();
    gtk_grid_attach(GTK_GRID(win->grid), win->titol, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(win->grid), win->missatge_benvinguda, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(win->grid), win->perfil, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(win->grid), win->mostrar_amistats, 1, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(win->grid), win->afegir_amistats, 2, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(win->grid), win->eliminar_amistats, 0, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(win->grid), win->afegir_usuaris, 1, 3, 1, 1);

    gtk_container_add(GIT_CONTAINER(win->main), win->grid);

    gtk_main(); // Prepara el programa per anar executant les instruccions d'actualització de la finestra.

    show_window(win->main);
    return win;
}

void show_window(GtkWindow *win)
{
    gtk_widget_show_all(win);
}