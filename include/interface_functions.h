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

#define MAX_USUARIS 10000 // Màxims usuaris que es suportaran al sistema.

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
 * @return short -1 en cas que s'hagi introduït un caràcter no numèric, el nombre introduït per teclat (dins del rang de short) altrament.
*/
extern short obtenir_opcio_convertida();

/**
 * @brief Demana el nombre d'usuaris nous que s'introduiran a la base d'usuaris.
 * @return short Nombre d'usuaris nous.
 * @post 0 < n_nous && n_nous < MAX_USUARIS.
*/
extern short demanar_n_usuaris_nous();

/**
 * @brief Guarda les dades d'un usuari pel teclat en la variable passada per paràmetre.
 * @param (S) usuari Variable de persona_t on es guarden les dades.
*/
extern void afegir_usuari(persona_t *usuari);

/**
 * @brief Demana una data de naixement a un usuari per teclat i l'emmagatzema en la variable usuari passada com a paràmetre.
 * @param usuari (S) Variable persona_t on es guarda la data de naixement.
*/
extern void demanar_data(persona_t *usuari);

/**
 * @brief Serial flush: Llegeix caràcters "brossa" fins haver llegit un salt de línia per no provocar problemes a l'hora de llegir una cadena de caràcters a posteriori.
*/
extern void serial_flush();

#endif