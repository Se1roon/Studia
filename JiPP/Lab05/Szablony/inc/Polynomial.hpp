#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP

#include <iostream>
#include <cmath>


template <int Degree>
class Polynomial {
	public:
		double coefficients[Degree + 1];


		Polynomial(const double (&coefficients)[Degree + 1]) {
			std::copy(coefficients, coefficients + Degree + 1, this->coefficients);
		}

		template <int Degree2>
		Polynomial<std::max(Degree, Degree2)> addPolynomial(const Polynomial<Degree2>& other) {
			double new_coefficients[std::max(Degree + 1, Degree2 + 1)] = {0};
			int co_diff = Degree - Degree2;

			if (co_diff >= 0) {
				for (int i = co_diff; i < Degree + 1; i++)
					new_coefficients[i] = this->coefficients[i] + other.coefficients[i - co_diff];

				for (int i = 0; i < co_diff; i++)
					new_coefficients[i] = this->coefficients[i];
			} else {
				co_diff = -1 * co_diff;
				for (int i = co_diff; i < Degree2 + 1; i++)
					new_coefficients[i] = other.coefficients[i] + this->coefficients[i - co_diff];

				for (int i = 0; i < co_diff; i++)
					new_coefficients[i] = other.coefficients[i];
			}

			Polynomial<std::size(new_coefficients) - 1> new_p(new_coefficients);

			return new_p;
		}

		template <int Degree2>
		Polynomial<std::max(Degree, Degree2)> subPolynomial(const Polynomial<Degree2>& other) {
			double new_coefficients[std::max(Degree + 1, Degree2 + 1)] = {0};
			int co_diff = Degree - Degree2;

			if (co_diff >= 0) {
				for (int i = co_diff; i < Degree + 1; i++)
					new_coefficients[i] = this->coefficients[i] - other.coefficients[i - co_diff];

				for (int i = 0; i < co_diff; i++)
					new_coefficients[i] = this->coefficients[i];
			} else {
				co_diff = -1 * co_diff;
				for (int i = co_diff; i < Degree2 + 1; i++)
					new_coefficients[i] = other.coefficients[i] - this->coefficients[i - co_diff];

				for (int i = 0; i < co_diff; i++)
					new_coefficients[i] = other.coefficients[i];
			}

			Polynomial<std::size(new_coefficients) - 1> new_p(new_coefficients);

			return new_p;
		}

		Polynomial mulPolynomial(int q) {
			Polynomial<Degree> p(this->coefficients);
			for (int i = 0; i < Degree + 1; i++)
				p.coefficients[i] *= q;

			return p;
		}

		double calculatePolynomial(double x) {
			double sum = 0;
			for (int i = 0; i < Degree + 1; i++)
				sum += coefficients[i] * std::pow(x, Degree - i);

			return sum;
		}


		friend void printPolynomial<Degree>(const Polynomial<Degree>& poly);
};

#endif

