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
	// Znalezc fmin i fmax (przeleciec caly przedzial)
	// jezeli oba sa > 0 to mniejszy do 0
	// N razy generujemy x <c_od; c_do> i y <Min; Max>
	// jezeli y > 0 to +1
	// jezeli y < 0 to -1
	// N+/N- = P[]/całka

	double sum = 0;
	double distance = c_do - c_od;

	srand(time(NULL));

	int i = 1;
	for (; i <= lp; i++) {
		double x = f(c_od + ((double)rand() / ((double)RAND_MAX + 1) * distance));
		sum += x;	
	}

	sum = distance * sum / lp;

	return sum;
}

