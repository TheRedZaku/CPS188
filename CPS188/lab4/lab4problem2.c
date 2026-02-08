
#include <stdio.h>

int main(void) {

    FILE *data;
    int employeeNum = 0, shifts = 0;
    double baseWage = 0, hours = 0, totalHours = 0, grossPay;

    data = fopen ("CTextFiles\\workerdata.txt", "r");

    printf("---------------ID---------------Total Hours---------------Gross Pay---------------\n");
    
    if(data != NULL) {
        //careful with feof; validates if the previous input had no error, not the next one, so may print extra for no reason
        while(!(feof(data))) {
            employeeNum = 0, shifts = 0, totalHours = 0, baseWage = 0;

            fscanf(data, "%d %d %lf", &employeeNum, &shifts, &baseWage);

            for (int i = 0; i < shifts; i++) {
                fscanf(data, "%lf", &hours);
                totalHours += hours;
            }
            if (totalHours <= 15) {
                grossPay = totalHours*baseWage;
            } else if (totalHours > 15 && totalHours <= 25) {
                grossPay = totalHours*baseWage*1.05;
            } else {
                grossPay = totalHours*baseWage*1.10;
            }
            
            printf("%19.0d %20.2lf %24.2lf\n", employeeNum, totalHours, grossPay);
        }

        fclose(data);

    } else {
        perror("cannot read from file.");
        getchar();  
    }

    getchar();
    return 0;
}