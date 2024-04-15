#ifndef back_functions_h
#define back_functions_h

// Capceleres de les funcions de càlculs interns.
/**
 * @brief Obté l'identificador de l'usuari passat com a paràmetre.
 * @param argv (E) Taula amb paràmetres del main (d'on s'obté l'identificador esperat).
*/
extern short obtenir_usuari(char *argv[]);

/**
 * @brief Carrega usuaris en una taula passada com a punter.
 * @param t (E/S) Taula on es carreguen les dades dels usuaris.
 * @return short Nombre d'usuaris registrats en el sistema.
*/
extern short carregar_usuaris(persona_t *t);

/**
 * @brief Carrega les dades de les amistats del sistema en una taula passada com a punter.
 * @param amistats (E/S) Taula amb les informacions de les amistats. De tipus int (no sabem quin és el màxim nombre de distància).
*/
extern void carregar_amistats(int *t);

#endif