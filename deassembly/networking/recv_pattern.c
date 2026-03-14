#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>

#define INITIAL_BUFFER_SIZE 1024

/*
    Riceve tutti i dati disponibili da un socket.
    - Alloca un buffer iniziale
    - Legge a blocchi
    - Se il buffer si riempie, lo espande con realloc
    - Restituisce il buffer finale e la lunghezza tramite out_size

    Nota:
    Il buffer restituito contiene un byte '\0' finale per comodità,
    così può essere trattato anche come stringa se i dati lo permettono.
*/
unsigned char *receive_all(int sockfd, size_t *out_size)
{
    size_t capacity = INITIAL_BUFFER_SIZE;
    size_t used = 0;
    unsigned char *buffer = malloc(capacity + 1);  // +1 per terminatore opzionale

    if (buffer == NULL) {
        perror("malloc");
        return NULL;
    }

    while (1) {
        /* Se il buffer è pieno, raddoppia la capacità */
        if (used == capacity) {
            size_t new_capacity = capacity * 2;
            unsigned char *new_buffer = realloc(buffer, new_capacity + 1);

            if (new_buffer == NULL) {
                free(buffer);
                perror("realloc");
                return NULL;
            }

            buffer = new_buffer;
            capacity = new_capacity;
        }

        /* Riceve nel segmento libero del buffer */
        /*
        sockfd → il socket da cui leggere
        buf → il buffer dove verranno scritti i dati
        len → numero massimo di byte da leggere
        flags → opzioni (di solito 0)
        */
        ssize_t bytes_received = recv(sockfd, buffer + used, capacity - used, 0);

        if (bytes_received > 0) {
            used += (size_t)bytes_received;
        }
        else if (bytes_received == 0) {
            /* Connessione chiusa dal peer */
            break;
        }
        else {
            /* Errore */
            if (errno == EINTR) {
                continue; /* ritenta se interrotto da segnale */
            }

            free(buffer);
            perror("recv");
            return NULL;
        }
    }

    /* Terminatore opzionale */
    buffer[used] = '\0';

    if (out_size != NULL) {
        *out_size = used;
    }

    return buffer;
}




int main(void)
{
    int sockfd = -1; /* qui dovrebbe esserci un socket già connesso */
    size_t data_size = 0;

    unsigned char *data = receive_all(sockfd, &data_size);
    if (data == NULL) {
        fprintf(stderr, "Errore nella ricezione dei dati\n");
        return 1;
    }

    printf("Ricevuti %zu byte\n", data_size);

    /* Se i dati sono testo */
    printf("Contenuto:\n%s\n", data);

    free(data);
    return 0;
}






/*

Kernel socket receive buffer

+-----------------------------------+
| A B C D E F G H I J K L M N O P |
+-----------------------------------+


recv(sockfd, buf, 5, 0);


+-----------------------------------+
| F G H I J K L M N O P            |
+-----------------------------------+


dati letti → rimossi
dati restanti → rimangono


*/



