/*
 * (C) Antonio Maulucci 2017 http://www.antomau.com
 */

/*
 * Questo programma implementa un array di interi utilizzando l'allocazione dinamica della memoria.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    
    int size, i, value;
    
    printf("\nQuante stringhe vuoi inserire?");
    scanf("%d", &size);
    
    int *array[size];
    
    for (i=0; i<size; i++)
    {
        printf("\nInserisci il valore:");
        scanf("%d", &value);
        printf("\n%d", value);
        array[i] = (int*) malloc(sizeof(value));
        *array[i] = value;
    }
    
    printf("\nStampo i dati:\n");
    for (i=0; i<size; i++)
    {
        printf("\n%d", *array[i]);
    }
    
    printf("\n\n\n");
    return 0;
}
