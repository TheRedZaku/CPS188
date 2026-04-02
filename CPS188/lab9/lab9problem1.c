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
    int year = 0, swimTemp[5], swimTempSum = 0;
    in = fopen("CTextFiles\\ontario.csv", "r"); //data file
    out = fopen("CTextFiles\\yearlyaveragetemperature.txt", "w"); //write the average temperatures to this file
    gnuplot = fopen("CTextFiles\\lab9problem1.txt", "w"); //the required gnuplot code to create a display

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

                average[j] += temperature[i][j]; //add the token to the array

                /*if (i == 184) {
                    compare = temperature[i][j]; //sets the next value to be compared
                    if (compare > highest) { //if the new comparable value is greater than the current highest, it becomes the new highest
                        highest = compare;
                        year = j; //the year is also stored.
                    }
                }*/

                //track the temperature above 20 when the year is 2021 to 2025
                if (temperature[i][j] > 20) {
                    switch(j) {
                        case 26: swimTemp[0]++; break; //2021
                        case 27: swimTemp[1]++; break; //2022
                        case 28: swimTemp[2]++; break; //2023
                        case 29: swimTemp[3]++; break; //2024
                        case 30: swimTemp[4]++; break; //2025
                    }
                }

            } else {
                temperature[i][j] = 0; // if the token is empty, it fills the cell with 0
            }

        }

    }

    fclose(in);

    //creating a gnuplot file
    fprintf(gnuplot , "set terminal svg enhanced size 600,480\n"
            "\nset title \'Average Water Temperature in Lake Ontario\'\n"
            "\nset xlabel \'Years\'\n"
            "set ylabel \'Temperature (°C)\'\n"
            "set key right center top\n"
            "\nset xrange [1994 : 2026]\n"
            "\nset yrange [0 : 14]\n"
            "\nset grid\n"
            "set boxwidth 1\n"
            "set style fill pattern 1\n"
            "plot \"yearlyaveragetemperature.txt\" using 1:2 title \"NOAA\" with boxes lw 3 lc \"#ABABFF\" pt 0\n");

    fclose(gnuplot);

    swimTempSum = swimTemp[0] + swimTemp[1] + swimTemp[2] + swimTemp[3] + swimTemp[4]; //total number of days above 20 degrees from 2021 to 2025
    
    printf("\nYear    Average Water Temperature (Degrees Celsius)");

    for (int i = 0; i < COLUMNS; i++) { 
        average[i] /= ROWS; //determines the average by dividing by the number of days (i.e. ROWS)
        printf("\n%d                        %.2lf", i + 1995, average[i]); //printing each average
        fprintf(out, "%d %.2lf\n", i + 1995, average[i]);
    }

    fclose(out);

    printf("\nNumber of days where swimming is possible:\n2021: %d\n2022: %d\n2023: %d\n2024: %d\n2025: %d\nThe total number of days you can swim in the years 2021 to 2025 are: %d", swimTemp[0], swimTemp[1], swimTemp[2], swimTemp[3], swimTemp[4], swimTempSum); 

    return 0;
}
