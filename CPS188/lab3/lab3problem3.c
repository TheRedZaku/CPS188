/*LAB #3 Problem #3*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define BOLD_TEXT "\033[1m"
#define DEFAULT "\033[0m"
#define BOLD_SLOW_BLINK_RED_COLOUR "\033[1;6;31m"

//function for allowing the reader to control the speed of text from the console
void hold(void) {
    fflush(stdin);
    getchar();
}

//function for inputs that are not allowed. In this case it is repetitive, and so a function is used.
void badInput(void) {
    printf(BOLD_SLOW_BLINK_RED_COLOUR "\nInvalid input. Grade entered must be between 0 to 100. Press enter to continue..." DEFAULT);
    fflush(stdin);
    getchar();
}

int main(void) {
    
    char yn;
    int quiz1, quiz10, quiz, midterm, final, total, pass = 0, check = 0;
    double quizAvg;
    //where total is the sum of the quizzes, and quizAvg is the actual average of the 10 quizzes

    do {
        system("cls");
        printf(BOLD_TEXT "Overall Course Grade Calculator" DEFAULT);
        hold();

        for (int i = 1; i <= 10; i++) {
            check = 0;
            if (i == 1) {
                while (check == 0) {
                    system("cls");
                    printf(BOLD_TEXT "What is your grade for quiz %d: " DEFAULT, i);
                    scanf("%d", &quiz1);
                    if (quiz1 < 0 || quiz1 > 100) {
                        badInput();
                    } else{ 
                        total += quiz1;
                        check = 1;
                    }
                }
            } else if (i == 10) {
                while (check == 0) {
                    system("cls");
                    printf(BOLD_TEXT "What is your grade for quiz %d: " DEFAULT, i);
                    scanf("%d", &quiz10);
                    if (quiz10 < 0 || quiz10 > 100) {
                        badInput();
                    } else {
                        total += quiz10;
                        check = 1; 
                    }
                }    
            } else {
                while (check == 0) {
                    system("cls");
                    printf(BOLD_TEXT "What is your grade for quiz %d: " DEFAULT, i);
                    scanf("%d", &quiz);
                    if (quiz < 0 || quiz > 100) {
                        badInput();
                    } else {
                        total += quiz;
                        check = 1; 
                    }
                }
                
            }
        }

        //removing the first or last entry, depending on which one is smaller
        if (quiz1 <= quiz10) {
            total -= quiz1;
        } else {
            total -= quiz10;
        }

        quizAvg = (total / 9) * 0.25; //finding the weighted average for the quizzes

        check = 0;
        while (check == 0) {
            system("cls");
            printf(BOLD_TEXT "What is your midterm exam grade: " DEFAULT);
            scanf("%d", &midterm);
            if (midterm < 0 || midterm > 100) {
                badInput();
            } else {
                check = 1;
            }
        }

        check = 0;
        while (check == 0) {
            system("cls");
            printf(BOLD_TEXT "What is your final exam grade: " DEFAULT);
            scanf("%d", &final);
            if (final < 0 || final > 100) {
                badInput();
            } else {
                check = 1;
            }
        }

        if (midterm >= final) {
            midterm *= 0.35;
            final *= 0.40;
        } else {
            midterm *= 0.25;
            final *= 0.50;
        }
        system("cls");
        total = quizAvg + midterm + final;
        printf(BOLD_TEXT "Your final grade for the course is %d.", total);
        //the current issue is that it is truncating, instead of rounding.
        hold();

        printf(BOLD_TEXT "Would you like to calculate a new average (Y/N)? " DEFAULT);
        scanf(" %c", &yn);
        yn = tolower(yn);
        if (yn == 'n') {
            printf(BOLD_TEXT "Have a great day! Press enter to leave." DEFAULT);
            pass = 1;
            hold();
        }
    } while (pass == 0);

    return 0;
}
