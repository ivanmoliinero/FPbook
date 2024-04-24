#ifndef interface_functions_h
#define interface_functions_h

// Constants per la selecció en el menú.
#define MOSTRAR_PERFIL_USUARI 1
#define MOSTRAR_AMISTATS 2
#define AFEGIR_AMISTAT 3
#define ELIMINAR_AMISTAT 4
#define AFEGIR_USUARI 5
#define EXIT 0

#define MAX_OPCIO 4 // Longitud de la dada numèrica màxima que s'espera obtenir per teclat en tot el codi (l'any de naixement de l'usuari).

#define MAX_DUMMY 100 // Constant per guardar dades en taula temporal.

#define MAX_USUARIS 10000 // Màxims usuaris que es suportaran al sistema.

#define COMPATIBILIDAD 3

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
 * @brief Mostra un missatge d'error en cas que no s'hagin pogut guardar les dades als fitxers.
*/
extern void error_guardat_dades();

/**
 * @brief Obté una opció introduïda per l'usuari per teclat i la converteix en un enter (short). Control d'errors d'entrada de dades numèriques.
 * @return short -1 en cas que s'hagi introduït un caràcter no numèric, el nombre introduït per teclat (dins del rang de short) altrament.
*/
extern short obtenir_opcio_convertida();

/**
 * @brief Demana el nombre d'usuaris nous que s'introduiran a la base d'usuaris.
*/
extern void demanar_n_usuaris_nous();

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
 * @brief Demana a l'usuari introduïr una opció en un rang de valors.
 * @param rang_max (E) Valor màxim permès.
 * @param rang_min (E) Valor mínim permès.
 * @return short Opcio escollida.
 */
extern short demanar_opcio(short rang_max, short rang_min);

/**
 * @brief Demana a l'usuari confirmar si vol acceptar o denegar una acció.
 * @param confirmacio (E/S) Decisio escollida per l'usuari.
 * @param afirmacio (E) Valor que indica afirmació.
 * @param denegacio (E) Valor que indicia denegació.
 */
extern void confirmar(short *confirmacio, short afirmacio, short denegacio);

/**
 * @brief Mostra els usuaris compatibles amb un usuari.
 * @pre Taula d'amistats carregada.
 * @param usuaris (E) Taula d'usuaris.
 * @param amistats (E/S) Vector amb l'informació de cada amistat.
 * @param n_usuaris (E) Nombre d'usuaris al sistema.
 * @param usuari (E) ID de l'usuari actiu.
 */
extern void mostrar_compatibles(persona_t *usuaris, char *amistats, int n_usuaris, int usuari);

/**
 * @brief Avisa de compatibilitat dolenta entre usuaris.
*/
extern void avis_compatibilitat_dolenta();

/**
 * @brief Avisa d'errors en la càrrega de dades d'amistats i proximitats d'usuaris.
*/
extern void missatge_error_arxiu_amistats();

/**
 * @brief Informa a l'usuari que ha d'escollir un usuari com a amic.
*/
extern void missatge_seleccio_amistat();

/**
 * @brief Informa a l'usuari que ha d'escollir un usuari per eliminar-lo dels seus amics.
*/
extern void missatge_esborrat_amistat();

/**
 * @brief Mostra la informació d'un usuari per afegir-lo com a amic.
 * @param usuaris (E) Taula d'usuaris del sistema.
 * @param usuari (E) Posició de la taula d'usuaris de l'usuari a mostrar.
*/
extern void mostrar_amistat(persona_t *usuaris, short usuari);

#endif