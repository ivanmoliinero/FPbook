#include <stdio.h>  // Proporciona les funcions necessàries per a l'entrada i sortida estàndard de dades
#include <stdlib.h> // Proporciona funcions per a la gestió de memòria dinàmica, control de processos i conversions de tipus

short obtenir_usuaris(char *argv[], short n_elem)
{
    short id = atoi(argv[1]); // Convertim la cadena de caràcters ASCII a un Integer(int)

    if ((id > n_elem - 1) || (id < 0)) // Comprovem que no s'hagui introduït un id inexistent
    {
        id = -1;
    }
    return (id); // Retornem el valor passat com a paràmetre en la trucada al nostre executable convertit a enter o -1 en cas de no existir l'id
}

extern char carregar_amistats(int *amistats)
{
    short i, j, fila_columna;
    FILE *fitxer = fopen("propers.fpb", "r");
    fscanf(fitxer, "%hd", &fila_columna);
    amistats = malloc(sizeof(short) * fila_columna * fila_columna);

    for (i = 0; i < fila_columna; i++)
    {
        for (j = 0; j < fila_columna; j++)
        {
            fscanf(fitxer, "%hd", &amistats[i * fila_columna + j]);
        }
    }
    fclose(fitxer);
}
