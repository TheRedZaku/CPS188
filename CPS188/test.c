#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int monkeys(int a) {
    srand(time(NULL));
    return a * rand() + a++;
}

int main(void) {
    //double num;
    printf("Hello, World!\n");
    //scanf("%lf", &num);
    //printf("You entered: %lf\n", num);
    int num;
    do {
        printf("Enter an integer: ");
        scanf("%d", &num);
        if (num != 67) {
            printf("That's not 67.\n");
        }
    } while (num != 67);
    // a while loop that repeats until the number 67 is entered
    printf("yay!\n");
    printf("you have %d monkeys.", monkeys(num));
    getchar();
    printf("Press Enter to exit...");
    getchar();
    return 0;
}   

