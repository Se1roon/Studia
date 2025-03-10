#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define lp 20000

double c_od, c_do;

double f3(double x) {
	return sin(x);      
}

double f4(double x) {
	return x*x + 2*x;
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

	double x_dif = c_do - c_od;

	double min = 0;
	double max = 0;
	for (double x = c_od; x <= c_do; x += x_dif/lp) {
		if (f(x) > max) max = f(x);
		else if (f(x) < min) min = f(x);
	}

	int u = 0;
	for (int i = 0; i < lp; i++) {
		double r_x = c_od + (double)rand()/RAND_MAX * x_dif;
		double r_y = min + (double)rand()/RAND_MAX * (max - min);

		if (f(r_x) >= r_y) u++;
	}

	double integral = (double)u / lp * (x_dif * (max - min));

	return integral - fabs(min) * (c_do - c_od);
}

