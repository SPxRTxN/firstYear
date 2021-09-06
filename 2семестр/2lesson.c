#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double Translate(char temp)
{
	switch (temp) {
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
	}
}

double Power(int base, int degree)
{
	double rez = 1.0;
	for(int i = 0; i < degree; ++i)
		{
	    rez *= base;
	  }
	return rez;
}
double powerAfterPoint(int base, int degree)
{
	double rez = 1.0;
	for(int i = 0; i < degree; ++i)
	{
		rez /= base;
	}
	return rez;
}
int dotSearch(char inputStr[], int len)
{
	for(int i = 0; i <= len; i++)
	{
		if(inputStr[i] == '.')
		{
			int point = i;
		}else{
			int point = -1;
		}
	}
}

int main()
{
	char inputStr[64];
	printf("Enter string: \n");
	fgets(inputStr, 64, stdin);

	int numArr = strlen(inputStr)-1;

	int dotIndex = dotSearch(inputStr, numArr);
	printf("Initial value index of the power = %d\n", dotIndex + 1);

	double sum = 0;
	if(dotIndex == -1)
	{
		for(int j = 0; j < numArr; j++)
		{
			sum += Translate(inputStr[numArr - j - 1]) * Power(4, j);
		}
  }else
	{
		for(int j = 1; j < numArr; j++)
		{
			sum += Translate(inputStr[numArr - j - 2]) * Power(4, j - 1);
			if(j < (numArr - dotIndex))
			{
			sum += Translate(inputStr[dotIndex + j]) * powerAfterPoint(4, j);
			}
		}
	}

	printf("sum = %.4lf\n", sum);

	return 0;
}
