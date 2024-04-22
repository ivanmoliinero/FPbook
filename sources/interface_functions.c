#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "estructures.h"
#include "interface_functions.h"
#include "back_functions.h"

short obtenir_opcio_convertida()
{
    char o[MAX_OPCIO];
    scanf("%s", o); // Obté l'opció escrita com un caràcter.
    short res = (short)atoi(o);
    if (res == 0 && (o[0] != '0' || o[1] != 0)) // Si el retorn de l'atoi és 0 però l'usuari no havia introduït el dígit 0:
        res = -1;                               // error, introducció de caràcter.
    return (res);                               // Conversió a enter, es guarda en short (màxima longitud de nombre emprada en el programa.)
}

short demanar_n_usuaris_nous()
{
    short n_nous;
    do
    {
        printf("Quants usuaris nous vols introduir?\n");
        n_nous = obtenir_opcio_convertida();
        if (n_nous <= 0 || n_nous > MAX_USUARIS)
            printf("Introdueix un nombre positiu menor a %hd\n", MAX_USUARIS);

    } while (0 >= n_nous || n_nous >= MAX_USUARIS);

    return (n_nous);
}

void demanar_data(persona_t *usuari) // IMPLEMENTAR CON FUNCION DO - WHILE GENÉRICA ERIC.
{
    short temp;
    bool mes_correcte;
    do
    {
        printf("Introdueix el mes de naixement de l'usuari:\n");
        temp = obtenir_opcio_convertida();
        if (temp < 1 || temp > 12)
            printf("Introdueix un mes valid, entre 1 i 12\n");
    } while (temp < 1 || temp > 12);
    usuari->data_neix.mes = (char)temp;
    do
    {
        printf("Introdueix l'any de naixement de l'usuari:\n");
        temp = obtenir_opcio_convertida();
        if (temp < 0)
            printf("Introdueix un any valid, no negatiu.\n");
    } while (temp < 0);
    usuari->data_neix.any = temp;
    do
    {
        printf("Introdueix el dia de naixement de l'usuari:\n");
        temp = obtenir_opcio_convertida();
        mes_correcte = data_compatible(temp, usuari->data_neix.mes, usuari->data_neix.any);
        if (!mes_correcte)
            printf("Introdueix un dia valid per aquest mes\n");
    } while (!mes_correcte);
    usuari->data_neix.dia = (char)temp;
}

void afegir_usuari(persona_t *usuari) // CAL REAJUSTAR PER OBTENIR OPCIONS CORRECTES EN DATA.
{
    printf("Introdueix el nom del nou usuari:\n");
    fflush(stdin);
    fgets(usuari->nom, MAX_NOM, stdin);
    fflush(stdin);
    printf("Introdueix el genere del nou usuari:\n");
    fgets(usuari->genere, MAX_GENERE, stdin);
    fflush(stdin);
    printf("Introdueix la ciutat del nou usuari:\n");
    fgets(usuari->ciutat, MAX_CIUTAT, stdin);
    demanar_data(usuari);
}

short demanar_opcio(short rang_max, short rang_min)
{
    short opcio;
    do
    {
        opcio = obtenir_opcio_convertida();
        if (opcio < rang_min || opcio > rang_max) printf("Introdueix una opcio entre %hd i %hd\n", rang_min, rang_max); // Missatge d'error.
    } while (opcio < rang_min || opcio > rang_max); // Procura que el valor introduït estigui entre l'interval establert.
    return opcio;
}

void confirmar(short *confirmacio, short afirmacio, short denegacio)
{
    // printf("¿ESTAS SEGURO DE QUE QUIERES AÑADIR A ALGUIEN CON POCA COMPATIBILIDAD? [%hd para denegar y %hd para confirmar]", denegacio, afirmacio);
    do
    {
        scanf("%hd", confirmacio);
    } while (*confirmacio != denegacio && *confirmacio != afirmacio); // Procura que el valor introduït sigui binari(dues opcions posibles).
}

void mostrar_compatibles(int *amistats, int n_usuaris, int usuari)
{
    int valor;
    for (short i = 0; i <= n_usuaris; i++) // Només necessitem iterar fins a la fila 'usuari'.
    {
        if (usuari != i)
        {
            if (i > usuari)
            {
                valor = amistats[(i * (i + 1)) / 2 + usuari]; // Calcular la posición en la matriz triangular
            }
            else
            {
                valor = amistats[(usuari * (usuari + 1)) / 2 + i]; // Si usuari < i, intercambiamos usuari e i para mantener la simetría
            }
            if (valor <= COMPATIBILIDAD && valor > 0)
            {
                printf("%d,%d\n", i, usuari);
                printf("mostrar_perfil()\n");
            }
        }
    }
}

void missatge_benvinguda()
{
    printf("Benvingut/da a FPbook! \n");
}

void missatge_acomiadament()
{
    printf("Fins aviat!");
}

void mostrar_perfil(short usuari, persona_t *usuaris)
{
    // usuaris.nom[o]
    // printf("%s \n", usuaris->nom);
    // printf("%s \n", usuaris->genere);
    // printf("%s \n", usuaris->ciutat);
    printf("ES MOSTRA EL PERFIL %hd\n", usuari);
}

void mostrar_menu_principal()
{
    printf("Que vols fer?: \n\n");
    printf("[1] Mostrar el perfil de l'usuari. \n");
    printf("[2] Mostrar les amistats. \n");
    printf("[3] Afegir una nova amistat. \n");
    printf("[4] Eliminar una amistat. \n");
    printf("[5] Afegir un nou usuari. \n");
    printf("[0] SORTIR\n");
}

void avis_compatibilitat_dolenta()
{
    printf("Estas segur que vols afegir aquest usuari com a amic (no teniu una bona compatibilitat)?\n");
}

void falta_identificador()
{
    printf("No s'ha inclos l'identificador de l'usuari en l'execucio. Si us plau, reinicia el programa inciant sessio correctament\n");
}

void usuari_inexistent()
{
    printf("Aquest usuari no existeix, no s'ha pogut iniciar sessio\n");
}

void error_guardat_dades()
{
    printf("No s'han pogut guardar les dades correctament.\n");
}

void missatge_error_arxiu_amistats()
{
    printf("No s'han pogut obtenir les dades de les amistats i les relacions entre usuaris\n");
}

void missatge_seleccio_amistat()
{
    printf("Escull un usuari per afegir-lo com a amic\n");
}

void missatge_esborrat_amistat()
{
    printf("Escull un usuari per eliminar-lo com a amic\n");
}