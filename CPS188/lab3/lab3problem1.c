/*LAB #3 - Problem #1*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

#define BOLD_SLOW_BLINK_RED_COLOUR "\033[1;6;31m"
#define DEFAULT_COLOUR "\033[0m"
#define BOLD_TEXT "\033[1m"

//pausing the program output for the user to read the screen
void hold(void) {
	fflush(stdin);
	getchar();
}

//function for finding the training heart rate, based on the equation in the document
int trainingHeartRate(char gender, int age, int rhr, double inten) {
	double mhr, thr;
	if (gender == tolower('M')) {
		mhr = 203.7 / (1 + exp(0.033 * (age - 104.3)));
	} else {
		mhr = 190.2 / (1 + exp(0.0453 * (age - 107.5)));
	}
	thr = ((mhr - rhr) * inten) + rhr;
	return thr;
}

int main(void) {
	
	char gender, fitLvlChar, yn;
	int rhr, age, thr;
	double inten; //fitness level as a double
	int pass = 0, genderCheck = 0, ageCheck = 0, heartRateCheck = 0, fitLvlCheck = 0;
	
	do {
		system("cls");
		printf(BOLD_TEXT "Training Heart Rate Program\nPress enter to continue...\n" DEFAULT_COLOUR);
		hold();
        //checking for acceptable input for gender (must be M/m or F/f)
		while (genderCheck == 0) {
			system("cls");
			printf(BOLD_TEXT "What is your gender (M/F): " DEFAULT_COLOUR);
			scanf(" %c", &gender);
			gender = tolower(gender);
			if (gender == 'm' || gender == 'f') {
				genderCheck = 1;
			} else {
				printf(BOLD_SLOW_BLINK_RED_COLOUR "\nInvalid input.\nAssume that the only input can be Male (M/m) or Female (F/f).\nEnter a key to continue...\n" DEFAULT_COLOUR);
				hold();
			}
		}
		
		//checking for acceptible age input (must be a reasonable age like 0 - 100); technically people live beyond 100, but it is a design choice.
		while (ageCheck == 0) {
			system("cls");
			printf(BOLD_TEXT"What is your age (0-100): " DEFAULT_COLOUR);
			scanf(" %i", &age);
			if (age > 0 && age <= 100) {
                ageCheck = 1;   
            } else {
				printf(BOLD_SLOW_BLINK_RED_COLOUR "\nInvalid input.\nAge must be between 0 and 100 (Older people are probably not relevant).\nEnter a key to continue...\n" DEFAULT_COLOUR);
				hold();
			}
		}

		while (heartRateCheck == 0) {
			system("cls");
			printf(BOLD_TEXT "What is your resting heart rate (25 - 200) in bpm: " DEFAULT_COLOUR);
			scanf(" %i", &rhr);
			if (rhr >= 25 && rhr <= 200) {
				heartRateCheck = 1;
			} else {
				printf(BOLD_SLOW_BLINK_RED_COLOUR "\nInvalid input.\nResting heart rate must be between 25 and 200 bpm.\nEnter a key to continue...\n" DEFAULT_COLOUR);
				hold();
			}
		}

		//checking for a valid fitness level input (must be L/l, M/m, or H/h)
		while (fitLvlCheck == 0) {
			system("cls");
			printf(BOLD_TEXT "What is your fitness level (L/M/H): " DEFAULT_COLOUR);
			scanf(" %c", &fitLvlChar);
			fitLvlChar = tolower(fitLvlChar);
			if (fitLvlChar == 'l' || fitLvlChar == 'm' || fitLvlChar == 'h') {
				fitLvlCheck = 1;
				if (fitLvlChar == 'l') {
					inten = 0.5;
				} else if (fitLvlChar == 'm') {
					inten = 0.65;
				} else {
					inten = 0.8;
				}
			} else {
				printf(BOLD_SLOW_BLINK_RED_COLOUR "\nInvalid input.\nValid options are Low (L/l), Medium (M/m), or High (H/h).\nEnter a key to continue...\n" DEFAULT_COLOUR);
				hold();
			}

		}

		system("cls");
		thr = trainingHeartRate(gender, age, rhr, inten);
		printf(BOLD_TEXT "Your training heart rate is %ibpm." DEFAULT_COLOUR, thr);
		hold();
	
		//check if loop should be exited after a calculation is completed.
		printf(BOLD_TEXT "\nWould you like to calculate another training heart rate? (Y/N): " DEFAULT_COLOUR);
		scanf(" %c", &yn);
		system("cls");
		yn = tolower(yn);
		if (yn == 'n') {
			pass = 1;
			printf(BOLD_TEXT "Have a good day!\nPress enter to leave." DEFAULT_COLOUR);
			hold();
		} else {
			genderCheck = 0;
			ageCheck = 0;
			heartRateCheck = 0;
			fitLvlCheck = 0;
			fflush(stdin);
		}

	} while (pass == 0);
	return 0;
}