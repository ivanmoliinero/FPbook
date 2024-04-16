#ifndef back_functions_h
#define back_functions_h

#include <stdbool.h> // Proporciona l'estructura de dades booleana

/**
 * @brief Obté l'identificador de l'usuari passat com a paràmetre.
 * @param argv (E) Taula amb paràmetres del main (d'on s'obté l'identificador esperat).
 * @param n_elem (E) Nombre d'elements de la tabla usuaris
 * @return char amb l'id de l'usuari; si existeix --> id; si no existeix --> -1
 */
extern short obtenir_usuari(char *argv[], short n_elem);

/**
 * @brief Carrega les dades de les amistats del sistema en una taula passada com a punter.
 * @param amistats (E/S) Vector amb l'informació de cada amistat. De tipus int (no sabem quin és el màxim nombre de distància).
 * @return booleà amb el resultat de l'operació; tot correcte --> true; error --> false
 */
extern bool carregar_amistats(int *amistats);

/**
 * @brief Afegeix una amistat y actualitza la informació de les amistats d'aquell usuari
 * @param usuari (E) Id de l'usuari
 * @param amistats (E) Vector amb l'informació de cada amistat. De tipus int (no sabem quin és el màxim nombre de distància).
 * @return booleà amb el resultat de l'operació; tot correcte --> true; error --> false
 */
extern bool afegir_amistat(short usuari, int amistats);

/**
 * @brief Carrega usuaris en una taula passada com a punter.
 * @param t (E/S) Taula on es carreguen les dades dels usuaris.
 * @return short Nombre d'usuaris registrats en el sistema.
 */
extern short carregar_usuaris(persona_t *t);

#endif