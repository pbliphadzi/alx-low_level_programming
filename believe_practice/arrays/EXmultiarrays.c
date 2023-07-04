#include <stdio.h>

	int main() {
		/* TODO: declare the 2D array grades here */
        int grades[2][5];
		float average;
		int i;
		int j;

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

		/* TODO: complete the for loop with appropriate terminating conditions */

		for (i = 0; i < 2 ; i++) { /*  This loop deals with the subjects*/
			average = 0;/* Initial value for average is set to be zero and resets to zero for each subject*/
			for (j = 0; j < 5 ; j++) { /*This loop deals with the grades of each student*/
				average += grades[i][j]; /* += sums up all the averages in the subject*/
			}

			/* TODO: compute the average marks for subject i */
            
            average /= 5.0; /* This then takes the value stored in aveage and divides it by 5*/

			printf("The average marks obtained in subject %d is: %.2f\n", i, average);
            /* i stores subject numbers and %d will dispaly the subject number*/
            /* %.2f is used to display the final value of average for each subject*/
		}

		return 0;
	}