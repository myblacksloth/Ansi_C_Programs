/*
 * (C) Antonio Maulucci 2026
 */

// nc 127.0.0.1 8883

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* importo le librerie che mi permettono di utilizzare le socker per le connessioni di rete */
#include <sys/socket.h> // socket
#include <netinet/in.h> // per struct sockaddr_in
#include <arpa/inet.h> // per le funzioni di conversione degli indirizzi
#include <unistd.h> // per la funzione close

#define BUF_SIZE 1024
#define MAX_CONN 256
int main()
{

    // dichiaro un buffer
    char buffer[BUF_SIZE];
    if (      ! memset(buffer, 0, BUF_SIZE)      )
    {
        exit(1);
    }


    /* dichiaro le variabili utili alle connessioni dei client*/
    /* la struttura client_address contiene le informazioni della connessione accettata dal server */
    struct sockaddr_in client_address;
    /* clilen corrisponde alla dimensione della struttura client_address */
    socklen_t clilen = sizeof(client_address);
    /* la variabile connection corrisponde al file desccriptor della socket di connessione con il client (dopo accept) */
    int connection = -1;
    /* la variabile clientip corrisponde all'IP del client (utile per scrivere le informazioni sul client nel file di output) */
    char *clientip = NULL;


    int socket_d; // main socket descriptor
    int server_port = 8883; // porta su cui lavora il server

    /* Ottengo un socket descriptor */
    /*
    * domain = AF_INET = protocollo per IPv4
    * tipo = SOCK_STREAM = canale bidirezionale, sequenziale, affidabile
    *   opera come flusso continuo di byte
    * protocollo = 0 = il protocollo e' dichiarato implicitamente dal tipo di socket
    *   quindi, eccetto per le raw_socket, non e' necessario dichiararlo
    */
    socket_d = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_d < 0)
    {
        return 1;
    }

    /* specifico l'indirizzo e la porta del server */
    /* -------------------------------------------------
    * gli indirizzi per le connessioni si specificano tramite apposite strutture dati
    *   in questo caso del tipo
    *                           struct sockaddr
    *   oppure  struct sockaddr_in
    * -------------------------------------------------
    * #include <netinet/in.h>
    * struct sockaddr_in {
    *     short            sin_family;   // e.g. AF_INET
    *     unsigned short   sin_port;     // e.g. htons(3490)
    *     struct in_addr   sin_addr;     // see struct in_addr, below
    *     char             sin_zero[8];  // zero this if you want to
    * };
    * struct in_addr {
    *     unsigned long s_addr;  // load with inet_aton()
    * };
    ------------------------------------------------- */
    struct sockaddr_in server_address;
    if (    ! memset(&server_address, 0, sizeof(server_address))      )
    {
            exit(1);
    }
    server_address.sin_family = AF_INET; // dominio di connessione IPv4

    /*
    * INADDR_ANY si usa per specificare un indirizzo IP generico (0.0.0.0)
    *
    * The htonl() function converts the unsigned integer hostlong  from  host byte order
    *   to network byte order
    */
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);


    /*
    * The htons() function converts the unsigned short integer hostshort
    *   from host byte order to network byte order
    */
    server_address.sin_port = htons(server_port); // port passato come argomento della funzione


    if ( bind ( socket_d, (struct sockaddr*) &server_address, sizeof(server_address) )  < 0 )
    {
        return 1;
    }

    if (    listen(socket_d, MAX_CONN)   != 0 )
    {
        return 1;
    }

    // accetta connessioni in entrata
    connection = accept(socket_d , (struct sockaddr*) &client_address, &clilen);

    // leggi ip del client
    clientip = (char*)malloc( (strlen(inet_ntoa(client_address.sin_addr)) ) + 1 * sizeof(char));
    if (clientip == NULL)
    {
            return 1;
    }
    if (   ! strcpy(clientip, inet_ntoa(client_address.sin_addr))  )
    {
            return 1;
    }

    printf("[debug logger.logger] Connessione sulla socket %d\n", connection);
    printf("Ricevuta connessione da IP: %s\n", clientip);

    // chiudo socket generica
    if (       close(socket_d)   != 0     )
    {
        return 1;
    }

    /* dichiaro una variabile per calcolare la quantita' di dati scambiati */
    size_t data_size = 0;

    /* dichiaro una variabile per memorizzare tutti i dati ricevuti tramite la socket */
    char* data = (char*)malloc(1 * sizeof(char));
    if (! data)
    {
        exit(1);
    }

    // imposta come stringa vuota
    data[0] = '\0';

    // leggo dati ricevuti dalla socket
    while (    (data_size = recv(connection, buffer, BUF_SIZE-1, 0)) > 0     )
    {

        buffer[data_size] = '\0';


        /* a questo punto preparo lo spazio necessario per aggiungere i nuovi dati dal client */
        data = (char*)realloc(   data, ( strlen(data)   + strlen(buffer) +1 +1    )  * sizeof(char)   );
        if( ! data )
        {
            exit(1);
        }
        // inserisco i dati nel buffer
        if (      ! strcat(data, buffer)      )
        {
            exit(1);
        }

        // ristampa sempre tutto l'intero messaggio da 0 perche' di fatto data non viene mai ripulito
        printf("Il contenuto ricevuto finora e': %s di dimensione %zu\n", data, strlen(data));

        /* azzero nuovamente il buffer per la ricezione di nuovi dati */
        if (    ! memset(buffer, 0, BUF_SIZE)      )
        {
                exit(1);
        }
    }

    // chiudo la connessione
    if (       close(connection)   != 0     )
    {
        return 1;
    }

    return 0;
}
