/* (C) Antonio Maulucci 2023 https://antomau.com */

#include <stdio.h>
#include <stdlib.h>

#include <limits.h>

#include "retval.h"

#define n_emels 10

// ========================================================================

int main(int argc, char* argv[])
{

        // ----------------------------------------------------------------

        // dichiaro array di interi
        int n[n_emels] = {4,3,2,1,-999 ,7,8,9, 99, 100};

        // ----------------------------------------------------------------

        /* dichiaro un puntatore al primo e uno all'ultimo elemento */
        int* f = n;
        int* l = f + (n_emels-1);

        // ----------------------------------------------------------------

        /* dichiaro un puntatore per lo scorrimento dell'array */
        int *c = f;

        /* dichiaro una variabile per memorizzare il valore minimo */
        int min = INT_MAX;

        // ----------------------------------------------------------------

        /* scorro tutto l'array alla ricerca del minimo
        * ovvero effettuo l'operazione finche' il puntatore cur e' inferiore di last
        */
        while(c < l)
        {

                /* cerco il valore minimo */
                if (*c < min)
                {
                        min = *c;
                }

                /* incremento il contatore cur per puntare all'elemento successivo */
                c++;
        }

        // ----------------------------------------------------------------

        /* stampo il valore minimo */

        printf("valore minimo: %d\n", min);

        // ----------------------------------------------------------------

        return success;
}
