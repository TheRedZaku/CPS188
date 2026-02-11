/*Lab #4 Problem #3*/

//using Gay-Lussac's law, where p1/t1 = p2/t2

#include <stdio.h>

int main(void) {
    
    double refKelvin = 300, refAtm = 50, maxKelvin = 0, maxAtm = 500, celsius, kelvin, atm;

    //a) calculating the maximum possible temperature the cylinder can withstand
    //using the law
    //t2 = p2t1/p1
    maxKelvin = maxAtm * refKelvin / refAtm;
    printf("The maximum temperature the cylinder can withstand is : %.3lf Kelvin.\n", maxKelvin);
    getchar();

    //to find initial pressure at 0 celsius, use the same equation (temperature must be absolute)
    celsius = 0, kelvin = 273.15, atm = 45.525;
    //Kelvin has no degree symbol, as it is absolute
    printf("Temperature (\u00b0C)    Temperature (K)      Pressure (atm)\n"
    "----------------     ----------------     --------------\n");

    do {
        printf("%7.2lf %20.2lf %22.3lf\n", celsius, kelvin, atm);  
        
        celsius += 250; //250 degree increment
        kelvin += 250;
        atm = (refAtm * kelvin) / refKelvin;
    //while loop condition is true until cylinder explodes
    } while (atm <= 500);

    printf("\033[1;5;31m" "%7.2lf %20.2lf %22.3lf\n" "\033[0m", celsius, kelvin, atm);

    printf("KABOOM! You're all dead.");
    fflush(stdin);
    getchar();
    return 0;
    //Must be displayed in a different compiler (like OnlineGDB) in order to properly display temperature unicode
}

