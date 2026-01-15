#include <stdio.h>

int main() {
    //double num;
    printf("Hello, World!\n");
    //scanf("%lf", &num);
    //printf("You entered: %lf\n", num);
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);
    printf("You entered: %d\n", num);
    getchar();
    printf("Press Enter to exit...");
    getchar();
    return 0;
}   