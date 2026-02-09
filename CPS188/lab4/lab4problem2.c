/*Lab #4 Problem #2*/

#include <stdio.h>

int main(void) {

    FILE *data;
    int employeeNum = 0, shifts = 0;
    double baseWage = 0, hours = 0, totalHours = 0, grossPay;

    //relative path will have to be changed depending on where the program is opened.
    data = fopen ("CTextFiles\\workerdata.txt", "r");

    printf("---------------ID---------------Total Hours---------------Gross Pay---------------\n");
    
    if(data != NULL) {
        //careful with feof; validates if the previous input had no error, not the next one, so may print extra for no reason
        while(!(feof(data))) {
            employeeNum = 0, shifts = 0, totalHours = 0, baseWage = 0;

            fscanf(data, "%d %d %lf", &employeeNum, &shifts, &baseWage);

            //iterate through the number of hours worked and sum them into the total hours worked
            for (int i = 0; i < shifts; i++) {
                fscanf(data, "%lf", &hours);
                totalHours += hours;
            }

            //paying different premiums depending on the total number of hours worked
            if (totalHours <= 15) {
                grossPay = totalHours*baseWage;
            } else if (totalHours > 15 && totalHours <= 25) {
                grossPay = totalHours*baseWage*1.05;
            } else {
                grossPay = totalHours*baseWage*1.10;
            }
            
            //printing the current employee's information to the console
            printf("%18.0d %20.2lf %25.2lf\n", employeeNum, totalHours, grossPay);
        }

        fclose(data);

    } else {
        //prevent program from crashing by stopping on bad execution
        perror("cannot read from file.");
        getchar();  
    }

    getchar();
    return 0;
}