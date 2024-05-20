#ifndef estructures_h
#define estructures_h // En cas de no estar definit, definir les estructures i constants presents en aquest arxiu de capceleres.

typedef struct
{
    char dia, mes;
    short any;
} data_t;

typedef struct
{
    short id;
    char *nom;
    char *genere;
    char *ciutat;
    data_t data_neix;
} persona_t;

#endif