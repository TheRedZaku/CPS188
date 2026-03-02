/* Lab #6 Problem #1 */

#include <stdio.h>
#include <stdlib.h>

int compare(const void *num1, const void *num2) {
    return(*(double*)num1 - *(double*)num2);
}

int main(void) {

    FILE *numbers;
    numbers = fopen("CTextFiles\\numbers.txt", "r");

    int arraySize, min, max;
    double xLow, xHigh;
    double arrX[100];

    while(!(feof(numbers))) {

        fscanf(numbers, "%d %d %d", &arraySize, &min, &max);
        
        arrX[arraySize];//initialize after you get the array size, so you don't need additional buffer space/don't need an array that is bigger than the data set.
        for (int loop = 0; loop < arraySize; loop++) {
            fscanf(numbers, "%lf", &arrX[loop]);
        }
        qsort(arrX, arraySize, sizeof(arrX[0]), compare);

        fclose(numbers);
    }

    xLow = arrX[0];
    xHigh = arrX[arraySize-1];
    double normArrX[arraySize];

    for(int i = 0; i < arraySize; i++) {
        normArrX[i] = min + (arrX[i] - xLow) * (max - min) / (xHigh - xLow);
        printf("%lf", arrX[i]);
    }

    if (numbers != NULL) {

    } else {
        printf("File Error.");
    }

    fflush(stdin);
    getchar();
    return 0;
}