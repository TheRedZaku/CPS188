/*Lab #3 Problem #2*/

#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define BOLD_TEXT "\033[1m"
#define DEFAULT "\033[0m"

double bmiCalculator (double weight, double height) {

    double bmi;

    return bmi = weight / pow(height, 2);
}

int main(void) {

    double weight, height, bmi;

    printf(BOLD_TEXT "BMI Calculation Program\n" DEFAULT);
    
    //saving weight to a variable
    printf(BOLD_TEXT "What is your weight in kg: " DEFAULT);
    scanf(" %lf", &weight);
     
    //saving height to a variable
    printf(BOLD_TEXT "What is your height in m: " DEFAULT);
    scanf(" %lf", &height);

    bmi = bmiCalculator(weight, height);

    printf(BOLD_TEXT "Your BMI value is %.1lf. ", bmi);

    //checking for the BMI classification
    if (bmi < 18.5) {
        printf("You are underweight.\nPress enter to exit." DEFAULT);
    } else if (bmi >= 18.5 && bmi <= 24.9) { 
        printf("You are normal.\nPress enter to exit." DEFAULT);
    } else if (bmi > 24.9 && bmi <= 29.99) { 
        printf("You are overweight.\nPress enter to exit." DEFAULT);
    } else {
        printf("You are obese.\nPress enter to exit." DEFAULT);
    }

    //pausing the program for the user to read the output
    fflush(stdin);
    getchar();

    return 0;
} 