/*LAB #3 Problem #3*/

#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define BOLD_TEXT "\033[1m"
#define DEFAULT "\033[0m"

int main(void) {
    
    int grade;
    double quizAvg, quiz1, quiz10, quiz, midterm, final, total;
    //where total is the sum of the quizzes, and quizAvg is the actual average of the 10 (9) quizzes

    printf(BOLD_TEXT "Overall Course Grade Calculator\n" DEFAULT);

    //storing and tracking values for each quiz
    printf(BOLD_TEXT "What is your grade for quiz 1: " DEFAULT);
    scanf("%lf", &quiz1);
    total += quiz1;
    printf(BOLD_TEXT "What is your grade for quiz 2: " DEFAULT);
    scanf("%lf", &quiz);
    total += quiz;
    printf(BOLD_TEXT "What is your grade for quiz 3: " DEFAULT);
    scanf("%lf", &quiz);
    total += quiz;
    printf(BOLD_TEXT "What is your grade for quiz 4: " DEFAULT);
    scanf("%lf", &quiz);
    total += quiz;
    printf(BOLD_TEXT "What is your grade for quiz 5: " DEFAULT);
    scanf("%lf", &quiz);
    total += quiz;
    printf(BOLD_TEXT "What is your grade for quiz 6: " DEFAULT);
    scanf("%lf", &quiz);
    total += quiz;
    printf(BOLD_TEXT "What is your grade for quiz 7: " DEFAULT);
    scanf("%lf", &quiz);
    total += quiz;
    printf(BOLD_TEXT "What is your grade for quiz 8: " DEFAULT);
    scanf("%lf", &quiz);
    total += quiz;
    printf(BOLD_TEXT "What is your grade for quiz 9: " DEFAULT);
    scanf("%lf", &quiz);
    total += quiz;
    printf(BOLD_TEXT "What is your grade for quiz 10: " DEFAULT);
    scanf("%lf", &quiz10);
    total += quiz10;

    //removing the first or last entry, depending on which one is smaller
    if (quiz1 <= quiz10) {
        total -= quiz1;
    } else {
        total -= quiz10;
    }

    quizAvg = (total / 9) * 0.25; //finding the weighted average for the quizzes

    printf(BOLD_TEXT "What is your midterm exam grade: " DEFAULT);
    scanf("%lf", &midterm);
            
    printf(BOLD_TEXT "What is your final exam grade: " DEFAULT);
    scanf("%lf", &final);

    //checking if midterm or final grade is higher, and distributing the weighting as appropriate
    if (midterm >= final) {
        midterm *= 0.35;
        final *= 0.40;
    } else {
        midterm *= 0.25;
        final *= 0.50;
    }

    //reusing total to sum the weighted values
    total = quizAvg + midterm + final;
    grade = total;
    printf(BOLD_TEXT "Your final grade for the course is %d.\nPress enter to exit." DEFAULT, grade);

    fflush(stdin);
    getchar();

    return 0;
}
