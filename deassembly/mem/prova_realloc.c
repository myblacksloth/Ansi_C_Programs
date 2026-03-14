#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dati {
    char* data;
    size_t size;
} d;

int main()
{
    size_t len = 4;
    char s[] = "ciao";
    s[len] = '\0';

    d*  miei = (d*)malloc(sizeof(d));
    if (!miei) return 1;
    miei->data = (char*)malloc(sizeof(char) * (strlen(s) + 1));
    if (!miei->data) return 1;
    miei->size = strlen(s);

    printf("dimensione allocata %p: %lu\n", miei->data, sizeof(miei->data));

    // in realta' realloc restituisce void*
    char* newdata = realloc(miei->data, sizeof(char) * (strlen(s) * 2 + 1));
    if (!newdata) return 1;
    printf("dimensione nuova variabile allocata %p: %lu\n", newdata, sizeof(newdata));
    printf("dimensione allocata %p: %lu\n", miei->data, sizeof(miei->data));
    if (newdata == miei->data) {
        printf("PUNTATORI UGUALI\n");
    } else {
        printf("PUNTATORI DIVERSI\n");
    }

    return 0;
}
