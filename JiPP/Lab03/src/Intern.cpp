#include <iostream>

#include "Employee.hpp"
#include "Intern.hpp"


void Intern::introduceYourself() {
	std::cout << "Hello, I'm an intern, and my name is " << this->name << " " << this->surname << "\n";
}

