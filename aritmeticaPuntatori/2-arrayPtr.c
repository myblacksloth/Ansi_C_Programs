/* (C) Antonio Maulucci 2023 https://antomau.com */

#include <stdio.h>
#include <stdlib.h>

#include "retval.h"

// ========================================================================

int main(int argc, char* argv[])
{

        /* dichiaro un array */
        int arr[5] = {1,2,3,4,5};

        // ----------------------------------------------------------------

        /* arr[0] = *arr */
        printf("confronto %d con %d\n", *arr, arr[0]);
        printf("confronto %d con %d\n", *arr+1, arr[1]);
        printf("confronto %d con %d\n", *arr+2, arr[2]);
        printf("confronto %d con %d\n", *arr+3, arr[3]);
        printf("confronto %d con %d\n\n", *arr+4, arr[4]);
        /*
        >out:
        confronto 1 con 1
        confronto 2 con 2
        confronto 3 con 3
        confronto 4 con 4
        confronto 5 con 5
        */

        // ----------------------------------------------------------------

        /* puntatore che punta al 3o elemento dell'array */
        int* trd = &arr[2];
        printf("Confronto %d con %d\n\n", *trd, arr[2]);
        /*
        >out:
        Confronto 3 con 3
        */

        printf("Confronto %d con %d\n", *trd-2, arr[0]);
        printf("Confronto %d con %d\n", *trd-1, arr[1]);
        printf("Confronto %d con %d\n", *trd+1, arr[3]);
        printf("Confronto %d con %d\n\n", *trd+2, arr[4]);
        /*
        >out:
        Confronto 1 con 1
        Confronto 2 con 2
        Confronto 4 con 4
        Confronto 5 con 5
        */

        printf("Confronto %d con %d\n", trd[-2], arr[0]);
        printf("Confronto %d con %d\n", trd[-1], arr[1]);
        printf("Confronto %d con %d\n", trd[1], arr[3]);
        printf("Confronto %d con %d\n\n", trd[2], arr[4]);
        /*
        >out:
        Confronto 1 con 1
        Confronto 2 con 2
        Confronto 4 con 4
        Confronto 5 con 5
        */


        // ----------------------------------------------------------------

        /* puntatori al primo e all'ultimo elemento dell'array */
        int* fst = arr; // equivale a int* fst = &arr[0]
        /* per ottenere l'ultimo elemento precisamente si puo' sommare 
        * n elementi * sizeof(elemento)
        * all'indirizzo del primo elemento dell'array
        */
        // int* lst = fst + 4 * sizeof(int); // USARE PER ELEMENTI NON INT
        int * lst = fst + 4;
        printf("primo %d ultimo %d\n\n", *fst, *lst);
        /* >out: primo 1 ultimo 5 */

        // ----------------------------------------------------------------

        return success;
}

// ========================================================================