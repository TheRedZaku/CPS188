/* Lab #5 Problem #3*/

#include <stdio.h>
#include <ctype.h>

void areaTrapezoid(double shortBase, double longBase, double height, double *area) {
    *area = (shortBase + longBase) * height / 2;    
}

void validateInput(double *ptr) {
    
    int pass = 0;
    double input;
    
    do {
        scanf("%lf", &input);
        if (input > 0) {//checks the input, and stores it only if it is greater than 0. Otherwise, the while loop repeats
            *ptr = input;
            pass = 1;
        } else {
            printf("\033[1;6;31m" "Input must be a positive number. Please try again.\n" "\033[0m");
        }
    } while (pass != 1);
}

int main(void) {

    double shortBase, longBase, height, area;
    char choice = 'y';

        fflush(stdin);
        printf("Trapezoid Area Calculator\nWhat is the length of the short base: ");
        validateInput(&shortBase);
        printf("\nWhat is the length of the long base: ");
        validateInput(&longBase);
        printf("\nWhat is the height: ");
        validateInput(&height);
        areaTrapezoid(shortBase, longBase, height, &area);
        printf("The surface area of the trapezoid is %.3lfunits\u00B2.\nPress enter to exit.", area);
        //will not display correctly in an IDE, must change input language or use something like OnlineGDB
        fflush(stdin);
        getchar();
    return 0;
}