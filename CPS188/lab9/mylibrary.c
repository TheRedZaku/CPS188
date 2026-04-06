#include "mylibrary.h"
#include <stdio.h>

void sumDiagonal(int SIZE, double num[][SIZE], FILE *fptr) {

    double sum = 0;
    for (int i = 0; i < SIZE; i++) {
        sum += num[i][i];
    }

    fwrite(&sum, sizeof(double), 1, fptr);

}

void sumAll(int SIZE, double num[][SIZE], FILE *fptr) {
    
    double sum = 0;
    for (int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            sum += num[i][j];
        }
    }

    fwrite(&sum, sizeof(double), 1, fptr);

}

void avgLast(int SIZE, double num[][SIZE], FILE *fptr) {

    double avg = 0;
    for (int i = 0; i < SIZE; i++) {
        avg += num[i][SIZE - 1];
    }
    avg = avg/SIZE;

    fwrite(&avg, sizeof(double), 1, fptr);

}

void sumCorners(int SIZE, double num[][SIZE], FILE *fptr) {

    double sum = 0;
    sum = num[0][0] + num[0][SIZE - 1] + num[SIZE - 1][0] + num[SIZE - 1][SIZE - 1];

    fwrite(&sum, sizeof(double), 1, fptr);

}
