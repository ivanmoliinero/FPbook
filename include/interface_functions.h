#ifndef interface_functions_h
#define interface_functions_h

// Constants per la selecció en el menú.
#define MOSTRAR_PERFIL_USUARI 1
#define MOSTRAR_AMISTATS 2
#define AFEGIR_AMISTAT 3
#define ELIMINAR_AMISTAT 4
#define AFEGIR_USUARI 5
#define EXIT 0

#define MAX_OPCIO 6 // Longitud de la dada numèrica màxima que s'espera obtenir per teclat en tot el codi (l'any de naixement de l'usuari) + \n + \0.

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
 * @param usuari (E) Identificador de l'usuari a mostrar.
 * @param usuaris (E) Taula amb la informació dels usuaris.
 */
extern void mostrar_perfil(short usuari, persona_t *usuaris);

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
 * @return bool True si s'ha pogut guardar l'usuari correctament, false altrament.
 */
extern bool afegir_usuari(persona_t *usuari);

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
 * @brief Mostra els usuaris compatibles amb un usuari.
 * @pre Taula d'amistats carregada.
 * @param usuaris (E) Taula d'usuaris.
 * @param amistats (E) Vector amb l'informació de cada amistat.
 * @param n_usuaris (E) Nombre d'usuaris al sistema.
 * @param usuari (E) ID de l'usuari actiu.
 * @return bool True si es tenen usuaris compatibles per afegir, fals en cas contrari.
 */
extern bool mostrar_compatibles(persona_t *usuaris, char *amistats, int n_usuaris, int usuari);

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

/**
 *@brief Informa a l'usuari d'error en la càrrega del fitxer d'usuaris.
 */
extern void missatge_error_arxiu_usuaris();

/**
 * @brief Informa a l'usuari d'error en l'afegiment d'usuaris.
 * @param control (E) Nombre d'usuaris final després d'intentar afegir-los.
 * @return bool True si s'han pogut guardar els usuaris, false altrament.
 * @pre Ha de ser -1 en cas que no s'hagin pogut guardar les dades.
 */
extern bool mirar_errors(short control);

/**
 * @brief Neteja la terminal per una lectura més fàcil del codi.
 */
extern void netejar_terminal();

/**
 * @brief Surt del menu especificat.
 */
extern void sortir_menu();

/**
 * @brief Mostra un missatge avisant que no hi ha usuaris compatibles amb l'usuari que ha iniciat sessió.
 */
extern void sense_compatibles();

/**
 * @brief Mostra les dades de les amistats d'un usuari.
 * @param usuaris (E) Taula d'usuaris.
 * @param usuari (E) ID de l'usuari actiu.
 * @param amistats (E) Vector amb l'informació de cada amistat.
 * @param n_usuaris (E) Nombre d'usuaris al sistema.
 * @return bool True en cas de trobar una amistat, false si no té cap amistat.
 */
extern bool mostrar_amistats(persona_t *usuaris, short usuari, char *amistats, short n_usuaris);

/**
 * @brief Mostra un missatge d'error si l'usuari intenta afegir-se a si mateix com a amic o eliminar-se a si mateix de la llista d'amistats.
 */
extern void missatge_error_un_mateix();

/**
 * @brief Demana a l'usuari confirmació addicional per eliminar una amistat.
 */
extern void missatge_confirmacio_eliminacio_amistat();

/**
 * @brief Informa a l'usuari de la dolenta selecció a l'hora d'intentar afegir una amistat quan ja és amic seu.
 */
extern void missatge_error_ja_amic();

/**
 * @brief Informa a l'usuari de l'intent d'eliminar un usuari del llistat d'amics quan aquest usuari no és amic.
 */
extern void missatge_error_no_amic();

/**
 * @brief Informa a l'usuari de que no té cap amistat.
 */
extern void missatge_error_no_amics();

/**
 * @brief Mostra els mesos de l'any.
 */
extern void mostrar_mesos();

#endif