/*
 * STAMPARE TUTTI GLI ELEMENTI SITUATI SULLA DIAGONALE PRICIPALE DI UNA MATRICE
 * (C) Antonio Maulucci 2017
 */


# include <stdio.h>


int main(int argc, char* argv[])
{

	int n=0;

	printf("Numero di righe e colonne:");

	scanf("%d", &n);


	int matrix[n][n];


	/* riempimento matrice */
	int i = 0, j=0;
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			printf("\n Inserisci l'elemento %d,%d:", i, j);
			scanf("%d", &matrix[i][j]);
		}
	}

	printf("\n\nStampo tutti gli elementi che si trovano sulla diagonale principale:");

	for (i=0; i<n; i++)
		printf("\n%d", matrix[i][i]);

	printf("\n\n\n");


	return 0;
}