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
        persona_t *usuaris; // Punter a taula d'usuaris.
        int *amistats; // Punter a taula d'amistats.
        short n_elem = carregar_usuaris(usuaris); // Nombre d'usuaris registrats al sistema.
        short usuari = obtenir_usuari(argv, usuaris, n_elem); // Id de l'usuari que ha iniciat el programa.
        if(usuari == -1)
        {
            usuari_inexistent();
        }
        else
        {
            carregar_amistats(amistats);
            // TODO: Comprobar que l'identificador és d'un usuari vàlid.
            missatge_benvinguda();
            do
            {
                mostrar_menu_principal();
                o = demanar_opcio();
                switch(o)
                {
                    case MOSTRAR_PERFIL_USUARI: mostrar_perfil(usuari, usuaris);
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
            // TODO: Actualització de fitxers SI ESCAL (mirar README.md).
            missatge_acomiadament();
        }
    }
    return 0;
}