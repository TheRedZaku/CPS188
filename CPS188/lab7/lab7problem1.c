/*Lab #7 Problem #1*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define GREEN "\033[32;1m"
#define RED "\033[31;1m"
#define BOLD "\033[1m"

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

    if ((int)strlen(before) == 0) {

        after[(int)strlen(after)] = '\0';//set the last value to the null character, and exit the function

    } else {

        after[(int)strlen(after)] = before[(int)strlen(before) - 1];//set the current highest index of the new array to the last character in the original array
        before[(int)strlen(before) - 1] = '\0'; //override the last value of the before array, so that the size decreases
        after[(int)strlen(after) + 1] = '\0'; //add back a null character in case
        reverse(before, after); //recursively calling the function again
    }

}

int main(void) {

    fflush(stdin);
    char input[100] = "\0", modifiedInput[100] = "\0", reversedInput[100] = "\0";
    int isPalindrome = 1;//updates to a 0, representing NOT, if not a palindrome

    printf(BOLD "Enter a word: ");

    fgets(input, 100, stdin); //input is the same as &input
    //printf("%s\n", input);

    clean(input, modifiedInput); //pointer addresses sent to function
    printf("\nYour input without punctuation, spaces or capitalization is: %s\n", modifiedInput);

    reversedInput[0] = '\0';
    reverse(modifiedInput, reversedInput);

    clean(input, modifiedInput);

    printf("The reverse of the given string is: %s\n", reversedInput);

    for (int index = 0; index < (int)strlen(modifiedInput); index++) {//checks if every single character in both the reverse and regular string are the same
        if (modifiedInput[index] != reversedInput[index]) {//if even one is different, it will break and update the check to 0
            isPalindrome = 0;
            break;
        }
    }

    switch (isPalindrome) {
        case 1:
            printf(GREEN "The string: %sis a palindrome.", input);
            break;
        default:
            printf(RED "The string: %sis NOT a palindrome.", input);
            break;
    }

    fflush(stdin);
    getchar();
    return 0;
}