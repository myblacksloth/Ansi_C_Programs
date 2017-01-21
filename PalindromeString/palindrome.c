/********************************************************************************************************************************************************
* PROGRAMMA CHE COMPUTA SE UNA STRINGA E' PALINDROMA O MENO
* Language: ANSI C
* Date: 13/10/2016
* Author: Antonio Maulucci
* Si utilizza un ciclo for per invertire la stringa e conservarne il contenuto in una nuova stringa avente la stessa dimensione di quella inserita dall'utente
********************************************************************************************************************************************************/


#include <stdio.h>
#include <string.h>

/*********************
#define debug 1
*********************/




int main() {


  char s1[256]; /* variabile che immagazzina la stringa inserita dall'utente */

  int i=0, j=0; /* variabili per il ciclo for */


  printf("\nInserisci una stringa: ");
  scanf("%s", s1);
  printf("\nLa stringa inserita e': %s", s1);

  char s2[strlen(s1)];

 /** debug area **/
  #ifdef debug
  printf("\n\n_debug_ lunghezza stringa: %lu\n\n", strlen(s1)); /* unsigned long */
  #endif
  /** debug area **/


  i=0; /* la i viene inzializzata a 0 perche' serve per leggere la stringa originaria e verra' incrementata volta per volta */
  for (j=strlen(s1)-1; j>=0; j--) { /* viene tolta una posizione perche' e' quella del terminatore che verra' aggiunto alla stringa dopo il ciclo for */
    s2[j]=s1[i];
    i++;
  } /* end of for */
  s2[strlen(s1)] = '\0'; /* terminatore per la stringa */


  printf("\nLa stringa invertita e': %s", s2);



  if (strcmp(s1, s2)==0) {
    printf("\n\n\nLA STRINGA INSERITA E' PALINDROMA");
  } /* end of if */
  else {
    printf("\n\n\nSPIACENTE MA LA STRINGA INSERITA NON E' PALINDROMA");
  } /* end of else */







  printf("\n\n");
  return 0;
}
/** end of main **/
