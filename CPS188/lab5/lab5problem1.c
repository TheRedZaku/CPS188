/* Lab #5 Problem #1 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calculate (int num1, int num2, double *avg, double *sum, double *absValue, double *squareRoot) {

    *sum = pow(num1, 2) + pow(num2 , 2);
    *avg = (num1 + num2) / 2.0;
    *absValue = fabs(pow(num1 - num2, 2));
    *squareRoot = sqrt(*sum);

}

int main (void) {

    int num1, num2;
    double avg, sum, absValue, squareRoot;

    printf("Funky Number Program\nPlease input a number: ");
    scanf("%d", &num1);
    printf("\ninput a second number: ");
    scanf("%d", &num2);
    calculate(num1, num2, &avg, &sum, &absValue, &squareRoot);
    printf("The average of the two numbers is: %.3lf\nThe sum of the squares of the two numbers is: %.3lf\nThe absolute value of the square of the difference between the two numbers is: %.3lf\nThe square root of the sum of the squares of the two numbers is: %.3lf", avg, sum, absValue, squareRoot);
    fflush(stdin);
    getchar();
    return 0;
}