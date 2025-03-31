#include <iostream>


template <int Degree>
class Polynomial {
	public:
		Polynomial(const int (&coefficients)[Degree + 1]) {
			std::copy(coefficients, coefficients + Degree + 1, this->coefficients);
		};

		friend void printPolynomial<Degree>(const Polynomial<Degree>& poly);

	private:
		int coefficients[Degree + 1];
};

template <int Degree>
void printPolynomial(const Polynomial<Degree>& poly) {
	int currentDegree = Degree;
	for (int c : poly.coefficients) {
		if (currentDegree == 0) std::cout << c << " ";
		else if (c != 0) {
			std::cout << c << "x^" << currentDegree;
			if (c < 0) std::cout << " - ";
			else std::cout << " + ";
		}
		currentDegree--;
	}

	return;
}


int main() {
	Polynomial<3> poly1({1, 2, 3, 4});
	Polynomial<2> poly2({-1, 0, 1});

	printPolynomial(poly1);
	std::cout << "\n";
	printPolynomial(poly2);

	return 0;
}

