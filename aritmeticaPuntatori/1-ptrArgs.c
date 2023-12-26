#include <stdio.h>
#include <stdlib.h>

// importo i valori di errore
#include "retval.h"

// ========================================================================

/* definisco una struttura per ospitare le informazioni */

typedef struct demo
{
        int eta;
        char* cf;
}dm ;

// ========================================================================

/* prototipi delle funzioni */
int main(int argc, char* argv[]);
int modificaEta(dm* d, int e);
int modificaEtaByAddress(int* de, int e);

// ========================================================================

int main(int argc, char* argv[])
{

        // ----------------------------------------------------------------

        // inzializzo la struttura
        dm* d = (dm*)malloc(sizeof(dm));
        if (d == NULL)
        {
                return memory_error;
        }

        // ----------------------------------------------------------------

        // modifico l'eta' passando un puntatore alla funzione
        if (    modificaEta(d, 27)  < 0 )
        {
                return memory_errorB;
        }

        // ----------------------------------------------------------------

        // modifico l'eta' passando l'indirizzo del parametro alla funzione
        if (      modificaEtaByAddress(&d->eta, 27)  < 0  )
        {
                return memory_errorB;
        }

        // ----------------------------------------------------------------


        // ----------------------------------------------------------------


        return success;
}

// ========================================================================

/**
* Modifica eta'
* @param d struttura di tipo dm
* @param e Nuova eta' da inserire
* @return nuova eta' aggiornata, altrimenti -1
*/
int modificaEta(dm* d, int e)
{

        d->eta = e;

        if (d->eta != e)
        {
                return memory_error;
        }

        return success;
}


// ========================================================================

int modificaEtaByAddress(int* de, int e)
{

        /* questa funzione effettua il doppio referencing (da * ottiene di nuovo * quindi )
        * l'argomento deve essere passato come indirizzo
        */
        *de = e;

        if (*de != e)
        {
                return memory_error;
        }

        return e;
}

// ========================================================================

// ========================================================================