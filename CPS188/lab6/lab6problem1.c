/* Lab #6 Problem #1*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void *num1, const void *num2) {
    return((*(double*)num1 > *(double*)num2) - (*(double*)num1 < *(double*)num2));
}

int main(void) {

    FILE *numbers;
    numbers = fopen("CTextFiles\\numbers.txt", "r");//My files are placed inside a folder in my IDE; hence the CTextFiles

    int arraySize, dataSet = 1;
    double xLow = 0, xHigh = 0, min, max;
    double arrX[20];
    double normArrX[20];

    printf("Original Sorted Array |||| Normalized Sorted Array\n");

    if (numbers != NULL) {
        //printf("working, probably...");

        while(!(feof(numbers))) {
            
            printf("Data Set #%d\n", dataSet);
            dataSet++;//spaces out the arrays, and also tells you the set #
            
            fscanf(numbers, "%d %lf %lf", &arraySize, &min, &max);
            
            for (int loop = 0; loop < arraySize; loop++) {//loop through and store numbers from text file into the array
                fscanf(numbers, "%lf", &arrX[loop]);
            }
            qsort(arrX, arraySize, sizeof(double), compare);//only sort up to the scanned numbers; rest are garbage values

            xLow = arrX[0];//since the array is sorted, the lowest value is at index 0
            xHigh = arrX[arraySize-1];//since array starts at 0, the highest bound would be the arraySize - 1
            
            if (xHigh - xLow != 0) {//prevents 0/0 division
                for(int i = 0; i < arraySize; i++) {//changes the bounds of the array using the given equation
                    normArrX[i] = min + (arrX[i] - xLow) * (max - min) / (xHigh - xLow);
                    printf("%21.2lf %28.2lf\n", arrX[i], normArrX[i]);
                
                }
            }

        }

    fclose(numbers);
    
    } else {
        printf("File Error.");//Prevent file reading error
    }

    fflush(stdin);
    getchar();
    return 0;
}