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
 * @brief Carrega les dades de l'usuari indicat a partir d'un fitxer passat com a paràmetre.
 * @param f (E) Arxiu amb els usuaris.
 * @param usuari (S) Variable de persona on es carrega la info de l'arxiu.
*/
extern void carregar_usuari(FILE *f, persona_t *usuari);

/**
 * @brief Carrega usuaris en una taula passada com a punter.
 * @param t (E/S) Taula on es carreguen les dades dels usuaris.
 * @return short Nombre d'usuaris registrats en el sistema, -1 si no es poden obrir l'arxiu de dades.
*/
extern short carregar_usuaris(persona_t **usuaris);

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
 * @brief Emmagatzema les dades dels usuaris en el fitxer usuaris.fpb.
 * @param t (E) Taula amb tota la informació dels usuaris.
 * @param n_elem (E) Nombre d'usuaris a guardar.
 * @pre n_elem ha de ser major al nombre d'usuaris guardats en el fitxer en el moment de cridar la funció.
 * @return bool True si s'han pogut guardar els usuaris, false altrament.
*/
extern bool guardar_usuaris(persona_t *t, short n_elem);

/**
 * @brief Emmagatzema les dades d'un usuari concret en un fitxer de text passat com a paràmetre.
 * @param f (E/S) Fitxer on es guarda la informació de l'usuari en qüestió.
 * @param usuari (E/S) Variable amb tota la informació de l'usuari.
*/
extern void guardar_usuari(FILE *f, persona_t *usuari);

/**
 * @brief Emmagatzema les dades dels estats de proximitat i amistat entre els usuaris.
 * @param amistats (E) Direcció de memòria de la matriu d'amistats (interpretada com un vector).
 * @param n_elem (E) Nombre de files i columnes de la matriu (nombre d'usuaris del sistema).
*/
extern bool guardar_amistats(int *amistats, short n_elem);

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
extern short afegir_usuaris(persona_t **usuaris, int **amistats, short n_usuaris);

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
extern void actualitzacio_amistats(int **amistats, short n_usuaris, short n_nous);

#endif