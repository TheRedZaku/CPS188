/* Lab #7 Problem #2*/

#include <stdio.h>

#define c 3e8 //speed of light m/s
#define h 6.626e-34 //Planck constant J-s
#define k 1.38e-23 //Boltzmann constant J/K

int main(void) {

    FILE *in;
    FILE *out

    in = fopen ("CTextFiles\\blackBodyRadiation.dat", "r");
    out = fopen ("CTextFiles\\blackBodyPlot.dat", "w");

    

    fprintf(out, "\n#Lab #7 Problem #2\n#\n# Temp(K) wavelength(μm) R");

    while(!feof(in)) {





    }


    return 0;
}