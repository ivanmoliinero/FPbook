#ifndef back_functions_h
#define back_functions_h

#include <stdbool.h> // Proporciona l'estructura de dades booleana.

/**
 * @brief Obté l'identificador de l'usuari passat com a paràmetre.
 * @param argv (E) Taula amb paràmetres del main (d'on s'obté l'identificador esperat).
 * @param n_elem (E) Nombre d'elements de la tabla usuaris.
 * @return char amb l'identificador de l'usuari; si existeix --> ID; si no existeix --> -1
 */
extern short obtenir_usuari(char *argv[], short n_elem);

/**
 * @brief Carrega les dades de les amistats del sistema en una taula passada com a punter.
 * @param amistats (E/S) Vector amb l'informació de cada amistat.
 * @return bool amb el resultat de l'operació; tot correcte --> true; error --> false
 */
extern bool carregar_amistats(int **amistats);

/**
 * @brief Mostra els usuaris compatibles amb un usuari.
 * @pre Taula d'amistats carregada.
 * @param amistats (E/S) Vector amb l'informació de cada amistat.
 * @param n_usuaris (E) Nombre d'usuaris al sistema.
 * @param usuari (E) ID de l'usuari actiu.
 */
extern void mostrar_compatibles(int *amistats, int n_usuaris, int usuari);

/**
 * @brief Permet afegir una amistat y actualitza la informació a la taula amistats.
 * @pre Taula d'amistats carregada.
 * @param amistats (E/S) Vector amb l'informació de cada amistat.
 * @param n_usuaris (E) Nombre d'usuaris al sistema.
 * @param usuari (E) ID de l'usuari actiu.
 */
extern void afegir_amistat(int **amistats, short n_usuaris, short usuari);

#endif