#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 64

typedef struct Node {
    char* s;
} n;

void change(n** p)
{
    // scambia i puntatori senza modificare il puntatore al puntatore
    n* original = *p;
    n* x = (n*)malloc(sizeof(n));
    *p = x;
    printf("was %p now is %p\n", original, *p);
    free(original);
    original = NULL;
}

int main()
{

    n* x = (n*)malloc(sizeof(n));
    x->s = (char*)malloc(sizeof(char) * (BUF_SIZE + 1));

    n** k = &x;

    printf("before\n");
    printf("%p\n", k);
    printf("%p\n", *k);
    change(k);
    printf("after\n");
    printf("%p\n", k);
    printf("%p\n", *k);

    return 0;
}
