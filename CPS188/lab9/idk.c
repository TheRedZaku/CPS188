#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //change to csv
    FILE* data=fopen("CTextFiles\\ontario.txt", "r");
    double temp[365][31]; //n-1995, n-1
    double store[1000]; //storage
    double total[6]; //for calculating average, part B
    double high=0; //for calculating highest temp, part C
    int row=0, column=0; //counters
    char line[1000];
    
    fgets(line, sizeof(line), data);
    
    while (fgets(line, sizeof(line), data)){
        //doesn't read day 366
        if (row>=365){
            break;
        }
        
        char *token=strtok(line, ",");
        
        while (token!=NULL){
            store[column]=atof(token); //stores it into a temporary array
            column++;
            token=strtok(NULL, ",");
        }
        
        for (int i=0; i<31; i++){
            temp[row][i]=store[i]; //reads only 1995-2025, ignores 2026 and day number
            printf("%lf\n", temp[row][i]);
        }
        return 1;
        column=0;
        row++;
    }
    
    for (int w=0; w<6; w++){
        total[w]=0;
    }
    
    for (int j=2020; j<2026; j++){ //calculates average temp
        for (int k=0; k<365; k++){
            total[j-2020]+=temp[k][j-1995];
        } total[j-2020]=total[j-2020]/365;
    } 
    
    for (int l=0; l<6; l++){ //prints average temp
        printf("The average temperature for %d is %.3lf.\n", l+2020, total[l]);
    }
    
    for (int q=0; q<31; q++){ //calculates highest temp
        if (high<temp[184][q]){
            high=temp[184][q];
        }
    }
    printf("The highest temperature for day #185 is %.3lf degrees Celsius.", high);
    
    fclose(data);
    return 0;
}