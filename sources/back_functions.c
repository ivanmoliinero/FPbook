#include <stdio.h>   // Proporciona les funcions necessàries per a l'entrada i sortida estàndard de dades
#include <stdlib.h>  // Proporciona funcions per a la gestió de memòria dinàmica, control de processos i conversions de tipus
#include <stdbool.h> // Proporciona l'estructura de dades booleana

#define COMPATIBILIDAD 3

short obtenir_usuari(char *argv[], short n_elem)
{
    short id = atoi(argv[1]); // Converteix la cadena de caràcters ASCII a un Integer(int)

    if ((id > n_elem - 1) || (id < 0)) // Comprova que no s'hagui introduït un id inexistent
    {
        id = -1;
    }
    return (id); // Retorna el valor passat com a paràmetre en la trucada a l'executable convertit a enter o -1 en cas de no existir l'id
}

bool carregar_amistats(int **amistats)
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
        *amistats = malloc(sizeof(int) * fila_columna * fila_columna); // Reserva memòria pel vector amistats de forma dinàmica

        for (i = 0; i < fila_columna; i++)
        {
            for (j = 0; j < fila_columna; j++)
            {
                fscanf(fitxer, "%d", &(*amistats)[i * fila_columna + j]); // Adreçament a dinàmic a memòria on amistats[fila * NC + columna]
            }
        }
        fclose(fitxer);
    }
    return resultat;
}

bool afegir_amistat(short usuari, short n_usuaris, int **amistats)
{
    bool correcte = true;
    bool error = false;
    short opcio, confirmacio;
    int i, j;
    int fila = usuari * n_usuaris;
    *amistats = malloc(sizeof(int) * n_usuaris * n_usuaris); // Reserva memòria pel vector amistats de forma dinàmica

    for (int i = 0; i < n_usuaris; i++)
    {
        if (((*amistats)[fila + i]) > COMPATIBILIDAD)
        {
            printf("mostrar_perfil();");
        }
    }

    menu_afegir_amistat();

    do
    {
        scanf("%hd", &opcio);
        if (((*amistats)[fila + opcio]) == -1)
        {
            correcte = false; // AÑADIR COMENTARIO INFORMANDO DEL ERROR
        }
        else if (opcio < 0 || opcio > n_usuaris)
        {
            correcte = false; // AÑADIR COMENTARIO INFORMANDO DEL ERROR
        }
        else
        {
            if (((*amistats)[fila + opcio]) < COMPATIBILIDAD)
            {
                // AÑADIR MENSAJE DE ESTAS SEGURO DE QUE QUIERES AÑADIR A ALGUIEN CON POCA COMPATIBILIDAD?
                do
                {
                    scanf("%hd", &confirmacio);
                } while (confirmacio != 0 && confirmacio != 1);

                if (confirmacio == 1)
                {
                    // AÑADIR AMISTAD
                    ((*amistats)[fila + opcio]) = -1;
                    FILE *fitxer = fopen("propers.fpb", "w");

                    if (fitxer == NULL)
                    {
                        error = true;
                    }
                    else
                    {
                        fprintf(fitxer, "%hd", n_usuaris);
                        for (i = 0; i < n_usuaris; i++)
                        {
                            for (j = 0; j < n_usuaris; j++)
                            {
                                fprintf(fitxer, "%d ", ((*amistats)[i * n_usuaris + j]));
                            }
                            fprintf(fitxer, "\n");
                        }
                        fclose(fitxer);
                    }
                }
            }
            else
            {
                // AÑADIR AMISTAD
                ((*amistats)[fila + opcio]) = -1;
                FILE *fitxer = fopen("propers.fpb", "w");

                if (fitxer == NULL)
                {
                    error = true;
                }
                else
                {
                    fprintf(fitxer, "%hd", n_usuaris);
                    for (i = 0; i < n_usuaris; i++)
                    {
                        for (j = 0; j < n_usuaris; j++)
                        {
                            fprintf(fitxer, "%d ", ((*amistats)[i * n_usuaris + j]));
                        }
                        fprintf(fitxer, "\n");
                    }
                    fclose(fitxer);
                }
            }
        }
    } while (!correcte);

    return error;
}