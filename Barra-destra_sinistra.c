/*
 * BARRETTA CHE SCORRE VERSO DESTRA O VERSO SINISTRA IN BASE AI COMANDI DATI
 * (C) Antonio Maulucci 2017
 */

#include <stdio.h>

int main(int argc, char *argv[])
{

	printf ("\033[2J"); /*clear screen*/

	char bar[] = "----";


	printf("\nPut x to exit, d to turn right, s to turn left\n"); /* stampa istruzioni d'uso */



	printf("%s", bar);

	char in = 'a';


	int l=0, r=0, i=0; /* 1 valore inziale di spostamento left right*/



	/*
	fintanto che l'utente non da come input 'x' l'esecuzione continua.

	La variabile r memorizza gli spostamenti verso destra.
	Verso sinistra non avrebbe senso perche' la barretta (bar) ha inizio a sinistra.

	d:
		viene incrementato lo spostamento verso destra
		se r ha assunto un valore negativo per via degli spostamenti verso sinistra il suo valore viene reimpostato a 0
		viene eliminata tutta la riga
		vengono stampati tanti spazi quanti sono gli spostamenti verso destra
		viene stampata la barretta
	s:
		viene decrementato lo spostamento verso destra
		viene eliminata la riga corrente
		se vi sono stati degli spostamenti verso destra (r deve essere maggiore di 0)
			vengono stampati tanti spazi quanti sono gli spostamenti (precedentemente aggiornati)
		viene stampata la barretta
	*/

	while (in!='x')
	{

		in = getchar();



		if (in=='d')
		{
			r++; /*r serve a contare di quante volte si e' andato verso destra nella scrittura di 'bar'*/
			if (r<0) r=0; /*se r ha assunto un valore negativo per via dei vari spostamenti verso sinistra riportarlo a 0*/
			printf("\r");
			for (i=0; i<=r; i++)
				printf(" ");

			printf("%s", bar);
		}
		else if(in=='s')
		{
			r--;
			printf("\r");
			if (r>0)
				for (i=0; i<r; i++)
					printf(" ");
			printf("%s", bar);
		}

	}






	printf("\n");

	return 0;
}


/*


32
printf("\r%s", bar); //\r e' il backspace


*/