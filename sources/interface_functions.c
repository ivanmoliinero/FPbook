void demanar_opcio(short *opcio, short rang_max, short rang_min)
{
    do
    {
        // printf("INTRODUCE EL ID DE TU NUEVO AMIGO [%hd ... %hd]", rang_min, rang_max);
        scanf("%hd", &*opcio);
    } while (*opcio < rang_min || *opcio > rang_max); // Procura que el valor introduït estigui entre l'interval establert.
}

void confirmar(short *confirmacio, short afirmacio, short denegacio)
{
    // printf("¿ESTAS SEGURO DE QUE QUIERES AÑADIR A ALGUIEN CON POCA COMPATIBILIDAD? [%hd para denegar y %hd para confirmar]", denegacio, afirmacio);
    do
    {
        scanf("%hd", &*confirmacio);
    } while (*confirmacio != denegacio && *confirmacio != afirmacio); // Procura que el valor introduït sigui binari(dues opcions posibles).
}