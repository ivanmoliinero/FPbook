#include <stdbool.h>
#include <stdlib.h>

bool cerca_dicotomica(int v, int dades[], int n)
{
    int p_i = 0, p_f = n - 1;
    bool trobat = false;
    
    while ((p_i <= p_f) && !trobat)
    {
        int mig = (p_i + p_f) / 2;
        
        if (dades[mig] == v) trobat = true;
        
        else if (v > dades[mig])
            p_i = mig + 1;
        
        else
            p_f = mig - 1;
    }
    
    return trobat;
}

short obtenir_usuaris(char *argv[], persona_t *usuaris, short n_elem)
{
    bool resultat = false;
    short id = atoi(argv[1])

    if(id > n_elem)
    {
        id = -1;
    }
    else
    {
        // Cerca dicotomica porque tenemos los datos ordendos pero no sabemos con certeca que el id coincide con la posicion de la tabla
        if(!cerca_dicotomica(id, usuaris, n_elem))
        {
            id = -1;
        }

    }
    return (id); // Devolvemos el valor pasado como parametro en la llamada a nuestro ejecutable convertido a entero
}