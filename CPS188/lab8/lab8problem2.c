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

        //fgets(scanner, SIZE, in);

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

    for (int j = 0; j < data; j++) {//loops through the total number of addresses

        for(int k = j+1; k < data; k++) {//it is starting at j+1, so that no redundant loops are completed. ex. if j is 1, then the inner loop will check from 2 to the end, instead of wasting time checking the identical loop

            if (localnet(&internet[j], &internet[k]) == 1) {
            printf("Servers %s and %s are on the same local network.\n", internet[j].nickname, internet[k].nickname);
            }

        }

    }

    //complete list of all the addresses read into the program, with their respective nicknames
    printf("IPv4 Address ---- Nickname\n");
    for (int i = 0; i < data; i++) {
        printf("%03d.%03d.%03d.%-03d %s\n", internet[i].aa, internet[i].bb, internet[i].cc, internet[i].dd, internet[i].nickname);
    }

    return 0;
}