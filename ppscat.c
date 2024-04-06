
/* ***************************************************************************
* ppscat - privileged pseudo-cat
* (C) 2024 Antonio Maulucci
*
* This program is part of ETH Project
* it has the objective to show how wrong privileges can cause disasters
*
* Not every functions' errors are correctly managed
*
* This code properly work on Linux but not in MacOs... MacOs does not support long options
*
* Usage example:
* $ gcc -o ppscat ppscat.c
* $ ./ppscat -f /etc/shadow
* $ sudo chown root ./ppscat
* $ sudo chmod u+s ./ppscat
* $ ./ppscat -f /etc/shadow
*
*
*************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include <errno.h>

void closeall(char** fname, char** content)
{
        free(*fname);
        *fname = NULL;
        free(*content);
        *content = NULL;
}

int main(int argc, char** argv)
{

        char* fname = NULL;
        FILE* reading = NULL;
        char tmp[4096] = {};
        char* content = NULL;
        void (*memf)(char**, char**)=&closeall;

        int choice = -1;
        char* options="f:";
        int longindex = -1;
        struct option longopts[] = { {"file", required_argument, 0, 'f'}, {0, 0, 0, 0} };
        // while ( (choice = getopt(argc, argv, "f:")) != -1 )
        while (( choice = getopt_long(argc, argv, options, longopts, &longindex) ) != -1)
        {
                switch(choice)
                {
                        case 'f':
                                fname = (char*)malloc(sizeof(char) * (strlen(optarg)+1));
                                strcpy(fname, optarg);
                                break;
                        case 0:
                                printf("%d\n", longindex);
                                exit(1);
                                break;
                        default:
                                exit(EXIT_FAILURE);
                }
        }

        if (! fname) { errno = EINVAL; perror("File non fornito"); exit(1); }


        reading = fopen(fname, "r");
        if (! reading)
        {
                errno=ENOENT; perror("Unable to read");     (*memf)(&fname, &content);        exit(2);
        }

        content = (char*)malloc(sizeof(char));
        if (! content)
        {
                errno=ENOMEM; perror("Errore"); (*memf)(&fname, &content);
                exit(3);
        }
        while (! feof(reading))
        {
                /*fscanf(reading, "%s", tmp);*/ fgets(tmp, 4096, reading);
                content = (char *)realloc (content, sizeof(char)*(strlen(content)+strlen(tmp)+/*2*/1)); if (! content) {errno=ENOENT; perror("Errore"); (*memf)(&fname, &content); exit(4);} strcat(content, tmp); /*strcat(content, "\n");*/ memset(tmp, 0, 4096);
        }

        if (content) { printf("%s", content); }

        fclose(reading);

        (*memf)(&fname, &content);
        if (fname || content)
        {
                errno=EFAULT; perror("ecchecca");
        }

        exit(EXIT_SUCCESS);
}

