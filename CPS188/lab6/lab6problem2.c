/*Lab #6 Problem #2*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//repetitive comparison functions
int compareFloatAscending(const void *num1, const void *num2) {
    return ((*(float*)num1 > *(float*)num2) - (*(float*)num1 < *(float*)num2));
}

int compareIntAscending(const void *num1, const void *num2) {
    return ((*(int*)num1 > *(int*)num2) - (*(int*)num1 < *(int*)num2));
}

int compareFloatDescending(const void *num1, const void *num2) {
    return ((*(float*)num1 < *(float*)num2) - (*(float*)num1 > *(float*)num2));
}

int compareIntDescending(const void *num1, const void *num2) {
    return ((*(int*)num1 < *(int*)num2) - (*(int*)num1 > *(int*)num2));
}

int main (void) {
    int arrInt[100];//set as 100 to buffer values
    float arrFloat[100];

    char testValue[100];
    int intCounter = 0, floatCounter = 0, display = 0;
    char decimal = '.';//program looks for decimal

    FILE *numbers;
    numbers = fopen("CTextFiles\\lab6problem2.txt", "r");
    
    while(!(feof(numbers))) {

        fscanf(numbers, "%s", &testValue);
        if (strchr(testValue, decimal) == NULL) {//if string contains NO decimal, it is an integer
            arrInt[intCounter] = atoi(testValue);
            intCounter++; //counts the number of values currently storing input for that array
        } else { //otherwise, the program considers the value as a double
            arrFloat[floatCounter] = atof(testValue);
            floatCounter++; //same as intCounter
        }
    }
    fclose(numbers);

    //displaying all the data values
    printf("Text file contains: ");
    for (display = 0; display < intCounter; display++) {
        printf("%d ", arrInt[display]);
    }
    for (display = 0; display < floatCounter; display++) {
        printf("%.2lf ", arrFloat[display]);
    }

    //compact segment to qsort depending on the requirement (int/float, asc/desc)
    printf("\nInteger array sorted in ascending order: ");
    qsort(arrInt, intCounter, sizeof(int), compareIntAscending);
    for (display = 0; display < intCounter; display++) {
        printf("%d ", arrInt[display]);
    }

    printf("\nFloat array sorted in ascending order: ");
    qsort(arrFloat, floatCounter, sizeof(float), compareFloatAscending);
    for (display = 0; display < floatCounter; display++) {
        printf("%.2lf ", arrFloat[display]);
    }

    printf("\nInteger array sorted in descending order: ");
    qsort(arrInt, intCounter, sizeof(int), compareIntDescending);
    for (display = 0; display < intCounter; display++) {
        printf("%d ", arrInt[display]);
    }

    printf("\nFloat array sorted in descending order: ");
    qsort(arrFloat, floatCounter, sizeof(float), compareFloatDescending);
    for (display = 0; display < floatCounter; display++) {
        printf("%.2lf ", arrFloat[display]);
    }

    fflush(stdin);
    getchar();
    return 0;
}