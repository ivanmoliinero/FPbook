#ifndef back_functions_h
#define back_functions_h
#include <stdbool.h>

// Capceleres de les funcions de càlculs interns.
/**
 * @brief Obté l'identificador de l'usuari passat com a paràmetre.
 * @param argv (E) Taula amb paràmetres del main (d'on s'obté l'identificador esperat).
 * @param n_elem (E) Nombre d'elements de la taula usuaris.
 * @return char Id de l'usuari si existeix, -1 en cas que no existeixi.
*/
extern short obtenir_usuari(char *argv[], short n_elem);

/**
 * @brief Carrega les dades de l'usuari indicat a la taula d'usuaris a partir d'un fitxer passat com a paràmetre.
 * @param f (E) Arxiu amb els usuaris.
 * @param t (S) Taula amb les dades dels usuaris.
 * @param usuari (E) Índex de la taula d'usuaris on es guarda la informació.
*/
extern void carregar_usuari(FILE *f, persona_t *t, short usuari);

/**
 * @brief Carrega usuaris en una taula passada com a punter.
 * @param t (E/S) Taula on es carreguen les dades dels usuaris.
 * @return short Nombre d'usuaris registrats en el sistema, -1 si no es poden obrir l'arxiu de dades.
*/
extern short carregar_usuaris(persona_t *t);

/**
 * @brief Carrega les dades de les amistats del sistema en una taula passada com a punter.
 * @param amistats (E/S) Taula amb les informacions de les amistats. De tipus int (no sabem quin és el màxim nombre de distància).
 * @return char 0 si s'ha pogut carregar, -1 en cas contrari.
*/
extern char carregar_amistats(int *amistats);

/**
 * @brief Carrega la data de naixement d'un arxiu de text a un usuari.
 * @param f (E) Arxiu d'on s'extreu la informació.
 * @param us (S) Usuari a on es guardarà la data de naixement.
*/
extern void carregar_data(FILE *f, persona_t *us);

/**
 * @brief Guarda el dia d'una data passada com a string en format dd/mm/aaaa en el dia de naixement d'un usuari.
 * @param us Usuari en el qual s'emmagatzema la data.
 * @param data String amb la data en el format especificat.
 * @param index (E/S) Índex de recorregut de la taula data.
 * @post index queda actualitzat per començar a llegir el mes directament (posició de la taula del primer dígit del mes).
*/
extern void carregar_dia(persona_t *us, char data[], unsigned char *index);

/**
 * @brief Guarda el mes d'una data passada com a string en format dd/mm/aaaa en el mes de naixement d'un usuari.
 * @param us Usuari en el qual s'emmagatzema la data.
 * @param data String amb la data en el format especificat.
 * @param index (E/S) Índex de recorregut de la taula data.
 * @post index queda actualitzat per començar a llegir l'any directament (posició de la taula del primer dígit de l'any).
*/
extern void carregar_mes(persona_t *us, char data[], unsigned char *index);

/**
 * @brief Guarda l'any d'una data passada com a string en format dd/mm/aaaa en l'any de naixement d'un usuari.
 * @param us Usuari en el qual s'emmagatzema la data.
 * @param data String amb la data en el format especificat.
 * @param index (E/S) Índex de recorregut de la taula data.
*/
extern void carregar_any(persona_t *us, char data[], unsigned char *index);

/**
 * @brief Emmagatzema les dades dels usuaris en el fitxer usuaris.fpb.
 * @param t (E) Taula amb tota la informació dels usuaris.
 * @param n_elem Nombre d'usuaris a guardar.
 * @pre n_elem ha de ser major al nombre d'usuaris guardats en el fitxer en el moment de cridar la funció.
*/
bool guardar_usuaris(persona_t *t, short n_elem);

#endif