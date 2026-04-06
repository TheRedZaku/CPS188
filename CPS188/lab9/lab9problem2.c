/* Lab #9 Problem #2 */

#include <stdio.h>
#include "mylibrary.h"
#include <string.h>
#include <stdlib.h>
 
#define SIZE 10 //size of the array
#define SCANNER_SIZE 1000 //scanner buffer space
#define DELIMITER " " //delimit at spaces -> preferable to use fgets rather than fscanf
#define RESULT_SIZE 4

int main(void) {

    FILE *in; 
    FILE *out;
    double num[SIZE][SIZE];
    double results[RESULT_SIZE];
    char *token;

    in = fopen("CTextFiles\\L9_real.txt", "r"); //the file of data
    out = fopen("CTextFiles\\results.bin", "wb"); //the output file (the results)

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

    //printing of results happens in the function call
    //the following calls all the functions and writes, meaning they don't have to be assigned to values
    sumDiagonal(SIZE, num, out);
    sumAll(SIZE, num, out);
    avgLast(SIZE, num, out);
    sumCorners(SIZE, num, out);

    fclose(out);//close the file
    out = fopen("CTextFiles\\results.bin", "rb"); //reopen in binary reading mode
    fread(results, sizeof(double), 4, out); //read the data into a new array
    
    //print out the results to the console
    printf("The sum of the diagonal array elements is %.2lf.\n"
                "The sum of all the array elements is %.2lf.\n"
                "The average of the last array elements is  %.2lf.\n"
                "The sum of the four corner array elements is %.2lf."
                , results[0], results[1], results[2], results[3]);
    
    fclose(out);
    
    fflush(stdin);
    getchar();
    return 0;

}