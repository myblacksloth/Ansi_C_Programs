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

int main() {

    char buffer[] = "ciaone\0";
    char *s = NULL;

    s = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
    if (!s) {
        return -1;
    }

    if (!strncpy(s, buffer, strlen(buffer)+1)) {
        return -1;
    };

    free(s);
    s = NULL;

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
