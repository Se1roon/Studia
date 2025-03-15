#include <iostream>

#include "Employee.hpp"
#include "Manager.hpp"


void Manager::introduceYourself() {
	std::cout << "Hello, I'm a manager and my name is " << this->name << " " 
		<< this->surname<< ". My salary is " << this->salary << "$\n";
}

