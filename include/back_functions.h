#ifndef back_functions_h
#define back_functions_h

// Capceleres de les funcions de càlculs interns.
/**
 * @brief Obté l'identificador de l'usuari passat com a paràmetre.
 * @param argv (E) Taula amb paràmetres del main (d'on s'obté l'identificador esperat).
 * @param usuaris (E) Taula d'usuaris.
 * @param n_elem (E) Nombre d'elements de la taula usuaris.
 * @return char Id de l'usuari si existeix, -1 en cas que no existeixi.
*/
extern short obtenir_usuari(char *argv[], persona_t *usuaris, short n_elem);

/**
 * @brief Carrega les dades de l'usuari indicat a la taula d'usuaris a partir d'un fitxer passat com a paràmetre.
 * @param f Arxiu amb els usuaris.
 * @param t Taula amb les dades dels usuaris.
 * @param usuari Índex de la taula d'usuaris on es guarda la informació.
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
extern char carregar_amistats(int *t);


#endif