#ifndef interface_functions_h
#define interface_functions_h

/**
 * @brief Demana a l'usuari introduïr una opció en un rang de valors.
 * @param opcio (E/S) Opció escollida per l'usuari.
 * @param rang_max (E) Valor màxim permès.
 * @param rang_min (E) Valor mínim permès.
 */
extern void demanar_opcio(short *opcio, short rang_max, short rang_min);

/**
 * @brief Demana a l'usuari confirmar si vol acceptar o denegar una acció.
 * @param confirmacio (E/S) Decisio escollida per l'usuari.
 * @param afirmacio (E) Valor que indica afirmació.
 * @param denegacio (E) Valor que indicia denegació.
 */
extern void confirmar(short *confirmacio, short afirmacio, short denegacio);

#endif