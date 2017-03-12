#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define PI 3.14159265358979323846
#define RAD_TO_DEG 57.29578

int main(int argc, char const *argv[])
{
	FILE *fp1,*fp2,*fp3,*output;

	fp1 = fopen("data_x.txt","r");
	fp2 = fopen("data_y.txt","r");
	fp3 = fopen("data_z.txt","r");
	output = fopen("Acc_output.txt","w+");

	if(fp1 == NULL || fp2 == NULL || fp3 == NULL){
		printf("File Not Found\n");
	}

	double raw_x = 0.0;
	double raw_y = 0.0;
	double raw_z = 0.0;
	double AccXangle = 0.0;
	double AccYangle = 0.0;

		fprintf(output,"AccXangle \t AccYangle\n");

	while (fscanf(fp1,"%lf",&raw_x)!=EOF && fscanf(fp2,"%lf",&raw_y)!=EOF && fscanf(fp3,"%lf",&raw_z)!=EOF){

		//Converting raw accelerometer readings into Degrees.
		AccXangle = (double) ( atan2(raw_y,raw_z)+ PI )*RAD_TO_DEG;
		AccYangle = (double) ( atan2(raw_z,raw_x)+ PI )*RAD_TO_DEG; 


		
		AccXangle -= (double)180.0;
		
		if (AccYangle > 90){
	        AccYangle -= (double)270;
		}else{
			AccYangle += (double)90;
		}

		fprintf(output,"%lf \t %lf\n",AccXangle,AccYangle);
		//printf("%lf\t%lf\n",AccXangle,AccYangle);
	}

	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	fclose(output);


	return 0;
}
