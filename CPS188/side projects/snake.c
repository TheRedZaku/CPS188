

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <Windows.h>

#define gameSize 17 // 2 on each side will just be used to create a border

void move(int dirInt, int map[gameSize][gameSize], int row, int col) {
    //recursive function would actually be so much more difficult

    for (row = 0; row < gameSize; row++) {
        for (col = 0; col < gameSize; col++) {

            if (map[row][col] == 1) {
                /*switch(dirInt) {
                    case 0: //going up
                        map[row - 1][col] = 1;
                        map[row][col] = 0;
                    break;
                    case 1: //going left
                        map[row][col - 1] = 1;
                        map[row][col] = 0;
                    break;
                    case 2: //down
                        map[row + 1][col] = 1;
                        map[row][col] = 0;
                    break;
                    case 3: //right
                        map[row][col + 1] = 1;
                        map[row][col] = 0;
                    break;
                    
                }*/

                if (dirInt = 0) {
                    map[row - 1][col] = 1;
                    map[row][col] = 0;

                } else if (dirInt = 1) {
                    map[row][col - 1] = 1;
                    map[row][col] = 0;

                } else if (dirInt = 2) {
                    map[row + 1][col] = 1;
                    map[row][col] = 0;

                } else if (dirInt = 3) {
                    map[row][col + 1] = 1;
                    map[row][col] = 0;

                }

                
            }

        }
    }

}

void display(int map[gameSize][gameSize]) {
    int row = 0, col = 0;

    printf("\e[1;1H\e[2J"); //clears the console

    for (row = 0; row < gameSize; row++) {
        for (col = 0; col < gameSize; col++) {
            printf("%2d ", map[row][col]);
        }
        printf("\n");
    }
}

int main(void) {


    int row = 0, col = 0, gameOver = 0, snakeLength = 1, dirInt;
    char dir = 'w'; //direction
    int map[gameSize][gameSize]; //creates a 17 x 17 grid
    //where map is the grid
    
    //initiating the default game board
    for (int row = 0; row < gameSize; row++) {
        for (int col = 0; col < gameSize; col++) {

            if (row == 8 && col == 8) {
                map[row][col] = 1;
            } else if (row != 0 && row != 16 && col != 0 && col != 16) {
                map[row][col] = 0;
            } else {
                map[row][col] = -1;
            }
        }
    }
    display(map);
    Sleep(100); //i know this is not very portable but it doesn't need to be
    while (gameOver != 1) {
        
        display(map);
        scanf("%c", &dir);
        row = 0, col = 0;
        tolower(dir);
        switch (dir) {
            case 'w':
                dirInt = 0;
            break;
            case 'a':
                dirInt = 1;
            break;
            case 's':
                dirInt = 2;
            break;
            case 'd':
                dirInt = 3;
            break;
        }
        Sleep(100);
            for (row = 0; row < gameSize; row++) {
                for (col = 0; col < gameSize; col++) {
                    if (dir == 'w' && map[row][col] == 1) {
                        map[row - 1][col] = 1;
                        map[row][col] = 0;

                    } else if (dir == 'a' && map[row][col] == 1) {
                        map[row][col - 1] = 1;
                        map[row][col] = 0;

                    } else if (dir == 's' && map[row][col] == 1) {
                        map[row + 1][col] = 1;
                        map[row][col] = 0;

                    } else if (dis == 'd' && map[row][col] == 1) {
                        map[row][col + 1] = 1;
                        map[row][col] = 0;

                    }
        
                }    
            }
        //move(dirInt, map, row, col);

    }


    //for now, I don't really care to actually display any custom symbols
    fflush(stdin);
    getchar();
    return 0;
}