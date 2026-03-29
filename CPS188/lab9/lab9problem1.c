/* Lab #8 Problem #1 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 1000
#define COLUMNS 31 //30 years, the 1 is from the row headers
#define ROWS 365 //first row is the header, which can be ignored when scanning
#define DELIMITER ",\n" //breaks string up whenever a comma or a new line is encountered

int main(void) {

    FILE *in;
    FILE *out;
    FILE *gnuplot;
    char *token; //token for splitting the csv values
    double temperature[ROWS][COLUMNS];
    double average[ROWS], highest = 0, compare = 0;
    int year = 0, swimTemp[5], swimTempAvg = 0;
    in = fopen("CTextFiles\\ontario.csv", "r");
    out = fopen("CTextFiles\\yearlyaveragetemperature.txt", "w");
    gnuplot = fopen("CTextFiles\\lab9problem1.txt", "w");

    char scanner[SIZE];

    fgets(scanner, SIZE, in);

    for (int i = 0; i < ROWS; i++) {

        fgets(scanner, SIZE, in);
        token = strtok(scanner, DELIMITER); //takes the rest of the string, ignoring the row header
        
        for (int j = 0; j < COLUMNS; j++) {

            token = strtok(NULL, DELIMITER); //splits the string to the next token

            if (token != NULL) {
                temperature[i][j] = atof(token); //converts the string to a float/double

                /*switch(j) {
                    case 25: average[0] += temperature[i][j]; break; //2020
                    case 26: average[1] += temperature[i][j]; break; //2021
                    case 27: average[2] += temperature[i][j]; break; //2022
                    case 28: average[3] += temperature[i][j]; break; //2023
                    case 29: average[4] += temperature[i][j]; break; //2024
                    case 30: average[5] += temperature[i][j]; break; //2025
                }*/

                average[j] += temperature[i][j];

                /*if (i == 184) {
                    compare = temperature[i][j]; //sets the next value to be compared
                    if (compare > highest) { //if the new comparable value is greater than the current highest, it becomes the new highest
                        highest = compare;
                        year = j; //the year is also stored.
                    }
                }*/

                if (temperature[i][j] > 20) {
                    switch(j) {
                        case 26: swimTemp[0]++; break;
                        case 27: swimTemp[1]++; break;
                        case 28: swimTemp[2]++; break;
                        case 29: swimTemp[3]++; break;
                        case 30: swimTemp[4]++; break;
                    }
                }

            } else {
                temperature[i][j] = 0; // if the token is empty, it fills the cell with 0
            }

        }

    }

    fclose(in);

    fprintf(gnuplot , "set terminal svg enhanced size 600,480\n"
            "set title \'Average Water Temperature over the years\'\n"
            "set xlabel \'Years\'\n"
            "set ylabel \'Temperature (°C)\'\n"
            "set key right center top\n"
            "\nset xrange [1995 : 2025]\n"
            "\nset yrange [0 : 14]\n"
            "set grid\n"
            "plot \"lab9problem1.txt\" using 1:2 title \"3000K\" with lp lw 3 lc \"#330F80\" pt 0\n");

    fclose(gnuplot);

    swimTempAvg = swimTemp[0] + swimTemp[1] + swimTemp[2] + swimTemp[3] + swimTemp[4];
    
    printf("\nYear           Average Water Temperature (Degrees Celsius)");

    for (int i = 0; i < COLUMNS; i++) { 
        average[i] /= ROWS; //determines the average by dividing by the number of days (i.e. ROWS)
        printf("\n%d: %.2lf.", i + 1995, average[i]); //printing each average
        fprintf(out, "%d %.2lf\n", i + 1995, average[i]);
    }

    fclose(out);

    printf("\nThe year with the highest temperature on day 185 was %d, with a recorded temperature of %.2lf."
    "\nNumber of days where swimming is possible:\n2021: %d\n2022: %d\n2023: %d\n2024: %d\n2025: %d", year + 1995, highest, swimTemp[0], swimTemp[1], swimTemp[2], swimTemp[3], swimTemp[4]); 

    return 0;
}
