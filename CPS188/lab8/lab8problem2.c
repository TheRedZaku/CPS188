/* Lab #8 Problem #2 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NICKNAME_SIZE 20
#define SIZE 1000
#define DELIMITER ". \n"
#define ADDRESSES 300
#define SENTINEL "sentinel\0"

struct address_t {

    int aa, bb, cc, dd;
    char nickname[NICKNAME_SIZE];
    
};

int localnet(struct address_t *system1, struct address_t *system2) {
    if (system1 -> aa == system2 -> aa && system1 -> bb == system2 -> bb) {
        return 1;
    } else {
        return 0;
    }
}

int main(void) {

    struct address_t internet[ADDRESSES];

    char scanner[SIZE];
    char *token;
    int data = 0;
    
    FILE *in;
    in = fopen("CTextFiles\\L8_ip.txt", "r"); //create the file reader

    for (int i = 0; i < ADDRESSES; i++) {

        fgets(scanner, SIZE, in);

        if (fgets(scanner, SIZE, in) != NULL) {

            token = strtok(scanner, DELIMITER);

            if (token != NULL) {

                internet[i].aa = atoi(token);
                 //converts the token chunk into an integer, stored in that addresses initial value
                token = strtok(NULL, DELIMITER);
                internet[i].bb = atoi(token); 
                token = strtok(NULL, DELIMITER);
                internet[i].cc = atoi(token); 
                token = strtok(NULL, DELIMITER);
                internet[i].dd = atoi(token); 
                token = strtok(NULL, DELIMITER);
                strncpy(internet[i].nickname, token, NICKNAME_SIZE);
                internet[i].nickname[NICKNAME_SIZE - 1] = '\0';
                if (strcmp(internet[i].nickname, SENTINEL) == 0) {
                    data = i;
                    break;
                }

            } else {
                break;
            }
        }
    
    }

    for (int j = 0; j < data; j++) { //fix this
            if (localnet(&internet[j], &internet[data-j-1]) == 1) {
                printf("\n%s is on the same locality as %s", internet[j].nickname, internet[data-j-1].nickname);
            } else {
                printf("\n%s is not on the same locality as %s", internet[j].nickname, internet[data-j-1].nickname);
            }
    }

    return 0;
}