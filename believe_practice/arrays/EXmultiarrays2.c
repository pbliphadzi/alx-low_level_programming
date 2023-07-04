#include <stdio.h>

int main(){
    float average;
    int grades[2][5];
    int a;
    int b;
grades[0][0] = 80;
		grades[0][1] = 70;
		grades[0][2] = 65;
		grades[0][3] = 89;
		grades[0][4] = 90;

		grades[1][0] = 85;
		grades[1][1] = 80;
		grades[1][2] = 80;
		grades[1][3] = 82;
		grades[1][4] = 87;

for (a = 0; a < 2; a++){
    average = 0;
    for (b = 0; b < 5; b++){
        average += grades[a][b];
    }
}
average /= 5.0 ;
printf( "The average for subject %d is : %.2f\n", a, average);
return 0;
}