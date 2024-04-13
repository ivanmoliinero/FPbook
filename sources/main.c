#include <stdio.h> // Menús + interacció per terminal.
#include <stdlib.h> 

#include "back_functions.h"
#include "interface_functions.h"
#include "estructures.h"

// Calen definir correctament les capceleres i paràmetres.
int main(int argc, char *argv[])
{
    if(argc != 2) // No s'ha passat com a paràmetre l'identificador de l'usuari.
        falta_identificador();
    else
    {
        char o; // Opció seleccionada per l'usuari.
        // COMANDES PER INICIALITZAR TAULES.
        missatge_benvinguda();
        do
        {
            mostrar_menu_principal();
            o = demanar_opcio();
            switch(o)
            {
                case MOSTRAR_PERFIL_USUARI: mostrar_perfil();
                                            break;
                case MOSTRAR_AMISTATS: mostrar_amistats();
                                       break;
                case AFEGIR_AMISTAT: afegir_amistat();
                                     break;
                case ELIMINAR_AMISTAT: eliminar_amistat();
                                       break;
                case AFEGIR_USUARI: afegir_usuari();
                                    break;
            } // Es podria afegir cas DEFAULT, però com el rang de o està (per funció demanar_opcio) controlat no cal.
        } while (o != 0);
        // Actualització de fitxers SI ESCAL (mirar README.md).
        missatge_acomiadament();
    }

    return 0;
}