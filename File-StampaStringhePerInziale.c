/*
 * DATO UN FILE FORMATTATO COME
 * CARATTERE STRINGA1 STRINGA2\n PER OGNI RIGA
 * SI STAMPI, PER OGNI RIGA, SOLO LA PAROLA CHE NON INIZIA PER IL CARATTERE DATO
 *
 * (C) Antonio Maulucci 2017
 * Language: ANSI C
 */

#include <stdio.h>


int main()
{
    
    FILE *file;
    
    file = fopen("text.txt", "r"); /*apertura file*/
    
    if (file == NULL)
    {
        printf("\n file error!\n");
        return 1;
    }
    
    
    char c = '\0';
    char worda[256]="", wordb[256]="";
    
    while (!feof(file))
    {
        fscanf(file, "%c %s %s\n" , &c, worda, wordb);
        printf("\nchar and token word = %c %s %s",c, worda, wordb);
        
        if (worda[0]!=c)
            printf("\n%s", worda);
        
        if (wordb[0]!=c)
            printf("\n%s", wordb);
        
        
    }
    
    printf("\n\n");
    
    return 0;
}
