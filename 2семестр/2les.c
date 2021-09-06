#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double Translate(char temp)
{
	double num = 0;
	switch (temp) {
		case '0': num = 0; break;
		case '1': num = 1; break;
		case '2': num = 2; break;
		case '3': num = 3; break;
		case '4': num = 4; break;
		case '5': num = 5; break;
		case '6': num = 6; break;
		case '7': num = 7; break;
		case '8': num = 8; break;
		case '9': num = 9; break;
		case 'A': case 'a': num = 10; break;
		case 'B': case 'b': num = 11; break;
		case 'C': case 'c': num = 12; break;
		case 'D': case 'd': num = 13; break;
		case 'E': case 'e': num = 14; break;
		case 'F': case 'f': num = 15; break;
	}
	return num;
}

double Power(int base, int degree)
{
	double rez = 1.0;
	if(degree != -1)
	{
		for(int i = 0; i < degree; ++i)
		{
	    rez *= base;
	  }
	}else
	{
		degree *= -1;
		for(int i = 0; i < degree; ++i)
		{
			rez *= (1/base);
	  }
	}
	return rez;
}


int main()
{
	char inputStr[64];
	printf("Enter string: \n");
	fgets(inputStr,64,stdin);

	char dot = 'n';
	int Point = 0; int numArr = strlen(inputStr) - 1;

	double* outputDbl = NULL;
	outputDbl = (double *) malloc(numArr * sizeof(double));

	char temp;
	for(int i = 0; i <= numArr; i++)
	{
		switch(inputStr[i]){
			case '.': Point = i; dot = 'y'; break;
			default: temp = inputStr[i]; outputDbl[i] = Translate(temp); break;
		}
	}

	switch(dot)
	{

		case 'y':
			for(int n = 0; n <= Point; n++)
			{
				int pow = Power(16, n);
				int powDot = Power(16, n);
				outputDbl[Point - n-1] = outputDbl[Point - n-1] * pow;
				if(n <= (numArr - Point)){ outputDbl[Point + n -1] = outputDbl[Point + n-1] *  powDot;} else{continue;}
			}
			break;

		default:
			for(int y = 0; y <= numArr; y++)
			{
				int pow = Power(16, y);
				outputDbl[numArr - y-1] = outputDbl[numArr - y-1] * pow;
			}
			break;
	}

	double sum = 0;

	for (int j = 0; j < numArr; j++) {
		sum = sum + outputDbl[j];
	}
	printf("Sum = %lf\n", sum);

	free(outputDbl);
	return 0;
}
