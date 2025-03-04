#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define lp 2000

double c_od, c_do;

double f3(double x) {
	return sin(x);      
}

double f4(double x) {
//	return x*x + 2*x;
	return 0;
}

double prostokaty(double (*f)(double)) {
	double sum = 0;
	double step = (c_do - c_od) / lp;
	for (double i = c_od; i < c_do; i += step)
		sum += f(i + step/2);

	return sum * step;
}

double trapezy(double (*f)(double)) {
	double sum = (f(c_do) + f(c_od)) / 2;
	double step = (c_do - c_od) / lp;
	for (double i = c_od + step; i < c_do; i += step)
		sum += f(i);
		
	return sum * step;
}
     
double mc(double (*f)(double)) {
	srand(time(NULL));

	double sum = 0;
	for (int c = 0; c < lp; c++)
		sum += f(c_od + (((double)rand()/RAND_MAX) * (c_do - c_od)));

	return (c_do - c_od) * sum / lp;
}

