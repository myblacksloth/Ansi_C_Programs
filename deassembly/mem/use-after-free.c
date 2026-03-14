#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct Persona {
    char* nome;
    int eta;
} p;


int main()
{

    char name[] = "antonio";

    // prima allocazione
    p* pers = malloc(sizeof(p));
    if (! pers) return 1;
    // stampo indirizzo del puntatore
    printf("puntatore = %p\n", pers);
    // alloco spazio per il nome che non liberero'
    pers -> nome = (char*)malloc(sizeof(char) * (strlen(name) + 1));
    // copio il nome
    if (! strcpy(pers->nome, name)) return 1;

    // indirizzo della stringa allocata
    printf("indirizzo della stringa allocata = %p\n", pers->nome);

    // salvo il valore del puntatore alla stringa
    char* salvato = pers->nome;

    // adesso libero il solo spazio della struttura
    free(pers);

    // stampo indirizzo del puntatore dopo free
    printf("puntatore dopo free della struct = %p\n", pers);


    // IL VERO USE AFTER FREE SAREBBE
    printf("indirizzo della stringa dopo free della struct = %p\n", pers->nome);


    // provo a leggere il nome dal vecchio puntatore
    // MEMORY LEAK
    // (in realta' e' un memory leak ma comunque mostra che e' possibile accedere a quell'area di memoria)
    //              e' un memory leak perche' non sto accedendo alla stringa sulla quale e' stata effettuata una free
    // printf("%s\n", pers->nome); // questo non va bene perche' avendo deallocato la struct verrebbe fuori un segmentation fault
    printf("LA STRINGA salvata %p E': %s\n", salvato, salvato);
    // l'indirizzo e' lo stesso di pers->nome che non e' mai stato deallocato


    // DIMOSTRO CHE UNA NUOVA ALLOCAZIONE DOPO LA FREE (sulla stessa dimensione) USA LO STESSO INDIRIZZO

    // rialloco lo spazio per la struttura su un nuovo puntatore
    p* newpers = malloc(sizeof(p));
    // stampo indirizzo del nuovo puntatore
    printf("nuovo puntatore = %p\n", newpers);

    if (pers == newpers) {
        printf("LA MEMORIA ALLOCATA E' ESATTAMENTE LA STESSA\n");
    }


    return 0;
}



/*
 * per rilevare errore in fase di esecuzione del codice:
 gcc -O0 -g -fsanitize=address -fno-omit-frame-pointer use-after-free.c
 */
