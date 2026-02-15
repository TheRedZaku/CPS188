/* Lab #5 Problem #2*/

#include <stdio.h>

void timeMoon(int speed, double *tPerigee, double *tApogee) {
        *tPerigee = 363104.0 / speed; //perigee
        *tApogee = 405696.0 / speed; //apogee
}

void timeMars(int speed, double *tPerigee, double *tApogee) {
    *tPerigee = 54600000.0 / speed; //perigee
    *tApogee = 401000000.0 / speed; //apogee
}

void timeVenus(int speed, double *tPerigee, double *tApogee) {
        *tPerigee = 38000000.0 / speed; //perigee
        *tApogee = 261000000.0 / speed; //apogee
}

//selecting a method of travel and the theoretical constant speed
void speedChoice(int *speed) {

    //speed is given in km/h
    int pass = 0, choice;

    do {
        printf("What method of travel would you like?\nSelect an option:\n1. By car (100km/h)\n2. By airplane (500km/h)\n3. By rocket (41000km/h)\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: //by car
                *speed  = 100;
                pass = 1;
            break;
            case 2: //by airplane
                *speed = 500;
                pass = 1;
            break;
            case 3: //by rocket
                *speed = 41000;
                pass = 1;
            break;
            default:
                printf("\033[1;6;31mNot an option. Please try again. \033[0m");
                fflush(stdin);
                getchar();
            break;
        }
    } while (pass != 1); 
}

int main(void) {

    int choice, speed, pass = 0;
    double tPerigee, tApogee;//all time is returned as hours

    do {
        printf("Space Travel Program\nSelect an option:");
        printf("\n1. Traveling to the Moon.\n2. Traveling to Mars.\n3. Traveling to Venus.\n4. Exit program.\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                speedChoice(&speed);
                timeMoon(speed, &tPerigee, &tApogee);
                printf("The minimum travel time is %.2lfhrs and the maximum travel time is %.2lfhrs.\nPress enter to return to the main menu.", tPerigee, tApogee);
                fflush(stdin);
                getchar();
            break;
            case 2:
                speedChoice(&speed);
                timeMars(speed, &tPerigee, &tApogee);
                printf("The minimum travel time is %.2lfhrs and the maximum travel time is %.2lfhrs.\nPress enter to return to the main menu.", tPerigee, tApogee);
                fflush(stdin);
                getchar();
            break;
            case 3:
                speedChoice(&speed);
                timeVenus(speed, &tPerigee, &tApogee);
                printf("The minimum travel time is %.2lfhrs and the maximum travel time is %.2lfhrs.\nPress enter to return to the main menu.", tPerigee, tApogee);
                fflush(stdin);
                getchar();
            break;
            case 4:
                pass = 1;
            break;
            default://prevents code from breaking from invalid input; acts as a catch all
                printf("\033[1;6;31mNot an option. Please try again. \033[0m");
                fflush(stdin);
                getchar();
            break;
        }
        
    } while (pass != 1);

}