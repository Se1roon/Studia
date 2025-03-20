#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define lp 200000

double c_od, c_do;

double f3(double x) {
	return cos(3*x) + sin(x);
}

double f4(double x) {
	return 4*x*x*x + 1.5*x*x + 3*x + 4;
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

	double x, y;
	int pod_wykresem = 0;
	double krok = (c_do - c_od) / lp;

	double f_min = f(c_od);
	double f_max = f(c_do);

	for (double i = c_od; i <= c_do; i += krok) {
		x = f(i);
		if (x < f_min) f_min = x;
		if (x > f_max) f_max = x;
	}

	double przesuniecie = (f_min < 0) ? fabs(f_min) : 0;
	double max = f_max + przesuniecie;

	for (int i = 0; i < lp; i++) {
		x = c_od + (double)rand()/RAND_MAX * (c_do - c_od);
		y = (double)rand()/RAND_MAX * max;

		if (y <= f(x) + przesuniecie) pod_wykresem++;
	}

	double I = (c_do - c_od) * max * ((double)pod_wykresem / lp);
	return I - przesuniecie * (c_do - c_od);
}

