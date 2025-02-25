#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define lp 1000

double c_od, c_do;

double f3(double x) {
	return sin(x);      
}

double f4(double x) {
	return x*x + 2*x;
}

// To trzeba jakąś inną metodą zrobić xd
double prostokaty(double (*f)(double)) {
	double sum = 0;
	double step = (c_do - c_od) / lp;
	for (double i = c_od; i < c_do; i += step)
		sum += f(i) * step;

	return sum;
}

double trapezy(double (*f)(double)) {
	double sum = 0;
	double step = (c_do - c_od) / lp;
	for (double i = c_od; i < c_do; i += step) {
		if (i + step > c_do) sum += (f(i) + f(c_do)) * step / 2;
		else sum += (f(i) + f(i + step)) * step / 2;
	}
		
	return sum;
}
       
double mc(double (*f)(double)) {
	double sum = 0;
	double distance = c_do - c_od;

	srand(time(NULL));

	int i = 1;
	for (; i <= lp; i++)
		sum += f(c_od + ((double)rand() / ((double)RAND_MAX + 1) * distance));

	sum = distance * sum / lp;

	return sum;
}

