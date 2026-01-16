#include <stdio.h>

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
    printf("yay!\n");
    getchar();
    printf("Press Enter to exit...");
    getchar();
    return 0;
}   