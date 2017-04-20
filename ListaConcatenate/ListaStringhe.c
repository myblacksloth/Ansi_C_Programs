/*
 (C) Antonio Maulucci 2017 http://www.antomau.com
 */
/*
 Questo programma implementa una lista concatenata in linguaggio Ansi C i cui nodi contengono delle stringhe
 e implementa le funzioni per
 stampare la lista
 inserire un nodo in testa alla lista
 eliminare il nodo in testa alla lista
 eliminare il nodo in coda alla lista
 eliminare tutti i nodi contenenti una determinata stringa
 eliminare il carattere iniziale di tutte le stringhe presenti nella lista (in ogni nodo)
 eliminare il carattere finale di tutte le stringhe presenti nella lista
 eliminare uno specifico carattere da tutte le stringhe presenti nella lista
 eliminare in ogni stringa il carattere presente in una determinata posizione all'interno della stringa
 stampare ogni stringa al contrario
 *
 (C) Antonio Maulucci 2017 http://www.antomau.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* prototipi */
int menu();
void inserisci(char*);
void inseriscicoda(char*);
void display();
void eliminaTesta();
void eliminaCoda();
void elimina(char*);
void eliminacharstart();
void eliminacharfine();
void eliminachar(char);
void eliminaindex(int);
void rovesciastringhe();



typedef struct nodo
{
    char *s;
    struct nodo *link;
    
} Nodo;



Nodo *headList = NULL;


int main()
{
 
    int menuchoice=1;
    char stringa[256];
    char carattere;
    int chooice;
    
    while (menuchoice!=0)
    {
        menuchoice = menu();
        
        switch(menuchoice)
        {
            case 1:
                printf("\n\nInserisci una stringa per la lista:");
                scanf("%s", stringa);
                inserisci(stringa);
                break;
            case 2:
                display();
                break;
            case 3:
                eliminaTesta();
                break;
            case 4:
                eliminaCoda();
                break;
            case 5:
                printf("\nInserisci la stringa contenuta dal nodo da eliminare:");
                scanf("%s", stringa);
                elimina(stringa);
                break;
            case 6:
                eliminacharstart();
                break;
            case 7:
                eliminacharfine();
                break;
            case 8:
                printf("\nInserisci il carattere da eliminare:");
                while(((carattere=getchar())!='\n') && (carattere!=EOF)) {}
                scanf("%c", &carattere);
                eliminachar(carattere);
                break;
            case 9:
                printf("\nInserisci l'indice del carattere da eliminare:");
                scanf("%d", &chooice);
                eliminaindex(chooice);
                break;
            case 10:
                rovesciastringhe();
                break;
            case 11:
                printf("\n\nInserisci una stringa per la lista:");
                scanf("%s", stringa);
                inseriscicoda(stringa);
                break;
            case 0:
                break;
            default:
                printf("\nHai inserito un valore non valido! Riprova!");
                break;
        }
        
    }
    
    return 0;
    
}



int menu()
{
    int choice;
    printf("\nMenu: (1) Inserisci stringa");
    printf("\nMenu: (2) Stampa la lista");
    printf("\nMenu: (3) Elimina primo nodo");
    printf("\nMenu: (4) Elimina ultimo nodo");
    printf("\nMenu: (5) Elimina nodo qualsiasi");
    printf("\nMenu: (6) Elimina carattere iniziale dalla stringa");
    printf("\nMenu: (7) Elimina carattere finale della stringa");
    printf("\nMenu: (8) Elimina un carattere della stringa");
    printf("\nMenu: (9) Elimina un carttere presnente in una posizione precisa:");
    printf("\nMenu: (10) Stampa le stringhe rovesciate");
    printf("\nMenu: (11) Inserisci stringa in coda");
    printf("\nInserisci la scelta:");
    scanf("%d", &choice);
    return choice;
}





void inserisci(char* stringa)
{
    printf("\nHai scelto di inserire la stringa: %s", stringa);
    
    Nodo *new = (Nodo*) malloc (sizeof(Nodo));
    

    new->s = (char*) malloc((sizeof(stringa)+1)*sizeof(char));
    
    strcpy(new->s, stringa);
    
    new->link =headList;
    
    headList = new;
    
}



void inseriscicoda(char* stringa)
{
    printf("\nHai scelto di inserire la stringa: %s", stringa);

    Nodo *ptr = headList;
    Nodo *new = (Nodo*) malloc (sizeof(Nodo));

    new -> s = (char*) malloc ((sizeof(stringa)+1)*sizeof(char));

    strcpy(new->s, stringa);

    /*scorrimento verso la fine */
    new -> link = NULL;
    if (!ptr) headList = new;
    else
    {
        while (ptr && ptr->link)
            ptr = ptr->link;

        ptr->link = new;
    }
}





void display()
{
    Nodo *cur = headList;
    
    while (cur)
    {
        printf("\n%s", cur->s);
        cur = cur->link;
    }
}







void eliminaTesta()
{
    headList = headList->link;
}


void eliminaCoda()
{
    Nodo *cur = headList;
    Nodo *previous = NULL;
    
    while (cur->link)
    {
        previous = cur;
        cur = cur->link;
    }
    
    previous->link = NULL;
}





void elimina(char* e)
{
    Nodo *prec = NULL;
    Nodo *cur = headList;
    
    if (prec!=NULL) printf("\nprec: %s", prec->s);
    printf("\ncur: %s", cur->s);
    
    while(cur)
    {
        if ((!strcmp(cur->s, e)) && !prec)
        {
          headList=cur->link;
            free(cur);
        }
        if (!strcmp(cur->s, e) && prec) prec->link = cur->link;
            
        prec = cur;
        cur = cur->link;
    }
    
}






void eliminacharstart()
{
    Nodo *cur = headList;
    
    while (cur)
    {
        int i; /* variabile per il cilo for */
        char stringa[256];
        
        int c = 0; /* variabile per lo scorrimento della nuova stringa */
        
        for (i=1; i<strlen(cur->s); i++) /* il ciclo for parte da 1 perche' il carattere 0 e' quello da eliminare e arriva a <strlen e non a <=strlen perche' la nuova stringa avra' un carattere in meno rispetto a quella originaria */
        {
            
            stringa[c] = cur->s[i];
            
            c++;
        }
        
        cur->s = (char*) malloc (sizeof(stringa)+1 * sizeof(char));
        
        strcpy(cur->s, stringa);
        
        cur = cur->link;
    }
}






void eliminacharfine()
{
    Nodo *cur = headList;
    
    while (cur)
    {
        
        int i;
        
        char stringa[256];
        
        int c=0;
        
        for (i=0; i<strlen(cur->s)-1; i++)
        {
            stringa[c] = cur->s[i];
            c++;
        }
        
        cur->s = (char*) malloc (sizeof(stringa)+1 * sizeof(char));
        
        strcpy(cur->s, stringa);
        
        cur = cur->link;
    }
}







void eliminachar(char c)
{
    Nodo *cur = headList;
    
    while(cur)
    {
       
        int i; /* variabile per il ciclo for */
        char stringa[256];
        
        int k=0; /* variabile per l'avanzamento all'interno della nuova stringa */
        
        for (i=0; i<=strlen(cur->s); i++)
        {
            if (c!=cur->s[i])
            {
                stringa[k] = cur->s[i];
                k++;
            }
            
        }
        
        cur->s = (char*) malloc (sizeof(stringa)+1 * sizeof(char));
        
        strcpy(cur->s, stringa);
        
        cur = cur->link;
    }
    
}










void eliminaindex(int e)
{
    
    Nodo *cur = headList;
    
    while (cur)
    {
        
        
        if (e <= strlen(cur->s))
        {
            
            int i;
            int k=0;
            char stringa[256];
            
            for (i=0; i<e; i++)
            {
                stringa[k] = cur->s[i];
                k++;
            }
            
            for (i=e+1; i<=strlen(cur->s); i++)
            {
                stringa[k] = cur->s[i];
                k++;
            }
            
            cur->s = (char*) malloc (sizeof(stringa)+1 * sizeof(char));
            
            strcpy(cur->s, stringa);
            
            cur = cur->link;
        }
        
        
        
        
    }
    
}







void rovesciastringhe()
{
    Nodo *cur = headList;
    
    while (cur)
    {
        char rovesciata[strlen(cur->s)];
        
        int i;
        
        int p = (int)strlen(cur->s)-1; /* casting da un operazione che restituisce un valore unsigned long ad un valore di tipo interocfrl */
        
        int k=0;
        for (i=p; i>=0; i--)
        {
            rovesciata[k]=cur->s[i];
            k++;
        }
        
        printf("\nStringa rovesciata: %s", rovesciata);
        
        cur = cur->link;
    }
}




