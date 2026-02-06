/*LAB #3 Problem #4*/

#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>

int main(void) {

    int cardValue, cardSuit, pass = 0;
    char cardSymbol, yn;

    srand(time(NULL));
    
    //2660 spade
    //2665 heart
    //2663 club
    //2666 diamond

    //returns a card value from 1 to 13
    //not the most random possible value ever, but it works for our purposes
    printf("Random Card Picker");
    fflush(stdin);
    getchar();
    
    cardValue = rand() % 13 + 1;
    cardSuit = rand() % 4 + 1;
    
    //case 1, 11, 12, and 13 return the card as a symbol A,J,Q,K
    switch (cardValue) {
        case 1:
            cardSymbol = 'A';
            printf("\nYour card is the %c of ", cardSymbol);
            break;
        case 11:
            cardSymbol = 'J';
            printf("\nYour card is the %c of ", cardSymbol);
            break;
        case 12:
            cardSymbol = 'Q';
            printf("\nYour card is the %c of ", cardSymbol);
            break;
        case 13:
            cardSymbol = 'K';
            printf("\nYour card is the %c of ", cardSymbol);
            break;
        default:
            //returns the card as a number
            printf("\nYour card is the %d of ", cardValue);
            break;
    }
    
    //sets the suit to be displayed, based on cardSuit
    switch (cardSuit) {
        case 1: 
            printf("\u2660\nPress enter to exit.");
            break;
        case 2:
            printf("\u2665\nPress enter to exit.");
            break;
        case 3:
            printf("\u2663\nPress enter to exit.");
            break;
        case 4:
            printf("\u2666\nPress enter to exit.");
            break;
    }

    fflush(stdin);
    getchar();

    return 0;
}
