/* (C) Antonio Maulucci 2023 https://antomau.com */

#include <stdio.h>
#include <stdlib.h>

#include "retval.h"

#define n_emels 10

// ========================================================================

/* prototipi delle funzioni */
int main(int argc, char* argv[]);
int sumWithPtr(int* res, int* a, int* b);

// ========================================================================

int main(int argc, char* argv[])
{

        // ----------------------------------------------------------------

        // dichiaro gli interi da sommare
        int a=3, b=2;
        // dichairo una variabile per la somma
        int somma1 = 0;

        // effettuo la somma
        sumWithPtr(&somma1, &a, &b);

        // stampo il valore della somma
        printf("somma1 = %d\n", somma1);

        // ----------------------------------------------------------------

        /* dichiaro un puntatore alla funzione che effettua la somma */
        int (*funzioneSomma)(int*, int*, int*) = &sumWithPtr;
        /*
        * dove quindi si hanno:
        * valore di ritorno: int
        * nome del putnatore che punta alla funzione
        * parametri della funzione
        *               la funzione prende come parametri dei puntatori ad interi
        * 
        * assegnamento dell'indirizzo della funzione
        */

        // ----------------------------------------------------------------

        // dichiaro una nuova variabile per effettuare la somma mediante puntatori
        int somma2 = 0;

        // effettuo la somma chiamando la funzione mediante il puntatore
        (*funzioneSomma)(&somma2, &a, &b);

        // stamapo il risultato della sommma
        printf("somma2 = %d\n", somma2);

        // ----------------------------------------------------------------

        /*
        * >out:
        * somma1 = 5
        * somma2 = 5
        */

        return success;
}

// ========================================================================

int sumWithPtr(int* res, int* a, int* b)
{
        int r = 0;

        r = *a + *b;

        *res = r;

        return r;

}