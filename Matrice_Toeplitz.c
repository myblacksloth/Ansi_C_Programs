/*
 * VERIFICARE UNA MATRICE DI TOEPLITZ
 * (C) Antonio Maulucci 2017
 * Language: ANSI C
 * La matrice di Topelitz e' una mtrice avente delle costanti lungo la diagonale principale
 * Questo programma e' in grado di verificare la sola presenza di numeri da 0 a 9
 * esso converte i valori in interi per verificare il loro valore nella tabella ASCII
 */

#include <stdio.h>


int toeplitz(int n, char matrix[n][n]);


int main(int argc, char* argv[])
{
    
    int n = 0;
    
    int esito = 0;
    
    printf("\nNumero di righe e colonne?");
    
    scanf("%d", &n);
    
    char matrix[n][n];
    
    /*riempimento della matrice*/
    int i =0, j = 0;
    char x;
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            printf("\nInserisci il valore della cella %d %d:", i, j);
            while(((x=getchar())!='\n') && (x!=EOF)) {}
            scanf("%c", &matrix[i][j]);
        }
    }
    
    
    esito = toeplitz(n, matrix);

    esito==0 ? printf("\n\nOK\n") : printf("\n\nNO\n");
    
    return 0;
}



int toeplitz(int n, char matrix[n][n])
{
    int i = 0;
    
    char cur;
    
    for (i=0; i<n; i++)
    {
        cur = (char)matrix[i][i];
        
        if ((int)cur<48 || (int)cur>57)
            return 1;
    }
    
    return 0;
}
