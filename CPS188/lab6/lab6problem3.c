/*Lab #6 Problem #3*/

#include <stdio.h>

#define STACK_EMPTY '0'
#define STACK_SIZE 20

void push(char stack[],    /* input/output - the stack */
     char item,       /* input - data being pushed onto the stack */
     int  *top,       /* input/output - pointer to top of stack */
     int  max_size)   /* input - maximum size of stack */
{
     if (*top < max_size-1) { //Checks where the current index is, and compares it to the max index of the stack. If it is less than the max index, it will add the item to the next available index
         ++(*top);
         stack[*top] = item;
     }
}

char pop (char stack[],    /* input/output - the stack */
    int *top)        /* input/output - pointer to top of stack */
{
    char item;       /* value popped off the stack */

    if (*top >= 0) { // 0 represents unfilled data values, so it looks for a non empty value.
        item = stack[*top]; //store the top value to be removed.
        --(*top);
    } else {
        item = STACK_EMPTY;
    }

    return (item); //return it
}

int main (void) {

    char s[STACK_SIZE];
    int s_top = -1; // stack is empty

    for (int i = 0; i < 5; i++) {//Alphabet is convenient for filling the array
        push(s, i+65, &s_top, STACK_SIZE); //65 is the letter 'A'
    }

    printf("The current stack is: ");
    for (int k = 0; k < s_top + 1; k++) {
        printf("%c ", s[k]);
    }

    for (int j = 0; j < 5; j++) {
        pop(s, &s_top);
    }

    printf("\nThe current stack is: ");
    for (int k = 0; k < s_top + 1; k++) {
        printf("%c ", s[k]);
    }

    getchar();
    return (0);
}