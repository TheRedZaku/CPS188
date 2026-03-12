/*Lab #7 Problem #1*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void clean(char before[], char after[]) {

    int modifiedIndex = 0;

    for (int i = 0; i < strlen(before); i++) {
        if (isalpha(before[i])) {
            after[modifiedIndex] = tolower(before[i]);
            modifiedIndex++;
        }
    }
}

void reverse(char before[], char after[]) {


    if ((int)strlen(after) > (int)strlen(before)) {
        after[0] = before[(int)strlen(before) - 1];
    } else {
        after[0] = before[(int)strlen(before) - 1]; 
    }

}

int main(void) {

    fflush(stdin);
    char input[100], modifiedInput[100], reversedInput[100];
    int isPalindrome = 0;

    printf("Enter a word: ");
    fgets(input, 100, stdin); //input is the same as &input
    printf("%s\n", input);
    clean(input, modifiedInput); //pointer addresses sent to function
    printf("%s", modifiedInput);
    reverse(modifiedInput, reversedInput);

    fflush(stdin);
    getchar();
    return 0;
}