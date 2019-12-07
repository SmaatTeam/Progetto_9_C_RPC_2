#include "fattoreX.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <rpc/rpc.h>

int main(int argc, char const *argv[]) {

    CLIENT *client;
    char *server;
    int servizio;

    void *in;

    static struct Output *out;

    if(argc != 2) {
        printf("Numero argomenti non valido..\n");
        exit(1);
    }

    server = argv[1];

    client = clnt_create(server, FATTOREXPROG, FATTOREXVERS, "udp");
    if(client == NULL) {
        clnt_pcreateerror(server);
        exit(2);
    }

    while(1) {
        printf("************************************\n\nScegli il servizio (1/2/3)\n1 - Classifica\n2 - Vota\n3 - Esci\n\n************************************\n");

        char str_i[20];
        fgets(str_i, 20, stdin);
        servizio = strtol(str_i, NULL, 0);

        if(servizio == 1) {
            printf("Servizio di visualizzazione della classifica\n\n");
            
            out = classifica_giudici_1(in, client);

            if(out == NULL) {
                clnt_perror(client, server);
                printf("Errore: out is null\n");
                continue;
            } else if(&out == NULL) {
                clnt_perror(client, server);
                printf("Errore: & out is null\n");
            }

            for(int i = 0; i < MAXGIUDICI; i++) {
                if(!strcmp(&out->giudici[i], "L")) {
                    printf("Giudice: %s\tPunteggio: %d\n", out->giudici[i].nomeGiudice, out->giudici[i].punteggio);
                }
            }

        } else if(servizio == 2) {

        } else if(servizio == 3) {
             printf("Termino...\n");
             break;
        } else {
            printf("Servizio non valido...\n");
            continue;
        }
    }

    clnt_destroy(client);
}

