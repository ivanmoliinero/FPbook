#ifndef interface_functions_h
#define interface_functions_h

// Constants per la selecció en el menú.
#define MOSTRAR_PERFIL_USUARI 1
#define MOSTRAR_AMISTATS 2
#define AFEGIR_AMISTAT 3
#define ELIMINAR_AMISTAT 4
#define AFEGIR_USUARI 5
#define LLETRA_INTRODUIDA 0 // atoi retorna 0 si s'introdueixen lletres.
#define EXIT -1

#define MAX_OPCIO 4 // Longitud de la dada numèrica màxima que s'espera obtenir per teclat en tot el codi (l'any de naixement de l'usuari).

// Capceleres de les funcions d'interfície.
/**
 * @brief Mostra un missatge de benvinguda a FPbook.
*/
extern void missatge_benvinguda();

/**
 * @brief Mostra un missatge d'acomiadament de FPbook.
*/
extern void missatge_acomiadament();

/**
 * @brief Mostra el menú principal de FPbook.
*/
extern void mostrar_menu_principal();

/**
 * @brief Mostra missatge informant que no s'ha passat l'identificador com a paràmetre del main.
*/
extern void falta_identificador();

/**
 * @brief Demana un nombre a l'usuari per seleccionar una opció del menú principal.
 * @return char Opció seleccionada per l'usuari.
 * @post o = 0 || o = 1 || o = 2 || o = 3 || o = 4 || o = 5
*/
extern char demanar_opcio();

/**
 * @brief Mostra el perfil de l'usuari passat com a paràmetre.
 * @param id (E) Identificador de l'usuari a mostrar.
 * @param t (E) Taula amb la informació dels usuaris.
*/
extern void mostrar_perfil(short id, persona_t t[]);

/**
 * @brief Mostra un missatge d'error en cas que l'usuari no existeixi.
*/
extern void usuari_inexistent();

/**
 * @brief Mostra un missatge d'error en cas que no s'hagin pogut guardar les dades dels usuaris.
*/
extern void error_guardat_usuaris();

/**
 * @brief Mostra un missatge d'error en cas que no s'hagin pogut guardar les dades de les amistats.
*/
extern void error_guardat_amistats();

/**
 * @brief Obté una opció introduïda per l'usuari per teclat i la converteix en un enter (short). Control d'errors d'entrada de dades numèriques.
*/
extern short obtenir_opcio_convertida();

#endif