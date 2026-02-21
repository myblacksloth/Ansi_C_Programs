
/*
* (C) Antonio Maulucci 2026
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char* nome;
    int eta;
    struct Node* link;
} n;

n* makeList() {
    // crea dummy head inutile
    // funzione inutilmente critica per campi non inzializzati
    n* x = (n*)malloc(sizeof(n));
    if (!x) {
        return NULL;
    }
    x -> nome = NULL;
    x -> eta = -1;
    x -> link = NULL;
    return x;
}

n* addNode(n* lista, char* name, int eta) {
    n* x = (n*)malloc(sizeof(n));
    if (!x) {
        return lista;
    }
    x -> nome = (char*)malloc(sizeof(char) * (strlen(name) +1));
    if (! x-> nome) {
        free(x);
        return lista;
    }
    if (! strncpy(x->nome, name, strlen(name) +1)) {
        // oppure, per andare sul sicuro
        // oppure memcpy(x->nome, strlen(name) +1);
        // oppure x->nome = strdup(name);
        free(x);
        return lista;
    }
    x->eta = eta;
    x -> link = lista;
    return x;
}

void addCoda(n* lista, char* name, int eta) {
    if (!lista) {
        return;
    }
    n* cur = lista;
    n* prec = NULL;
    while(cur) {
        prec = cur;
        cur = cur -> link;
    }
    n* x = (n*)malloc(sizeof(n));
    if (!x) {
        return;
    }
    x -> nome = (char*)malloc(sizeof(char) * (strlen(name) +1));
    if (! x->nome) {
        free(x);
        return;
    }
    memcpy(x->nome, name, strlen(name) +1);
    x -> eta = eta;
    x -> link = NULL;
    prec -> link = x;
    return;
}

void stampaLista(n* lista) {
    if (!lista) {
        return;
    }
    n* cur = lista;
    while (cur) {
        if (cur -> nome) {
            printf("%s --- %d\n", cur->nome, cur->eta);
        }
        cur = cur -> link;
    }
}

void freeLista(n* lista) {
    if (!lista) {
        return;
    }
    n* cur = lista;
    while (cur) {
        n* prec = cur;
        cur = cur -> link;
        if (prec -> nome)
            free(prec->nome);
        free(prec);
    }
}

int main(int argc, char** argv) {

    #ifdef IS_WINZOZZ
    printf("Running on Winzozz\n");
    #endif

    /* determino archiettura di esecuzione del codice */
    #if defined(__x86_64__) || defined(_M_X64)
        printf("x86_64\n");
    #elif defined(__i386__) || defined(_M_IX86)
        printf("x86 32-bit\n");
    #elif defined(__aarch64__) || defined(_M_ARM64)
        printf("ARM 64-bit\n");
    #elif defined(__arm__) || defined(_M_ARM)
        printf("ARM 32-bit\n");
    #else
        printf("Architettura sconosciuta\n");
        return 1;
    #endif

    /* determino sistema operativo di esecuzione del codice */
     #if defined(_WIN32) || defined(_WIN64)
        /* _WIN32 è definita su tutti i compilatori Windows, sia 32 che 64 bit.
           _WIN64 è definita solo su compilatori Windows a 64 bit. */
        printf("Sistema operativo: Windows\n");
    #elif defined(__APPLE__)
        /* __APPLE__ è definita su tutti i sistemi Apple.
           Per distinguere macOS da iOS si può includere <TargetConditionals.h> */
        printf("Sistema operativo: macOS/iOS\n");
    #elif defined(__linux__)
        /* __linux__ è definita su tutti i sistemi Linux */
        printf("Sistema operativo: Linux\n");
    #elif defined(__FreeBSD__)
        printf("Sistema operativo: FreeBSD\n");
    #else
        printf("Sistema operativo: sconosciuto\n");
    #endif

    n* lista = makeList();
    lista = addNode(lista, "ciaone", 0);
    
    if (!lista) {
        return -1;
    }

    stampaLista(lista);

    freeLista(lista);
    lista = NULL;

    return 0;
}
