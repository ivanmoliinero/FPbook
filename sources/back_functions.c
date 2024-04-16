#include <stdio.h>   // Proporciona les funcions necessàries per a l'entrada i sortida estàndard de dades
#include <stdlib.h>  // Proporciona funcions per a la gestió de memòria dinàmica, control de processos i conversions de tipus
#include <stdbool.h> // Proporciona l'estructura de dades booleana

short obtenir_usuaris(char *argv[], short n_elem)
{
    short id = atoi(argv[1]); // Converteix la cadena de caràcters ASCII a un Integer(int)

    if ((id > n_elem - 1) || (id < 0)) // Comprova que no s'hagui introduït un id inexistent
    {
        id = -1;
    }
    return (id); // Retorna el valor passat com a paràmetre en la trucada a l'executable convertit a enter o -1 en cas de no existir l'id
}

bool carregar_amistats(int *amistats)
{
    bool resultat = true;
    short i, j, fila_columna;
    FILE *fitxer = fopen("propers.fpb", "r");

    if (fitxer == NULL)
    {
        resultat = false;
    }
    else
    {
        fscanf(fitxer, "%hd", &fila_columna);
        amistats = malloc(sizeof(short) * fila_columna * fila_columna); // Reserva memòria pel vector amistats de forma dinàmica

        for (i = 0; i < fila_columna; i++)
        {
            for (j = 0; j < fila_columna; j++)
            {
                fscanf(fitxer, "%hd", &amistats[i * fila_columna + j]); // Adreçament a dinàmic a memòria on amistats[fila * NC + columna]
            }
        }
        fclose(fitxer);
    }
    return resultat;
}

bool afegir_amistat(short usuari, int *amistats)
{
    bool resultat = false;
}