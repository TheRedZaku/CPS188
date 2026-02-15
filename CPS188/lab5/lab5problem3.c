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
        if (input > 0) {
            *ptr = input;
            pass = 1;
        } else {
            printf("\033[1;6;31m" "Input must be a positive number. Please try again.\n" "\033[0m");
        }
    } while (pass != 1);
}

int main(void) {

    int pass = 0;
    double shortBase, longBase, height, area;
    char choice;

    do {
        fflush(stdin);
        printf("Trapezoid Area Calculator\nWhat is the length of the short base: ");
        validateInput(&shortBase);
        printf("\nWhat is the length of the long base: ");
        validateInput(&longBase);
        printf("\nWhat is the length of the height: ");
        validateInput(&height);
        areaTrapezoid(shortBase, longBase, height, &area);
        fflush(stdin);
        printf("The surface area of the trapezoid is %.3lfunits\u00B2.\nWould you like to do another calculation? [Y/N]: ", area);
        scanf("%c", &choice);
        if (tolower(choice) == 'n') {
            pass = 1;
        }
    } while (pass != 1);
    return 0;
}