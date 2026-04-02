/* Lab #9 Problem #2 */

#include <stdio.h>
#include "mylibrary.h"
#include <string.h>
#include <stdlib.h>

#define SIZE 10 //size of the array
#define SCANNER_SIZE 1000 //scanner buffer space
#define DELIMITER " " //delimit at spaces -> preferable to use fgets rather than fscanf

int main(void) {

    FILE *in; 
    FILE *out;
    double num[SIZE][SIZE];
    char *token;

    in = fopen("CTextFiles\\L9_real.txt", "r"); //the file of data
    out = fopen("CTextFiles\\results.bin", "w"); //the output file (the results)

    char scanner[SCANNER_SIZE];

    if (fgets(scanner, SCANNER_SIZE, in) != NULL) { //checks if the file reads at first
        token = strtok(scanner, DELIMITER); //grab the initial string and convert the first component into a token
        
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                    num[i][j] = atof(token); //convert the scanned token into a float
                    token = strtok(NULL, DELIMITER); //read the next token in the string
            }
        }
    }

    fclose(in);

    //print out the results into the output file "results.bin"
    fprintf(out, "The sum of the diagonal array elements is %.2lf.\n"
                "The sum of all the array elements is %.2lf.\n"
                "The average of the last array elements is  %.2lf.\n"
                "The sum of the four corner array elements is %.2lf."
                , sumDiagonal(SIZE, num), sumAll(SIZE, num), avgLast(SIZE, num), sumCorners(SIZE, num));

    fclose(out);

    //print out the results to the console
    printf("The sum of the diagonal array elements is %.2lf.\n"
                "The sum of all the array elements is %.2lf.\n"
                "The average of the last array elements is  %.2lf.\n"
                "The sum of the four corner array elements is %.2lf."
                , sumDiagonal(SIZE, num), sumAll(SIZE, num), avgLast(SIZE, num), sumCorners(SIZE, num));

    return 0;

}