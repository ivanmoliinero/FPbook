#ifndef back_functions_h
#define back_functions_h
#include <stdbool.h>

#define ACCEPTAR 1
#define DENEGAR -1 // Constants per escollir acció a l'hora d'afegir amistats incompatibles.

// Capceleres de les funcions de càlculs interns.

/**
 * @brief Carrega les dades de l'usuari indicat a partir d'un fitxer passat com a paràmetre.
 * @param f (E) Arxiu amb els usuaris.
 * @param usuari (S) Variable de persona on es carrega la info de l'arxiu.
*/
extern void carregar_usuari(FILE *f, persona_t *usuari);

/**
 * @brief Carrega usuaris en una taula passada com a punter.
 * @param t (E/S) Taula on es carreguen les dades dels usuaris.
 * @return short Nombre d'usuaris registrats en el sistema, -1 en cas d'error.
*/
extern short carregar_usuaris(persona_t **usuaris);

/**
 * @brief Carrega la data de naixement d'un arxiu de text a un usuari.
 * @param f (E) Arxiu d'on s'extreu la informació.
 * @param us (S) Usuari a on es guardarà la data de naixement.
*/
extern void carregar_data(FILE *f, persona_t *us);

/**
 * @brief Emmagatzema les dades dels usuaris en el fitxer passat com a paràmetre.
 * @param t (E) Taula amb tota la informació dels usuaris.
 * @param n_elem (E) Nombre d'usuaris a guardar.
 * @param f (E/S) Arxiu on guardar les dades.
 * @pre n_elem ha de ser major al nombre d'usuaris guardats en el fitxer en el moment de cridar la funció.
*/
extern void guardar_usuaris(persona_t *t, short n_elem, FILE *f);

/**
 * @brief Emmagatzema les dades d'un usuari concret en un fitxer de text passat com a paràmetre.
 * @param f (E/S) Fitxer on es guarda la informació de l'usuari en qüestió.
 * @param usuari (E/S) Variable amb tota la informació de l'usuari.
*/
extern void guardar_usuari(FILE *f, persona_t *usuari);

/**
 * @brief Emmagatzema les dades dels estats de proximitat i amistat entre els usuaris en el fitxer passat com a paràmetre.
 * @param amistats (E) Direcció de memòria de la matriu d'amistats (interpretada com un vector).
 * @param n_elem (E) Nombre de files i columnes de la matriu (nombre d'usuaris del sistema).
 * @param f (E/S) Arxiu on guardar les dades.
*/
extern void guardar_amistats(char *amistats, short n_elem, FILE *f);

/**
 * @brief Comprova si una data és compatible (si un dia no supera els dies màxims d'un mes i si 29/2 és vàlid, és a dir, si l'any és estacionari).
 * @param dia (E) Dia.
 * @param mes (E) Mes.
 * @param any (E) Any.
 * @return bool True si és compatible, fals altrament.
 * @pre 0 < mes <= 12 && 0 <= any (D.C).
*/
extern bool data_compatible(char dia, char mes, short any);

/**
 * @brief Afegeix un nombre d'usuaris especificats per terminal.
 * @param usuaris (E/S) Taula d'usuaris.
 * @param n_usuaris (E) Nombre d'usuaris actuals (abans d'afegir-ne nous).
 * @param amistats (S) Taula d'amistats.
 * @return short Nombre d'usuaris finals.
*/
extern short afegir_usuaris(persona_t **usuaris, char **amistats, short n_usuaris);

/**
 * @brief Actualitza la taula amb tots els usuaris del sistema.
 * @param usuaris (S) Taula amb usuaris del sistema.
 * @param n_usuaris (E) Nombre d'usuaris actuals (abans d'afegir-ne nous).
 * @param n_nous (E) Nombre d'usuaris nous que es volen afegir al sistema.
 * @return short Nombre d'usuaris finals que constaran al sistema.
*/
extern short actualitzacio_usuaris(persona_t **usuaris, short n_usuaris, short n_nous);

/**
 * @brief Inicia la llavor per establir aleatoris.
*/
extern void ini_llavor();

/**
 * @brief Genera un nombre aleatori entre min i max passats per paràmetre.
 * @param min (E) Nombre mínim per generar l'aleatori.
 * @param max (E) Nombre màxim per generar l'aleatori.
 * @return int Nombre aleatori generat.
*/
extern int genera_aleatori(int min, int max);

/**
 * @brief Actualitza la taula d'amistats.
 * @param amistats (S) Taula d'amistats i distàncies entre usuaris.
 * @param n_usuaris (E) Nombre d'usuaris actuals (abans d'afegir-ne nous).
 * @param n_nous (E) Nombre d'usuaris nous que es volen afegir al sistema.
*/
extern void actualitzacio_amistats(char **amistats, short n_usuaris, short n_nous);

/**
 * @brief Obté l'identificador de l'usuari passat com a paràmetre.
 * @param argv (E) Taula amb paràmetres del main (d'on s'obté l'identificador esperat).
 * @param n_elem (E) Nombre d'elements de la tabla usuaris.
 * @return short Identificador de l'usuari; si existeix --> ID; si no existeix --> -1
 */
extern short obtenir_usuari(char *argv[], short n_elem);

/**
 * @brief Carrega les dades de les amistats del sistema en una taula passada com a punter.
 * @param amistats (E/S) Vector amb l'informació de cada amistat.
 * @return bool amb el resultat de l'operació; tot correcte --> true; error --> false
 */
extern bool carregar_amistats(char **amistats);

/**
 * @brief Permet afegir una amistat y actualitza la informació a la taula amistats.
 * @pre Taula d'amistats carregada.
 * @param usuaris (E) Taula d'usuaris del sistema.
 * @param amistats (E/S) Vector amb l'informació de cada amistat.
 * @param n_usuaris (E) Nombre d'usuaris al sistema.
 * @param usuari (E) ID de l'usuari actiu.
 */
extern void afegir_amistat(persona_t *usuaris, char **amistats, short n_usuaris, short usuari);

/**
 * @brief Permet eliminar una amistat y actualitza la informació a la taula amistats.
 * @pre Taula d'amistats carregada.
 * @param amistats (E/S) Vector amb l'informació de cada amistat.
 * @param n_usuaris (E) Nombre d'usuaris al sistema.
 * @param usuari (E) ID de l'usuari actiu.
 */
extern void eliminar_amistat(char **amistats, short n_usuaris, short usuari);

/**
 * @brief Guarda les dades als arxius de manera controlada per tal de no provocar actualitzacions incorrectes.
 * @param usuaris (E) Taula amb dades d'usuaris.
 * @param amistats (E) Taula amb dades d'amistats i distàncies.
 * @param n_elem (E) Nombre d'usuaris a registrar en el sistema (després de realitzar modificacions).
 * @param usuaris_editats (E) Identificador de canvis en la taula d'usuaris.
 * @param amistats_editades (E) Identificador de canvis en la taula d'amistats.
 * @return bool True en cas de guardat de dades correctes, false altrament.
*/
extern bool guardar_dades(persona_t *usuaris, char *amistats, short n_elem, bool usuaris_editats, bool amistats_editades);

/**
 * @brief Allibera la memòria de les taules generades amb malloc.
 * @param usuaris (E) Punter a la taula que s'ha d'alliberar.
 * @param amistats (E) Punter a la taula que s'ha d'alliberar.
*/
extern void alliberacio_memoria(persona_t *usuaris, char *amistats);

/**
 * @brief Copia una string a una altra sense espais addicionals al darrere.
 * @param origin (E) String origen.
 * @param dest (S) Punter a l'string destí.
 * @pre Cal que origin tingui el caràcter sentinella '\n'.
*/
extern void string_copy_without_trash(char origin[], char **dest);

#endif 