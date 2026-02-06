/*LAB #3 - Problem #1*/

#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define DEFAULT_COLOUR "\033[0m"
#define BOLD_TEXT "\033[1m"

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
	
	char gender, fitLvlChar;
	int rhr, age, thr;
	double inten; //fitness level as a double	
	
	printf(BOLD_TEXT "Training Heart Rate Program\n" DEFAULT_COLOUR);
	printf(BOLD_TEXT "What is your gender (M/F): " DEFAULT_COLOUR);
	scanf(" %c", &gender);
	gender = tolower(gender);

	printf(BOLD_TEXT"What is your age (0-100): " DEFAULT_COLOUR);
	scanf(" %i", &age);
	
	printf(BOLD_TEXT "What is your resting heart rate (25 - 200) in bpm: " DEFAULT_COLOUR);
	scanf(" %i", &rhr);

	printf(BOLD_TEXT "What is your fitness level (L/M/H): " DEFAULT_COLOUR);
	scanf(" %c", &fitLvlChar);
	
	//determining the fitness level by checking the input between (L/l), (M/m), or (H/h)
	fitLvlChar = tolower(fitLvlChar);
	if (fitLvlChar == 'l') {
		inten = 0.5;
	} else if (fitLvlChar == 'm') {
		inten = 0.65;
	} else {
		inten = 0.8;
	}

	//calculating through a function, as it returns the value as an integer
	thr = trainingHeartRate(gender, age, rhr, inten);
	printf(BOLD_TEXT "Your training heart rate is %ibpm.\nPress enter to exit." DEFAULT_COLOUR, thr);
	fflush(stdin);
	getchar();

	return 0;
}