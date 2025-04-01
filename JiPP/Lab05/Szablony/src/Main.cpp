#include <iostream>
#include <cmath>

#include "Polynomial.hpp"


template <int Degree>
void printPolynomial(const Polynomial<Degree>& poly) {
	int currentDegree = Degree;
	for (double c : poly.coefficients) {
		if (c != 0) {
			if (currentDegree != Degree && c > 0) std::cout << " + ";
			else if (c < 0) std::cout << " - ";

			if (currentDegree != 0) {
				if (c != 1 && c != -1) std::cout << std::abs(c);
				std::cout << "x^" << currentDegree;
			} else std::cout << c;
		}
		currentDegree--;
	}

	return;
}


int main() {
	Polynomial<2> poly1({-2, 1, 1});
	Polynomial<3> poly2({3, 4, -7, 1});
	
	std::cout << "Poly1 = ";
	printPolynomial(poly1);
	std::cout << "\n" << "Poly2 = ";
	printPolynomial(poly2);
	std::cout << "\n";

	auto poly3 = poly1.addPolynomial(poly2);
	std::cout << "Poly3 = Poly1 + Poly2 = ";
	printPolynomial(poly3);
	std::cout << "\n";

	auto poly4 = poly1.subPolynomial(poly2);
	std::cout << "Poly1 - Poly2 = ";
	printPolynomial(poly4);
	std::cout << "\n";

	auto poly5 = poly3.mulPolynomial(3);
	std::cout << "3 * Poly3 = ";
	printPolynomial(poly5);
	std::cout << "\n";

	return 0;
}

