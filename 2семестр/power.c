#include <stdio.h>

double power(int y) {

    int i;
    double rez = 1;

    for(i = 1; i <= y; ++i) {
        rez *= (0.0625);
    }
    return rez;
}

int main()
{
	double x =power(1);
	printf("x = %lf\n", x);
}
