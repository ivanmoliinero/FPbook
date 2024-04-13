#ifndef estructures_h
#define estructures_h // En cas de no estar definit, definir les estructures i constants presents en aquest arxiu de capceleres.

#define MAX_NOM 50
#define MAX_CIUTAT 20 // Valors predeterminats necessaris per poder crear les estructures de dades necessàries.

typedef struct 
{
    char dia, mes, any;
} data_t;

typedef struct
{
    short id;
    char nom[MAX_NOM];
    char ciutat[MAX_CIUTAT];
    data_t data_neix;
} persona_t;

#endif