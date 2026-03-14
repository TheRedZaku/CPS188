/* Lab #7 Problem #2*/

#define _USE_MATH_DEFINES // potentially undefined constant pi
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 100
#define SAMPLE 300

int main(void) {

    FILE *data;
    FILE *plot;

    /*constants*/
    const double c = 3e8; //speed of light m/s
    const double h = 6.626e-34; //Planck constant J-s
    const double k = 1.38e-23; //Boltzmann constant J/K

    /*values for x*/
    const double MAX_X = 3e-6;
    const double MIN_X = 0.1e-6;
    const double X_INCREMENT = (2.9e-6)/(SIZE - 1); //making SIZE -1 data points
    double wavelength[SIZE];
    wavelength[0] = MIN_X;

    /*values for y*/
    const double MAX_Y = 5e13;
    const double MIN_Y = 0;
    const double Y_INCREMENT = 1e13;
    
    /*other*/
    double temperature[3] = {3000, 4000, 5000}; //Kelvin
    double R[SAMPLE];

    /*files*/
    data = fopen ("CTextFiles\\blackBodyRadiation.txt", "w"); //because of my ide, I have a folder 'CTextFiles' be sure to adjust depending on what is running the program
    plot = fopen ("CTextFiles\\blackBodyPlot.txt", "w");

    fprintf(data, "#Lab #7 Problem #2\n#\n# Temp(K) wavelength(μm) R\n# ----------------------------------------------------------\n");
    for (int i = 0; i < SIZE; i++) {
        R[i] = ((2 * M_PI * pow(c, 2) * h) / pow(wavelength[i], 5)) * (1 / exp((h * c) / (wavelength[i] * k * temperature[0])));
        
        R[i + (SAMPLE / 3)] = ((2 * M_PI * pow(c, 2) * h) / pow(wavelength[i], 5)) * (1 / exp((h * c) / (wavelength[i] * k * temperature[1])));

        R[i + (SAMPLE / 3 * 2)] = ((2 * M_PI * pow(c, 2) * h) / pow(wavelength[i], 5)) * (1 / exp((h * c) / (wavelength[i] * k * temperature[2])));
        
        fprintf(data, "%e %e %e %e\n", wavelength[i], R[i], R[i + (SAMPLE / 3)], R[i + (SAMPLE / 3 * 2)]); //%e is for scientific notation
        
        if (i != SIZE - 1) { // would cause an array out of bounds error
            wavelength[i + 1] = wavelength[i] + X_INCREMENT;
        }
    }

    fclose(data);

    /* https://thetimetube.herokuapp.com/gnuplotviewer/ */
    //go to this website, and paste the resulting program from the datafile 'blackBodyPlot.txt'

    //creating the gnuplot code, to display the data to the viewer
    fprintf(plot, "#Lab #7 Problem #2\n#\n#-----------------------------------------------");
    fprintf(plot, "\nset terminal svg enhanced size 600,480\nset title \'Black Body Radiation\'\nset xlabel \'Wavelength (μm)\'");
    fprintf(plot, "\nset ylabel \'Spectral Energy Density (W/m³)\'\nset key right center top");
    fprintf(plot, "\nset xrange [0 : 0.000003]\nset xtics (\"0.5\" 0.0000005, \"1\" 0.000001, \"1.5\" 0.0000015, \"2\" 0.000002, \"2.5\" 0.0000025, \"3\" 0.000003)");
    fprintf(plot, "\nset yrange [0 : 50000000000000]\nset ytics 10000000000000\nset grid");
    fprintf(plot, "\nplot \"blackBodyRadiation.txt\" using 1:2 title \"3000K\" with lp lw 3 lc \"#AD2105\" pt 0, \\\n\"blackBodyRadiation.txt\" using 1:3 title \"4000K\" with l dt 4 lw 3 lc \"#E84120\" pt 0, \\\n\"blackBodyRadiation.txt\" using 1:4 title \"5000K\" with l dt 3 lw 3 lc \"#F5A190\" pt 0");
    
    fclose(plot);

    return 0;
}