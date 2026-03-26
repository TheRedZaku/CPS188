/* Lab #8 Problem #1 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define SIZE 1000
#define COLUMNS 30 //30 years, the 1 is from the row headers
#define ROWS 365 //first row is the header, which can be ignored when scanning
#define DELIMITER ",\n" //breaks string up whenever a comma or a new line is encountered

int main(void) {

    FILE *in;
    char *token; //token for splitting the csv values
    double temperature[ROWS][COLUMNS];
    double average[6], highest = 0, compare = 0;
    int year = 0;
    in = fopen("ctextfiles\\ontario.csv", "r");

    char scanner[size];


    fgets(scanner, size, in);

    
    for (int i = 0; i < rows; i++) {

        fgets(scanner, size, in);
        token = strtok(scanner, delimiter); //takes the rest of the string, ignoring the row header
        
        for (int j = 0; j < columns; j++) {

            token = strtok(NULL, DELIMITER); //splits the string to the next token

            if (token != NULL) {
                temperature[i][j] = atof(token); //converts the string to a float/double

                switch(j) {
                    case 24: average[0] += temperature[i][j]; break; //2020
                    case 25: average[1] += temperature[i][j]; break; //2021
                    case 26: average[2] += temperature[i][j]; break; //2022
                    case 27: average[3] += temperature[i][j]; break; //2023
                    case 28: average[4] += temperature[i][j]; break; //2024
                    case 29: average[5] += temperature[i][j]; break; //2025
                }

                if (i == 184) {
                    compare = temperature[i][j]; //sets the next value to be compared
                    if (compare > highest) { //if the new comparable value is greater than the current highest, it becomes the new highest
                        highest = compare;
                        year = j; //the year is also stored.
                    }
                }
            } else {
                temperature[i][j] = 0; // if the token is empty, it fills the cell with 0
            }

        }

    }

    fclose(in);
    
    for (int i = 0; i < 6; i++) { 
        average[i] /= ROWS; //determines the average by dividing by the number of days (i.e. ROWS)
        printf("The average of the temperatures for the year %d is %.2lf.\n", i + 2020, average[i]); //printing each average
    }

    printf("The year with the highest temperature on day 185 was %d, with a recorded temperature of %.2lf.", year + 1995, highest); 

    return 0;
}
