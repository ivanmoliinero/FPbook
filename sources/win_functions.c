#include <gtk/gtk.h>
#include "estructures.h"
#include "win_functions.h"
#include <stdio.h>
#include <string.h>
#include "back_functions.h" // Per l'obtencio de dades dels nous usuaris.

#define COMPATIBILIDAD 3

void setup(info_t *dades_sis)
{
    dades_sis->win.main = gtk_window_new(GTK_WINDOW_TOPLEVEL); 
    gtk_window_set_default_size(GTK_WINDOW(dades_sis->win.main), 500, 500); // Tamany.
    gtk_window_set_resizable(GTK_WINDOW(dades_sis->win.main), FALSE);
    gtk_window_set_title(GTK_WINDOW(dades_sis->win.main), "FPbook");
    dades_sis->win.logo = gdk_pixbuf_new_from_file("data/fpbook_logo.png", NULL);
    gtk_window_set_icon(GTK_WINDOW(dades_sis->win.main), GDK_PIXBUF(dades_sis->win.logo)); // Logo
    main_window_setup(&(dades_sis->win));
    mostrar_perfil_setup(dades_sis);
    afegir_usuaris_setup(&(dades_sis->win));
    amistats_setup(&(dades_sis->win));
    styles_setup(dades_sis);
    show_main_window(&(dades_sis->win));
}

void styles_setup(info_t *dades_sis)
{
    GtkCssProvider *provider = gtk_css_provider_new();
    if (!gtk_css_provider_load_from_path(provider, "styles/styles.css", NULL)) printf("ERROR EN LA CÀRREGA DE L'ARXIU CSS\n");
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    main_window_styles(dades_sis);
    mostrar_perfil_styles(dades_sis);
    afegir_usuaris_styles(dades_sis);
}

void mostrar_perfil_styles(info_t *dades_sis)
{
    GtkStyleContext *style_context = gtk_widget_get_style_context(dades_sis->win.mostrar_perfil.main_box);
    gtk_style_context_add_class(style_context, "mostrar_perfil_box");

    // Labels
    gtk_widget_set_name(dades_sis->win.mostrar_perfil.main_label, "main_label");
    
    style_context = gtk_widget_get_style_context(dades_sis->win.mostrar_perfil.name_label);
    gtk_style_context_add_class(style_context, "mostrar_perfil_labels");
    style_context = gtk_widget_get_style_context(dades_sis->win.mostrar_perfil.genre_label);
    gtk_style_context_add_class(style_context, "mostrar_perfil_labels");

    style_context = gtk_widget_get_style_context(dades_sis->win.mostrar_perfil.city_label);
    gtk_style_context_add_class(style_context, "mostrar_perfil_labels");

    style_context = gtk_widget_get_style_context(dades_sis->win.mostrar_perfil.date_label);
    gtk_style_context_add_class(style_context, "mostrar_perfil_labels");

    // Buttons
    style_context = gtk_widget_get_style_context(dades_sis->win.mostrar_perfil.back_button);
    gtk_style_context_add_class(style_context, "mostrar_perfil_buttons");
}

void afegir_usuaris_styles(info_t *dades_sis)
{
    GtkStyleContext *style_context = gtk_widget_get_style_context(dades_sis->win.afegir_usuari.main_box); // Variable per aconseguir els contexts d'estil dels diferents elements.  
    gtk_style_context_add_class(style_context, "afegir_usuaris_box");

    // Labels.
    style_context = gtk_widget_get_style_context(dades_sis->win.afegir_usuari.bar_label1);
    gtk_style_context_add_class(style_context, "afegir_usuaris_labels");
    style_context = gtk_widget_get_style_context(dades_sis->win.afegir_usuari.bar_label2);
    gtk_style_context_add_class(style_context, "afegir_usuaris_labels");
    style_context = gtk_widget_get_style_context(dades_sis->win.afegir_usuari.main_label);
    gtk_style_context_add_class(style_context, "afegir_usuaris_labels");
    style_context = gtk_widget_get_style_context(dades_sis->win.afegir_usuari.name_label);
    gtk_style_context_add_class(style_context, "afegir_usuaris_labels");
    style_context = gtk_widget_get_style_context(dades_sis->win.afegir_usuari.genre_label);
    gtk_style_context_add_class(style_context, "afegir_usuaris_labels");
    style_context = gtk_widget_get_style_context(dades_sis->win.afegir_usuari.city_label);
    gtk_style_context_add_class(style_context, "afegir_usuaris_labels");
    style_context = gtk_widget_get_style_context(dades_sis->win.afegir_usuari.date_label);
    gtk_style_context_add_class(style_context, "afegir_usuaris_labels");

    // Buttons.
    style_context = gtk_widget_get_style_context(dades_sis->win.afegir_usuari.confirm_button);
    gtk_style_context_add_class(style_context, "afegir_usuaris_buttons");
    style_context = gtk_widget_get_style_context(dades_sis->win.afegir_usuari.go_back_button);
    gtk_style_context_add_class(style_context, "afegir_usuaris_buttons");

    // Text entries.
    style_context = gtk_widget_get_style_context(dades_sis->win.afegir_usuari.name_entry);
    gtk_style_context_add_class(style_context, "afegir_usuaris_entries");
    style_context = gtk_widget_get_style_context(dades_sis->win.afegir_usuari.genre_entry);
    gtk_style_context_add_class(style_context, "afegir_usuaris_entries");
    style_context = gtk_widget_get_style_context(dades_sis->win.afegir_usuari.day_entry);
    gtk_style_context_add_class(style_context, "afegir_usuaris_entries");
    style_context = gtk_widget_get_style_context(dades_sis->win.afegir_usuari.month_entry);
    gtk_style_context_add_class(style_context, "afegir_usuaris_entries");
    style_context = gtk_widget_get_style_context(dades_sis->win.afegir_usuari.year_entry);
    gtk_style_context_add_class(style_context, "afegir_usuaris_entries");
    style_context = gtk_widget_get_style_context(dades_sis->win.afegir_usuari.city_entry);
    gtk_style_context_add_class(style_context, "afegir_usuaris_entries");
}

void main_window_styles(info_t *dades_sis)
{
    GtkStyleContext *style_context = gtk_widget_get_style_context(dades_sis->win.finestra_principal.main_box); // Variable per aconseguir els contexts d'estil dels diferents elements.
    gtk_style_context_add_class(style_context, "main_box");

    // Buttons.
    style_context = gtk_widget_get_style_context(dades_sis->win.finestra_principal.perfil);
    gtk_style_context_add_class(style_context, "main_buttons");
    style_context = gtk_widget_get_style_context(dades_sis->win.finestra_principal.afegir_amistats);
    gtk_style_context_add_class(style_context, "main_buttons");
    style_context = gtk_widget_get_style_context(dades_sis->win.finestra_principal.mostrar_amistats);
    gtk_style_context_add_class(style_context, "main_buttons");
    style_context = gtk_widget_get_style_context(dades_sis->win.finestra_principal.eliminar_amistats);
    gtk_style_context_add_class(style_context, "main_buttons");
    style_context = gtk_widget_get_style_context(dades_sis->win.finestra_principal.afegir_usuaris);
    gtk_style_context_add_class(style_context, "main_buttons");

    // Labels.
    style_context = gtk_widget_get_style_context(dades_sis->win.finestra_principal.titol);
    gtk_style_context_add_class(style_context, "main_labels");
    style_context = gtk_widget_get_style_context(dades_sis->win.finestra_principal.missatge_benvinguda);
    gtk_style_context_add_class(style_context, "main_labels");

}

void functionalities(info_t *dades_sis)
{
    main_screen_functionalities(dades_sis);
    mostrar_perfil_functionalities(&(dades_sis->win));
    afegir_usuaris_functionalities(dades_sis);
    amistats_functionalities(dades_sis);
}

void afegir_usuaris_setup(finestra_t *win)
{
    win->afegir_usuari.main_label = gtk_label_new("Afegir usuari");
    win->afegir_usuari.name_label = gtk_label_new("Introdueix el nom del nou usuari: ");
    win->afegir_usuari.genre_label = gtk_label_new("Introdueix el genere del nou usuari:");
    win->afegir_usuari.city_label = gtk_label_new("Introdueix la ciutat del nou usuari:");
    win->afegir_usuari.date_label = gtk_label_new("Introdueix la data de naixement del nou usuari:");
    win->afegir_usuari.bar_label1 = gtk_label_new("/");
    win->afegir_usuari.bar_label2 = gtk_label_new("/");

    win->afegir_usuari.name_entry = gtk_entry_new();
    win->afegir_usuari.genre_entry = gtk_entry_new();
    win->afegir_usuari.city_entry = gtk_entry_new();
    win->afegir_usuari.day_entry = gtk_entry_new();
    win->afegir_usuari.month_entry = gtk_entry_new();
    win->afegir_usuari.year_entry = gtk_entry_new();

    gtk_entry_set_max_length(GTK_ENTRY(win->afegir_usuari.name_entry), MAX_DUMMY);
    gtk_entry_set_max_length(GTK_ENTRY(win->afegir_usuari.genre_entry), MAX_DUMMY);
    gtk_entry_set_max_length(GTK_ENTRY(win->afegir_usuari.city_entry), MAX_DUMMY);
    gtk_entry_set_max_length(GTK_ENTRY(win->afegir_usuari.day_entry), MAX_DUMMY);
    gtk_entry_set_max_length(GTK_ENTRY(win->afegir_usuari.month_entry), MAX_DUMMY);
    gtk_entry_set_max_length(GTK_ENTRY(win->afegir_usuari.year_entry), MAX_DUMMY); // Max length for the reading of data.

    win->afegir_usuari.confirm_button = gtk_button_new_with_label("CONFIRMAR");
    win->afegir_usuari.go_back_button = gtk_button_new_with_label("<--");

    win->afegir_usuari.main_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    win->afegir_usuari.labels_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    win->afegir_usuari.entry_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    win->afegir_usuari.date_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    win->afegir_usuari.funct_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);

    gtk_box_pack_start(GTK_BOX(win->afegir_usuari.labels_box), win->afegir_usuari.name_label, TRUE, TRUE, 10);
    gtk_box_pack_start(GTK_BOX(win->afegir_usuari.labels_box), win->afegir_usuari.genre_label, TRUE, TRUE, 10);
    gtk_box_pack_start(GTK_BOX(win->afegir_usuari.labels_box), win->afegir_usuari.city_label, TRUE, TRUE, 10);
    gtk_box_pack_start(GTK_BOX(win->afegir_usuari.labels_box), win->afegir_usuari.date_label, TRUE, TRUE, 10);
    gtk_box_pack_start(GTK_BOX(win->afegir_usuari.labels_box), win->afegir_usuari.go_back_button, TRUE, TRUE, 10);

    gtk_box_pack_start(GTK_BOX(win->afegir_usuari.date_box), win->afegir_usuari.day_entry, TRUE, TRUE, 5);
    gtk_box_pack_start(GTK_BOX(win->afegir_usuari.date_box), win->afegir_usuari.bar_label1, TRUE, TRUE, 5);
    gtk_box_pack_start(GTK_BOX(win->afegir_usuari.date_box), win->afegir_usuari.month_entry, TRUE, TRUE, 5);
    gtk_box_pack_start(GTK_BOX(win->afegir_usuari.date_box), win->afegir_usuari.bar_label2, TRUE, TRUE, 5);
    gtk_box_pack_start(GTK_BOX(win->afegir_usuari.date_box), win->afegir_usuari.year_entry, TRUE, TRUE, 5);

    gtk_box_pack_end(GTK_BOX(win->afegir_usuari.entry_box), win->afegir_usuari.confirm_button, TRUE, TRUE, 5);
    gtk_box_pack_end(GTK_BOX(win->afegir_usuari.entry_box), win->afegir_usuari.date_box, TRUE, TRUE, 5);
    gtk_box_pack_end(GTK_BOX(win->afegir_usuari.entry_box), win->afegir_usuari.city_entry, TRUE, TRUE, 5);
    gtk_box_pack_end(GTK_BOX(win->afegir_usuari.entry_box), win->afegir_usuari.genre_entry, TRUE, TRUE, 5);
    gtk_box_pack_end(GTK_BOX(win->afegir_usuari.entry_box), win->afegir_usuari.name_entry, TRUE, TRUE, 5);

    gtk_box_pack_start(GTK_BOX(win->afegir_usuari.funct_box), win->afegir_usuari.labels_box, TRUE, TRUE, 5);
    gtk_box_pack_start(GTK_BOX(win->afegir_usuari.funct_box), win->afegir_usuari.entry_box, TRUE, TRUE, 5);

    gtk_box_pack_start(GTK_BOX(win->afegir_usuari.main_box), win->afegir_usuari.main_label, TRUE, TRUE, 10);
    gtk_box_pack_start(GTK_BOX(win->afegir_usuari.main_box), win->afegir_usuari.funct_box, TRUE, TRUE, 10);
}

void main_window_setup(finestra_t *win)
{
    win->finestra_principal.titol = gtk_label_new("FPbook"); 
    win->finestra_principal.missatge_benvinguda = gtk_label_new("Benvingut/da a FPbook!"); 
    win->finestra_principal.perfil = gtk_button_new_with_label("Mostrar perfil"); 
    win->finestra_principal.mostrar_amistats = gtk_button_new_with_label("Mostrar amistats");
    win->finestra_principal.afegir_amistats = gtk_button_new_with_label("Afegir amistats");
    win->finestra_principal.eliminar_amistats = gtk_button_new_with_label("Eliminar amistats");
    win->finestra_principal.afegir_usuaris = gtk_button_new_with_label("Afegir nou usuari");
    win->finestra_principal.main_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    win->finestra_principal.main_third_row_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    win->finestra_principal.main_fourth_row_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    gtk_box_pack_start(GTK_BOX(win->finestra_principal.main_box), win->finestra_principal.titol, FALSE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(win->finestra_principal.main_box), win->finestra_principal.missatge_benvinguda, FALSE, FALSE, 2);
    gtk_box_pack_start(GTK_BOX(win->finestra_principal.main_third_row_box), win->finestra_principal.perfil, TRUE, TRUE, 10);
    gtk_box_pack_start(GTK_BOX(win->finestra_principal.main_third_row_box), win->finestra_principal.mostrar_amistats, TRUE, TRUE, 10);
    gtk_box_pack_start(GTK_BOX(win->finestra_principal.main_third_row_box), win->finestra_principal.afegir_amistats, TRUE, TRUE, 10);
    gtk_box_pack_start(GTK_BOX(win->finestra_principal.main_fourth_row_box), win->finestra_principal.eliminar_amistats, TRUE, TRUE, 10);
    gtk_box_pack_start(GTK_BOX(win->finestra_principal.main_fourth_row_box), win->finestra_principal.afegir_usuaris, TRUE, TRUE, 10);
    gtk_box_pack_start(GTK_BOX(win->finestra_principal.main_box), win->finestra_principal.main_third_row_box, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(win->finestra_principal.main_box), win->finestra_principal.main_fourth_row_box, TRUE, TRUE, 0);
}

void mostrar_perfil_setup(info_t *dades_sis)
{
    dades_sis->win.mostrar_perfil.main_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    dades_sis->win.mostrar_perfil.main_label = gtk_label_new("El meu perfil");
    dades_sis->win.mostrar_perfil.back_button = gtk_button_new_with_label("<--"); 
    dades_sis->win.mostrar_perfil.name_label = gtk_label_new(dades_sis->usuaris[dades_sis->usuari].nom);
    dades_sis->win.mostrar_perfil.genre_label = gtk_label_new(dades_sis->usuaris[dades_sis->usuari].genere);
    dades_sis->win.mostrar_perfil.city_label = gtk_label_new(dades_sis->usuaris[dades_sis->usuari].ciutat);
    char date[MAX_CHAR_DATE];
    sprintf(date, "%hd/%hd/%hd", (short)dades_sis->usuaris[dades_sis->usuari].data_neix.dia, (short)dades_sis->usuaris[dades_sis->usuari].data_neix.mes, (short)dades_sis->usuaris[dades_sis->usuari].data_neix.any);
    dades_sis->win.mostrar_perfil.date_label = gtk_label_new(date);
    gtk_box_pack_end(GTK_BOX(dades_sis->win.mostrar_perfil.main_box), dades_sis->win.mostrar_perfil.back_button, FALSE, FALSE, 10);
    gtk_box_pack_start(GTK_BOX(dades_sis->win.mostrar_perfil.main_box), dades_sis->win.mostrar_perfil.main_label, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(dades_sis->win.mostrar_perfil.main_box), dades_sis->win.mostrar_perfil.name_label, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(dades_sis->win.mostrar_perfil.main_box), dades_sis->win.mostrar_perfil.genre_label, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(dades_sis->win.mostrar_perfil.main_box), dades_sis->win.mostrar_perfil.city_label, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(dades_sis->win.mostrar_perfil.main_box), dades_sis->win.mostrar_perfil.date_label, TRUE, TRUE, 10);
}

void amistats_setup(finestra_t *win)
{
    win->amistats.go_back_button = gtk_button_new_with_label("<--");
    win->amistats.confirm_button = gtk_button_new_with_label("CONFIRMAR");
    win->amistats.eliminar_button = gtk_button_new_with_label("ELIMINAR");
    win->amistats.blank_label = gtk_label_new("");
    
    win->amistats.text_renderer = gtk_cell_renderer_text_new(); // Renderer per poder mostrar text.

    win->amistats.scrolled_window = gtk_scrolled_window_new(NULL, NULL); // Per poder moure la llista d'amistats.
}

void amistats_functionalities(info_t *dades_sis)
{
    g_signal_connect(dades_sis->win.amistats.go_back_button, "clicked", G_CALLBACK(amistats_to_main_window), (gpointer)(&(dades_sis->win)));
    g_signal_connect(dades_sis->win.amistats.confirm_button, "clicked", G_CALLBACK(afegir_amistats_win), (gpointer)dades_sis);
    g_signal_connect(dades_sis->win.amistats.confirm_button, "clicked", G_CALLBACK(amistats_to_main_window), (gpointer)(&(dades_sis->win))); 
    g_signal_connect(dades_sis->win.amistats.eliminar_button, "clicked", G_CALLBACK(amistats_to_main_window), (gpointer)(&(dades_sis->win)));
    g_signal_connect(dades_sis->win.amistats.eliminar_button, "clicked", G_CALLBACK(eliminar_amistats_win), (gpointer)dades_sis); 
}

void eliminar_amistats_win(GtkWidget *wid, gpointer ptr)
{
    info_t *dades_sis = ptr; // Reanomenació del punter passat com a paràmetre per facilitar l'accés a les dades.
    char *opcio; // Dades de l'usuari escollit.
    GtkTreeSelection *sel = gtk_tree_view_get_selection(GTK_TREE_VIEW(dades_sis->win.amistats.tree_view));
    GtkTreeModel *model; // ls amb les dades del tree view.
    GtkTreeIter iter; // fila seleccionada per l'usuari.
    if(gtk_tree_selection_get_selected(sel, &model, &iter)) // Comprovem si l'usuari realment ha seleccionat una amistat.
    {
        gtk_tree_model_get(model, &iter, 0, &opcio, -1);
        short id_sel = atoi(opcio); // Com el primer que es troba en aquesta string és l'id de l'usuari, l'atoi retorna aquest valor enter sense tenir en compte la resta d'informació.
        int columna; // Direcció de l'amistat en la taula d'amistats.
        short usuari = dades_sis->usuari; // Un únic accés a memòria.
        if (id_sel < usuari)
        {
            columna = (((usuari * (usuari + 1)) / 2) + id_sel); // Cerca de fila
        }
        else
        {
            columna = (((id_sel * (id_sel + 1)) / 2) + usuari); // Cerca de columna
        }
        dades_sis->amistats[columna] = (char)genera_aleatori(COMPATIBILIDAD, 9);
        dades_sis->amistats_editades = true; // Identifica l'edició de l'arxiu amistats.
    }
    else
        printf("CAP AMISTAT SELECCIONADA\n");
}

void afegir_amistats_win(GtkWidget *wid, gpointer ptr)
{
    info_t *dades_sis = ptr; // Reanomenació del punter passat com a paràmetre per facilitar l'accés a les dades.
    char *opcio; // Dades de l'usuari escollit.
    GtkTreeSelection *sel = gtk_tree_view_get_selection(GTK_TREE_VIEW(dades_sis->win.amistats.tree_view));
    GtkTreeModel *model; // ls amb les dades del tree view.
    GtkTreeIter iter; // fila seleccionada per l'usuari.
    if(gtk_tree_selection_get_selected(sel, &model, &iter)) // Comprovem si l'usuari realment ha seleccionat una amistat.
    {
        gtk_tree_model_get(model, &iter, 0, &opcio, -1);
        short id_sel = atoi(opcio); // Com el primer que es troba en aquesta string és l'id de l'usuari, l'atoi retorna aquest valor enter sense tenir en compte la resta d'informació.
        int columna; // Direcció de l'amistat en la taula d'amistats.
        short usuari = dades_sis->usuari; // Un únic accés a memòria.
        if (id_sel < usuari)
        {
            columna = (((usuari * (usuari + 1)) / 2) + id_sel); // Cerca de fila
        }
        else
        {
            columna = (((id_sel * (id_sel + 1)) / 2) + usuari); // Cerca de columna
        }
        dades_sis->amistats[columna] = -1;
        dades_sis->amistats_editades = true; // Identifica l'edició de l'arxiu amistats.
    }
    else
        printf("CAP AMISTAT SELECCIONADA\n");
}

void amistats_to_main_window(GtkWidget *wid, gpointer ptr)
{
    finestra_t *win = ptr; // Es transforma el punter general en un finestra_t *.
    win->amistats.main_box = g_object_ref(win->amistats.main_box);
    gtk_container_remove(GTK_CONTAINER(win->main), win->amistats.main_box); 
    show_main_window(win);
}

void mostrar_perfil_activate(GtkWidget *wid, gpointer ptr)
{
    finestra_t *win = ptr;
    win->finestra_principal.main_box = g_object_ref(win->finestra_principal.main_box);
    gtk_container_remove(GTK_CONTAINER(win->main), win->finestra_principal.main_box); 
    gtk_container_add(GTK_CONTAINER(win->main), win->mostrar_perfil.main_box);
    gtk_widget_show_all(win->main);
}

void generar_afegir_amistats(GtkWidget *origin, gpointer ptr)
{
    info_t *dades_sis = ptr; // Reanomenació del punter enviat per facilitar el tractament de les dades.
    dades_sis->win.amistats.friend_list = gtk_list_store_new(1, G_TYPE_STRING); // Es crea la llista amb les dades.
    short n_usuaris = dades_sis->n_elem;
    short id_usuari = dades_sis->usuari; 
    char *amistats = dades_sis->amistats; 
    persona_t *usuaris = dades_sis->usuaris; // Assignació per evitar accesos a memòria constant.
    short index = 0; // Index per anar afegint dades a la taula.
    bool te_compatibilitat = false; // Suposem que no té compatibilitat amb ningú.
    char buffer[115]; /* 100 max per nom, 100 max per genere, 100 max per ciutat, 11 max per data, 4 max per id. Es podria fer amb malloc i strlen, però el cost algorítmic seria
                         massa elevat i caldria controlar errors. */
    int dir = (id_usuari*(id_usuari+1))/2; // Fórmula per accedir a les amistats de l'usuari.
    for(short i = 0; i < n_usuaris; i++)
    {
        if(amistats[dir] > 0 && amistats[dir] <= COMPATIBILIDAD)
        {
            te_compatibilitat = true;
            sprintf(buffer, "%hd\n%s%s%s%hd / %hd / %hd\n", i, usuaris[i].nom, usuaris[i].genere, usuaris[i].ciutat, (short)usuaris[i].data_neix.dia, (short)usuaris[i].data_neix.mes, usuaris[i].data_neix.any);
            gtk_list_store_insert_with_values(dades_sis->win.amistats.friend_list, NULL, index++, 0, buffer, -1);
        }
        if(i < id_usuari) dir++; // Avenç fila a fila.
        else dir += i + 1; // Avenç columna a columna.
    }
    if(!te_compatibilitat)
        printf("NO TENS COMPATIBILITAT AMB CAP USUARI!!!\n");
    else
    {
        finestra_t *win = &(dades_sis->win); // Per evitar diversos accesos a memòria.
        win->amistats.main_label = gtk_label_new("Afegir amistats: ");
        amistats_setup(win);
        amistats_functionalities(dades_sis); // Cal tornar a crear les senyals i objectes de la caixa.
        win->amistats.tree_view = gtk_tree_view_new_with_model(GTK_TREE_MODEL(win->amistats.friend_list));
        gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(win->amistats.tree_view), -1, "Selecciona una amistat:", win->amistats.text_renderer, "text", 0, NULL);
        win->amistats.main_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);

        win->amistats.buttons_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
        gtk_box_pack_start(GTK_BOX(win->amistats.buttons_box), win->amistats.go_back_button, TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(win->amistats.buttons_box), win->amistats.confirm_button, TRUE, TRUE, 0);

        gtk_container_add(GTK_CONTAINER(win->amistats.scrolled_window), win->amistats.tree_view); // Possibilitat d'scroll al tree view.

        gtk_box_pack_start(GTK_BOX(win->amistats.main_box), win->amistats.main_label, FALSE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(win->amistats.main_box), win->amistats.scrolled_window, TRUE, TRUE, 0); // Tree view amb scroll.
        gtk_box_pack_start(GTK_BOX(win->amistats.main_box), win->amistats.buttons_box, FALSE, FALSE, 0);

        win->finestra_principal.main_box = g_object_ref(win->finestra_principal.main_box);
        gtk_container_remove(GTK_CONTAINER(win->main), win->finestra_principal.main_box); 
        gtk_container_add(GTK_CONTAINER(win->main), win->amistats.main_box);

        amistats_styles_dynamic(dades_sis);

        
        gtk_widget_show_all(win->main);
    }
}

void main_screen_functionalities(info_t *dades_sis)
{
    g_signal_connect(dades_sis->win.main, "delete_event", G_CALLBACK (close_window), (gpointer)dades_sis); // Creu per tancar el programa.
    g_signal_connect(dades_sis->win.finestra_principal.perfil, "clicked", G_CALLBACK (mostrar_perfil_activate), (gpointer)(&(dades_sis->win)));
    g_signal_connect(dades_sis->win.finestra_principal.afegir_usuaris, "clicked", G_CALLBACK (afegir_usuaris_activate), (gpointer)(&(dades_sis->win)));
    g_signal_connect(dades_sis->win.finestra_principal.afegir_amistats, "clicked", G_CALLBACK(generar_afegir_amistats), (gpointer)dades_sis);
    g_signal_connect(dades_sis->win.finestra_principal.eliminar_amistats, "clicked", G_CALLBACK(generar_eliminar_amistats), (gpointer)dades_sis);
    g_signal_connect(dades_sis->win.finestra_principal.mostrar_amistats, "clicked", G_CALLBACK(generar_mostrar_amistats), (gpointer)dades_sis);

}

void generar_eliminar_amistats(GtkWidget *wid, gpointer ptr)
{
    info_t *dades_sis = ptr; // Reanomenació del punter enviat per facilitar el tractament de les dades.
    dades_sis->win.amistats.friend_list = gtk_list_store_new(1, G_TYPE_STRING); // Es crea la llista amb les dades.
    short n_usuaris = dades_sis->n_elem;
    short id_usuari = dades_sis->usuari; 
    char *amistats = dades_sis->amistats; 
    persona_t *usuaris = dades_sis->usuaris; // Assignació per evitar accesos a memòria constant.
    short index = 0; // Index per anar afegint dades a la taula.
    bool te_amics = false; // Suposem que no té amics.
    char buffer[115]; /* 100 max per nom, 100 max per genere, 100 max per ciutat, 11 max per data, 4 max per id. Es podria fer amb malloc i strlen, però el cost algorítmic seria
                         massa elevat i caldria controlar errors. */
    int dir = (id_usuari*(id_usuari+1))/2; // Fórmula per accedir a les amistats de l'usuari.
    for(short i = 0; i < n_usuaris; i++)
    {
        if(amistats[dir] == -1)
        {
            te_amics = true;
            sprintf(buffer, "%hd\n%s%s%s%hd / %hd / %hd\n", i, usuaris[i].nom, usuaris[i].genere, usuaris[i].ciutat, (short)usuaris[i].data_neix.dia, (short)usuaris[i].data_neix.mes, usuaris[i].data_neix.any);
            gtk_list_store_insert_with_values(dades_sis->win.amistats.friend_list, NULL, index++, 0, buffer, -1);
        }
        if(i < id_usuari) dir++; // Avenç fila a fila.
        else dir += i + 1; // Avenç columna a columna.
    }
    if(!te_amics)
        printf("NO TENS AMICS!\n");
    else
    {
        finestra_t *win = &(dades_sis->win); // Per evitar diversos accesos a memòria.
        win->amistats.main_label = gtk_label_new("Eliminar amistats: ");
        amistats_setup(win);
        amistats_functionalities(dades_sis); // Cal tornar a crear les senyals i objectes de la caixa.
        win->amistats.tree_view = gtk_tree_view_new_with_model(GTK_TREE_MODEL(win->amistats.friend_list));
        gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(win->amistats.tree_view), -1, "Selecciona una amistat:", win->amistats.text_renderer, "text", 0, NULL);
        win->amistats.main_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);

        win->amistats.buttons_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
        gtk_box_pack_start(GTK_BOX(win->amistats.buttons_box), win->amistats.go_back_button, TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(win->amistats.buttons_box), win->amistats.eliminar_button, TRUE, TRUE, 0);

        gtk_container_add(GTK_CONTAINER(win->amistats.scrolled_window), win->amistats.tree_view); // Possibilitat d'scroll al tree view.

        gtk_box_pack_start(GTK_BOX(win->amistats.main_box), win->amistats.main_label, FALSE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(win->amistats.main_box), win->amistats.scrolled_window, TRUE, TRUE, 0); // Tree view amb scroll.
        gtk_box_pack_start(GTK_BOX(win->amistats.main_box), win->amistats.buttons_box, FALSE, FALSE, 0);

        win->finestra_principal.main_box = g_object_ref(win->finestra_principal.main_box);
        gtk_container_remove(GTK_CONTAINER(win->main), win->finestra_principal.main_box); 
        gtk_container_add(GTK_CONTAINER(win->main), win->amistats.main_box);

        amistats_styles_dynamic(dades_sis);

        gtk_widget_show_all(win->main);
    }
}

void afegir_usuaris_activate(GtkWidget *wid, gpointer ptr)
{
    finestra_t *win = ptr;
    win->finestra_principal.main_box = g_object_ref(win->finestra_principal.main_box);
    gtk_container_remove(GTK_CONTAINER(win->main), win->finestra_principal.main_box); 
    gtk_container_add(GTK_CONTAINER(win->main), win->afegir_usuari.main_box);
    gtk_widget_show_all(win->main);
}

void close_window(GtkWidget *wid, GdkEvent *event, gpointer ptr)
{
    info_t *dades_sis = ptr; // Es fa aquest canvi per poder accedir més fàcilment a les dades.
    if((dades_sis->amistats_editades || dades_sis->usuaris_editats) && !guardar_dades(dades_sis->usuaris, dades_sis->amistats, dades_sis->n_elem, dades_sis->usuaris_editats, dades_sis->amistats_editades))
        printf("Error en el guardat de dades, no s'han pogut guardar correctament\n");
    alliberacio_memoria(dades_sis->usuaris, dades_sis->amistats, dades_sis->n_elem);
    gtk_main_quit();
}

void show_main_window(finestra_t *win)
{
    gtk_container_add(GTK_CONTAINER(win->main), win->finestra_principal.main_box);
    gtk_widget_show_all(win->main);
}

void mostrar_perfil_to_main_window(GtkWidget *wid, gpointer ptr)
{
    finestra_t *win = ptr; // Es transforma el punter general en un finestra_t *.
    win->mostrar_perfil.main_box = g_object_ref(win->mostrar_perfil.main_box);
    gtk_container_remove(GTK_CONTAINER(win->main), win->mostrar_perfil.main_box);
    show_main_window(win);
}

void mostrar_perfil_functionalities(finestra_t *win)
{
    g_signal_connect(win->mostrar_perfil.back_button, "clicked", G_CALLBACK (mostrar_perfil_to_main_window), (gpointer)win);
}

void afegir_usuaris_to_main_window(GtkWidget *wid, gpointer ptr)
{
    info_t *dades_sis = ptr; // Es transforma el punter general en un finestra_t *.
    dades_sis->win.afegir_usuari.main_box = g_object_ref(dades_sis->win.afegir_usuari.main_box);
    gtk_container_remove(GTK_CONTAINER(dades_sis->win.main), dades_sis->win.afegir_usuari.main_box);
    gtk_widget_set_size_request(dades_sis->win.main, 500, 500);

    // gtk_entry_set_text(GTK_ENTRY(dades_sis->win.afegir_usuari.name_entry), "");
    // gtk_entry_set_text(GTK_ENTRY(dades_sis->win.afegir_usuari.genre_entry), "");
    // gtk_entry_set_text(GTK_ENTRY(dades_sis->win.afegir_usuari.city_entry), "");
    // gtk_entry_set_text(GTK_ENTRY(dades_sis->win.afegir_usuari.day_entry), "");
    // gtk_entry_set_text(GTK_ENTRY(dades_sis->win.afegir_usuari.month_entry), "");
    // gtk_entry_set_text(GTK_ENTRY(dades_sis->win.afegir_usuari.year_entry), ""); // Reset del text dins dels entrys.

    show_main_window(&(dades_sis->win));
}

void afegir_usuaris_functionalities(info_t *dades_sis)
{
    finestra_t *win = &(dades_sis->win); // Conversió per evitar problemes entre variables i tipus de dades.
    g_signal_connect(win->afegir_usuari.go_back_button, "clicked", G_CALLBACK (afegir_usuaris_to_main_window), (gpointer)dades_sis);
    g_signal_connect(win->afegir_usuari.confirm_button, "clicked", G_CALLBACK (afegir_usuaris_to_main_window), (gpointer)dades_sis);
    g_signal_connect(win->afegir_usuari.confirm_button, "clicked", G_CALLBACK (afegir_usuari_entry), (gpointer)dades_sis);
}

void afegir_usuari_entry(GtkWidget *wid, gpointer ptr)
{
    info_t *dades_sis = ptr; // Reanomenació del punter per tractar les dades fàcilment.

    persona_t *temp_usuaris = dades_sis->usuaris;
    char *temp_amistats = dades_sis->amistats; // Taules temporals per controlar els realloc.
    
    short n_final = actualitzacio_usuaris_win(dades_sis, &temp_usuaris);
    if(n_final != -1)
    {
        if(!actualitzacio_amistats(&temp_amistats, dades_sis->n_elem, 1)) // Només afegim 1 ÚNIC USUARI NOU.
        {
            if (temp_usuaris != NULL)
                dades_sis->usuaris = realloc(temp_usuaris, sizeof(persona_t)*dades_sis->n_elem); 
            if (temp_amistats != NULL)
                dades_sis->amistats = realloc(temp_amistats, sizeof(char)*dades_sis->n_elem); // Es torna a col·locar la memòria al seu lloc.
            printf("NO S'HA POGUT COMPLETAR L'OPERACIÓ CORRECTAMENT!\n");
        }
        else // S'ha executat correctament.
        {
            dades_sis->amistats_editades = true; dades_sis->usuaris_editats = true; // S'han editat satisfactòriament les taules.
            dades_sis->usuaris = temp_usuaris;
            dades_sis->amistats = temp_amistats; // Col·locació d'adreces amb tota la info carregada als paràmetres.
            dades_sis->n_elem = n_final; // == (dades_sis->n_elem)++; - només afegim un únic usuari.
        }
    }
    else
    {
        if (temp_usuaris != NULL)
            dades_sis->usuaris = realloc(temp_usuaris, sizeof(persona_t)*dades_sis->n_elem); // Es torna a col·locar la memòria al seu lloc.
        printf("NO S'HA POGUT COMPLETAR L'OPERACIÓ CORRECTAMENT!\n");
    }
}

short actualitzacio_usuaris_win(info_t *dades_sis, persona_t **temp_usuaris)
{
    short n_finals = dades_sis->n_elem + 1; // Valor incial.
    short id_nou = n_finals - 1;
    *temp_usuaris = realloc(*temp_usuaris, sizeof(persona_t)*n_finals); // Ampliació del vector d'usuaris.
    if(*temp_usuaris != NULL)
    {
        short temp_any;
        char *dummy, temp_dia, temp_mes;
        bool comprova_cadena;

        temp_any = (short)atoi(gtk_entry_get_text(GTK_ENTRY(dades_sis->win.afegir_usuari.year_entry)));
        if (temp_any < 0 || temp_any > 2024) 
            n_finals = -1; // Es podria agafar l'any actual amb time.h.
        else
        {
            temp_mes = (char)atoi(gtk_entry_get_text(GTK_ENTRY(dades_sis->win.afegir_usuari.month_entry)));
            if(temp_mes <= 0 || temp_mes > 12) 
                n_finals = -1;
            else
            {
                temp_dia = (char)atoi(gtk_entry_get_text(GTK_ENTRY(dades_sis->win.afegir_usuari.day_entry)));
                if(!data_compatible(temp_dia, temp_mes, temp_any)) 
                    n_finals = -1;
                else
                {
                    dummy = (char *)gtk_entry_get_text(GTK_ENTRY(dades_sis->win.afegir_usuari.name_entry));
                    comprova_cadena = nomes_carace
                    if (!string_copy_without_trash_for_win(dummy, &((*temp_usuaris)[id_nou].nom))) 
                        n_finals = -1;
                    else
                    {
                        dummy = (char *)gtk_entry_get_text(GTK_ENTRY(dades_sis->win.afegir_usuari.genre_entry));
                        if (!string_copy_without_trash_for_win(dummy, &((*temp_usuaris)[id_nou].genere))) 
                            n_finals = -1;
                        else
                        {
                            dummy = (char *)gtk_entry_get_text(GTK_ENTRY(dades_sis->win.afegir_usuari.city_entry));
                            if (!string_copy_without_trash_for_win(dummy, &((*temp_usuaris)[id_nou].ciutat))) 
                                n_finals = -1;
                            else
                            {
                                (*temp_usuaris)[id_nou].data_neix.dia = temp_dia;
                                (*temp_usuaris)[id_nou].data_neix.mes = temp_mes;
                                (*temp_usuaris)[id_nou].data_neix.any = temp_any;

                                (*temp_usuaris)[id_nou].id = id_nou;
                            }
                        }
                    }
                }
            }
        }
    }
    else n_finals = -1;
    return n_finals;
}
    
bool string_copy_without_trash_for_win(char origin[], char **dest)
{
    bool correcte = true;
    if(origin[0] == ' ')
        correcte = false;
    else
    {
        short last_index = -1, i; // -1, si no es modifica siginifica que només hi ha espais.
        for (i = 0; origin[i] != '\0'; i++)
            if(origin[i] != ' ') 
                last_index = i;
        if(last_index == -1) 
        {
            correcte = false; // La string original NOMÉS TÉ ESPAIS.
        }
        else
        {
            last_index++;
            origin[last_index] = 0;
            char new_lenght = strlen(origin); // length fins el caràcter sentinella \0.
            new_lenght+=2; // Pel caràcter \n.
            *dest = (char *)malloc(sizeof(char)*new_lenght);
            if(*dest == NULL)
                correcte = false;
            else
            {
                strcpy(*dest, origin);
                /* Les següents modificacions poden ser estudiades per veure si realment calen, però per evitar problemes de format
                i de heap s'inclouen */
                (*dest)[new_lenght-2] = '\n'; // Caràcter necessari per fer correctament els printf.
                (*dest)[new_lenght-1] = '\0'; // Caràcter per indicar fi sentinella.
            }
        }
    }
    return correcte;
}

void generar_mostrar_amistats(GtkWidget *wid, gpointer ptr)
{
    info_t *dades_sis = ptr; // Reanomenació del punter enviat per facilitar el tractament de les dades.
    dades_sis->win.amistats.friend_list = gtk_list_store_new(1, G_TYPE_STRING); // Es crea la llista amb les dades.
    short n_usuaris = dades_sis->n_elem;
    short id_usuari = dades_sis->usuari; 
    char *amistats = dades_sis->amistats; 
    persona_t *usuaris = dades_sis->usuaris; // Assignació per evitar accesos a memòria constant.
    short index = 0; // Index per anar afegint dades a la taula.
    bool te_amics = false; // Suposem que no té amics.
    char buffer[115]; /* 100 max per nom, 100 max per genere, 100 max per ciutat, 11 max per data, 4 max per id. Es podria fer amb malloc i strlen, però el cost algorítmic seria
                         massa elevat i caldria controlar errors. */
    int dir = (id_usuari*(id_usuari+1))/2; // Fórmula per accedir a les amistats de l'usuari.
    for(short i = 0; i < n_usuaris; i++)
    {
        if(amistats[dir] == -1)
        {
            te_amics = true;
            sprintf(buffer, "%hd\n%s%s%s%hd / %hd / %hd\n", i, usuaris[i].nom, usuaris[i].genere, usuaris[i].ciutat, (short)usuaris[i].data_neix.dia, (short)usuaris[i].data_neix.mes, usuaris[i].data_neix.any);
            gtk_list_store_insert_with_values(dades_sis->win.amistats.friend_list, NULL, index++, 0, buffer, -1);
        }
        if(i < id_usuari) dir++; // Avenç fila a fila.
        else dir += i + 1; // Avenç columna a columna.
    }
    if(!te_amics)
        printf("NO TENS AMICS!\n");
    else
    {
        finestra_t *win = &(dades_sis->win); // Per evitar diversos accesos a memòria.
        win->amistats.main_label = gtk_label_new("Les meves amistats: ");
        amistats_setup(win);
        amistats_functionalities(dades_sis); // Cal tornar a crear les senyals i objectes de la caixa.
        win->amistats.tree_view = gtk_tree_view_new_with_model(GTK_TREE_MODEL(win->amistats.friend_list));
        gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(win->amistats.tree_view), -1, NULL, win->amistats.text_renderer, "text", 0, NULL);
        win->amistats.main_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);

        win->amistats.buttons_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
        gtk_box_pack_start(GTK_BOX(win->amistats.buttons_box), win->amistats.go_back_button, TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(win->amistats.buttons_box), win->amistats.blank_label, TRUE, TRUE, 0);

        gtk_container_add(GTK_CONTAINER(win->amistats.scrolled_window), win->amistats.tree_view); // Possibilitat d'scroll al tree view.

        gtk_box_pack_start(GTK_BOX(win->amistats.main_box), win->amistats.main_label, FALSE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(win->amistats.main_box), win->amistats.scrolled_window, TRUE, TRUE, 0); // Tree view amb scroll.
        gtk_box_pack_start(GTK_BOX(win->amistats.main_box), win->amistats.buttons_box, FALSE, FALSE, 0);

        win->finestra_principal.main_box = g_object_ref(win->finestra_principal.main_box);
        gtk_container_remove(GTK_CONTAINER(win->main), win->finestra_principal.main_box); 
        gtk_container_add(GTK_CONTAINER(win->main), win->amistats.main_box);

        amistats_styles_dynamic(dades_sis);

        gtk_widget_show_all(win->main);
    }
}

void amistats_styles_dynamic(info_t *dades_sis)
{
    GtkStyleContext *style_context = gtk_widget_get_style_context(dades_sis->win.amistats.main_box);
    gtk_style_context_add_class(style_context, "amistats_box"); // Main box.

    style_context = gtk_widget_get_style_context(dades_sis->win.amistats.main_label);
    gtk_style_context_add_class(style_context, "amistats_labels"); // Main label.
    style_context = gtk_widget_get_style_context(dades_sis->win.amistats.tree_view);
    gtk_style_context_add_class(style_context, "amistats_tree_view"); // Tree view.
    style_context = gtk_widget_get_style_context(dades_sis->win.amistats.scrolled_window);
    gtk_style_context_add_class(style_context, "amistats_scrolled_window"); // Finestra amb scroll.

    // Buttons.
    style_context = gtk_widget_get_style_context(dades_sis->win.amistats.go_back_button);
    gtk_style_context_add_class(style_context, "amistats_buttons");
    style_context = gtk_widget_get_style_context(dades_sis->win.amistats.confirm_button);
    gtk_style_context_add_class(style_context, "amistats_buttons");
    style_context = gtk_widget_get_style_context(dades_sis->win.amistats.eliminar_button);
    gtk_style_context_add_class(style_context, "amistats_buttons");
}