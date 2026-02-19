/*
(C) Antonio Maulucci 2026
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
    n* x = (n*)malloc(sizeof(n));
    return x;
}

n* addNode(n* lista, char* name, int eta) {
    n* x = (n*)malloc(sizeof(n));
    x -> nome = (char*)malloc(sizeof(char) * (strlen(name) +1));
    if (! x-> nome) {
        return lista;
    }
    if (! strncpy(x->nome, name, strlen(name) +1)) {
        return lista;
    }
    x->eta = eta;
    x -> link = lista;
    return x;
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
