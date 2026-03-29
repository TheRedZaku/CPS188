#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int monkeys(int a) {
    srand(time(NULL));
    return a * rand() + a++;
}

void nish(int *x, int *y) {
    int aaa = 3;
    *x = aaa - 2 + *y;
    *y += *x;
}

int main(void) {

    FILE *in;
    srand(time(NULL));

    in = fopen("CTextFiles\\monkeymonkey.txt", "r");

    int n[100];//buffer space
    int i = 0, temp = 0, k = 4;

    while (!feof(in)) {
        fscanf(in, "%d", &temp);
        if (temp % 2 == 0) {// == 1 if finding odd numbers
            n[i] = temp;
            i++;
        }
    }

    for (int j = 0; j < i; j++) {
        printf("%d ", n[j]);
    }
    
    nish(&n[0], &k);
    printf("\n%d %d ", n[0], k);


    fflush(stdin);
    getchar();
    return 0;
}

/*int main(void) {
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
*/
