/*Lab #4 Problem #1*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"

int factorial(int num) {

    int factValue = 1;

    for (int i = 1; i <= num; i++) {
        factValue *= i;
    }
    return factValue;
}

int main(void) {
    
    srand(time(NULL));

    int total, spaces = 34, leftSpacing = 0, randNum;
    //make a loop of 9
    //use 'n choose k' formuala from combinations
    /*let row be n
    and column be k*/
    for (int row = 0; row < 9; row++) {
        for (int column = 0; column <= row; column++) {
            total = factorial(row) / (factorial(column) * factorial(row - column));
            //printf("\033[1;6;31m""col: %d" "\033[0m", column)
            
            randNum = rand() % 4;
            switch (randNum) {
                case 0:
                    printf(RED);
                    break;
                case 1:
                    printf(YELLOW);
                    break;
                case 2:
                    printf(GREEN);
                    break;
                case 3:
                    printf(BLUE);
                    break;
            }
            /*if (column == 0) {
                switch (row) {
                    case 0:
                        printf("%34d", total);
                        break;
                    case 1:
                        printf("%30d", total);
                        break;
                    case 2:
                        printf("%26d", total);
                        break;
                    case 3:
                        printf("%22d", total);
                        break;
                    case 4:
                        printf("%18d", total);
                        break;
                    case 5:
                        printf("%14d", total);
                        break;
                    case 6:
                        printf("%10d", total);
                        break;
                    case 7:
                        printf("%6d", total);
                        break;
                    case 8:
                        printf("%2d", total);
                        break;
                }
            } else {
                printf("%8d", total);
            }*/
            
            if (column == 0) {
                leftSpacing = (spaces - (4*row));
                printf("%*d", leftSpacing, total);
            } else {
                printf("%8d", total);
            }
        }
        printf("\n");
    }
    getchar();
    return 0;
}