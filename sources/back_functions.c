#include <stdio.h>   // Proporciona les funcions necessàries per a l'entrada i sortida estàndard de dades.
#include <stdlib.h>  // Proporciona funcions per a la gestió de memòria dinàmica, control de processos i conversions de tipus.
#include <stdbool.h> // Proporciona l'estructura de dades booleana.

#define COMPATIBILIDAD 3
#define ACCEPTAR 1
#define DENEGAR -1

short obtenir_usuari(char *argv[], short n_elem)
{
    short id = atoi(argv[1]); // Converteix la cadena de caràcters ASCII a un Integer(int).

    if ((id > n_elem - 1) || (id < 0)) // Comprova que no s'hagui introduït un id inexistent.
    {
        id = -1;
    }
    return (id);
}

bool carregar_amistats(int **amistats)
{
    bool resultat = true;
    int dir, n_elem;
    short i, j, fila_columna;
    FILE *fitxer = fopen("propers.fpb", "r"); // Obrim fitxer amb les dades d'amistats.

    if (fitxer == NULL)
    {
        resultat = false;
    }
    else
    {
        fscanf(fitxer, "%hd", &fila_columna); // Guardem el número de d'elements de cada fila/columna equivalent al número d'usuaris al sistema.

        n_elem = (((fila_columna * (fila_columna + 1)) / 2)); // Mètode d'adreçament = ((N * (N + 1)) / 2)
        *amistats = malloc(sizeof(int) * n_elem);             // Assignació dinàmica de memória.

        for (i = 0; i < fila_columna; i++)
        {
            dir = ((i * (i + 1)) / 2);

            for (j = 0; j <= i; j++, dir++)
            {
                fscanf(fitxer, "%d", &(*amistats)[dir]);
            }
        }
        fclose(fitxer);
    }
    return resultat;
}

void mostrar_compatibles(int *amistats, int n_usuaris, int usuari)
{
    int i, valor;

    for (i = 0; i <= usuari; i++) // Només necessitem iterar fins a la fila 'usuari'.
    {
        if (usuari >= i)
        {
            valor = amistats[(usuari * (usuari + 1)) / 2 + i]; // Calcular la posició en la matriu triangular.
        }
        else
        {
            valor = amistats[(i * (i + 1)) / 2 + usuari]; // Si (usuari < i), intercanviem 'usuari' <--> 'i' per a mantenir la simetria.
        }

        if (valor <= COMPATIBILIDAD && valor > 0) // Comprova la compatibilidad y que no siguis ja amic.
        {
            printf("mostrar_perfil()\n");
        }
    }
}

void afegir_amistat(int **amistats, short n_usuaris, short usuari)
{
    int i, j, columna;
    bool correcte = false;
    short opcio, confirmacio;

    mostrar_compatibles(*amistats, n_usuaris, 0);

    while (!correcte)
    {
        demanar_opcio(&opcio, n_usuaris - 1, 0);

        if (opcio == usuari || opcio == -1)
        {
            printf("¡NO TE PUEDES AÑADIR TU MISMO COMO AMIGO!");
        }
        else
        {
            columna = (((opcio * (opcio + 1)) / 2) + usuari); // Calculem l'adreça desitjada per l'usuari.

            if (((*amistats)[columna]) == -1)
            {
                printf("¡YA ES TU AMIGO!");
            }
            else if (((*amistats)[columna]) > COMPATIBILIDAD)
            {
                confirmar(&confirmacio, DENEGAR, ACCEPTAR);

                if (confirmacio == ACCEPTAR)
                {
                    correcte = true;
                    ((*amistats)[columna]) = -1;
                }
            }
            else
            {
                correcte = true;
                ((*amistats)[columna]) = -1;
            }
        }
    }
}