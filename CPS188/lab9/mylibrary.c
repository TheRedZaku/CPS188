#include "mylibrary.h"
#include <stdio.h>

double sumDiagonal(int SIZE, double num[][SIZE]) {

    double sum = 0;
    for (int i = 0; i < SIZE; i++) {
        sum += num[i][i];
    }

    return sum;

}

double sumAll(int SIZE, double num[][SIZE]) {
    
    double sum = 0;
    for (int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            sum += num[i][j];
        }
    }

    return sum;

}

double avgLast(int SIZE, double num[][SIZE] ) {

    double avg = 0;
    for (int i = 0; i < SIZE; i++) {
        avg += num[i][SIZE - 1];
    }
    avg = avg/SIZE;

    return avg;

}

double sumCorners(int SIZE, double num[][SIZE]) {

    double sum = 0;
    sum = num[0][0] + num[0][SIZE - 1] + num[SIZE - 1][0] + num[SIZE - 1][SIZE - 1];

    return sum;

}
