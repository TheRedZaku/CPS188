/*Lab #3 Problem #2*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

#define BOLD_TEXT "\033[1m"
#define DEFAULT "\033[0m"
#define BOLD_SLOW_BLINK_RED_COLOUR "\033[1;6;31m"

double bmiCalculator (double weight, double height) {

    double bmi;

    return bmi = weight / pow(height, 2);
}

int main(void) {

    char yn; //program repetition check
    int pass = 0, weightCheck = 0, heightCheck = 0; //loop exit conditions
    double weight, height, bmi;

    do {
        system("cls");
        printf(BOLD_TEXT "BMI Calculation Program\n" DEFAULT);
        fflush(stdin);
        getchar();
        fflush(stdin);
        
        //input validation only for numbers. Doesn't check if string is entered.
        while (weightCheck == 0) {
            system("cls");
            fflush(stdin);
            printf(BOLD_TEXT "What is your weight in kg: " DEFAULT);
            scanf(" %lf", &weight);
            fflush(stdin);
            if (weight <= 0 || weight >= 700) {
                printf(BOLD_SLOW_BLINK_RED_COLOUR "\nInvalid input.\nYour weight must be between (0 - 700)kg.\nPress enter to continue..." DEFAULT);
                fflush(stdin);
                getchar();
                fflush(stdin);
            } else {
                weightCheck = 1;
            }
        }
    
        //input validation for input range only. Doesn't validate for string/char input.
        while (heightCheck == 0) {
            system("cls");
            fflush(stdin);
            printf(BOLD_TEXT "What is your height in m: " DEFAULT);
            scanf(" %lf", &height);
            fflush(stdin);
            if (height <= 0 || height > 3) {
                printf(BOLD_SLOW_BLINK_RED_COLOUR "\nInvalid input.\nYour height must be between (0 to 3)m.\nPress enter to continue..." DEFAULT);
                fflush(stdin);
                getchar();
                fflush(stdin);
            } else {
                heightCheck = 1;
            }
        }

        bmi = bmiCalculator(weight, height);

        //prints out bmi value, as well as asks user if they would like to run the program again.
        printf(BOLD_TEXT "Your BMI value is %.1lf" DEFAULT, bmi);
        fflush(stdin);
        getchar();
        fflush(stdin);
        printf(BOLD_TEXT "\nWould you like to do a new calculation (Y/N): " DEFAULT);
        scanf(" %c", &yn);
        yn = tolower(yn);
        if (yn == 'n') {
            pass = 1;
            system("cls");
            printf(BOLD_TEXT "Have a good day!\nPress enter to leave." DEFAULT);
            fflush(stdin);
            getchar();
            fflush(stdin);
        } else {
            weightCheck = 0;
            heightCheck = 0;
            fflush(stdin);
        }

    } while (pass == 0);
    
    return 0;
} 