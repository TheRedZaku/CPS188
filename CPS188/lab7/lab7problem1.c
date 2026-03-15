/*Lab #7 Problem #1*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define GREEN "\033[32;1m"
#define RED "\033[31;1m"
#define BOLD "\033[1m"

void clean(char before[], char after[]) {

    int modifiedIndex = 0;

    for (int i = 0; i < strlen(before); i++) {//runs through the array length and just skips anything that isn't a lowercase alpha character
        if (isalnum(before[i])) {
            after[modifiedIndex] = tolower(before[i]);
            modifiedIndex++;
        }
    }
}

void reverse(char before[], char after[]) {

    if (strlen(before) == 0) {

        after[strlen(after)] = '\0';//set the last value to the null character, and exit the function

    } else {

        after[strlen(after)] = before[strlen(before) - 1];//set the current highest index of the new array to the last character in the original array
        before[strlen(before) - 1] = '\0'; //override the last value of the before array, so that the size decreases
        after[strlen(after) + 1] = '\0'; //add back a null character in case
        reverse(before, after); //recursively calling the function again
    }

}

int main(void) {

    fflush(stdin);
    char input[100] = "\0", modifiedInput[100] = "\0", reversedInput[100] = "\0";

    printf(BOLD "Enter a word: ");

    fgets(input, 100, stdin); //input is the same as &input
    //printf("%s\n", input);

    clean(input, modifiedInput); //pointer addresses sent to function
    printf("\nYour input without punctuation, spaces or capitalization is: %s\n", modifiedInput);

    reversedInput[0] = '\0'; //ensures that the reversedInput starts out empty
    reverse(modifiedInput, reversedInput);

    clean(input, modifiedInput); // have to reclean the modifiedInput because it gets destroyed in the process of making the reversedInput

    printf("The reverse of the given string is: %s\n", reversedInput);

    switch (strncmp(modifiedInput, reversedInput, strlen(modifiedInput))) {
        case 0: //0 case proves it is identical; any other case is irrelevant
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