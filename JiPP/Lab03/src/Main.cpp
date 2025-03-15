#include <iostream>

#include "Manager.hpp"
#include "Intern.hpp"


void ChangeSalary(Manager& manager, unsigned int salary) {
	manager.salary = salary;
}


int main() {
	Manager m;
	Intern i;

	m.name = "Mietek";
	m.surname = "Żul";
	m.salary = 100000;

	i.name = "Jertek";
	i.surname = "Moxos";

	m.introduceYourself();
	i.introduceYourself();

	ChangeSalary(m, 200000);

	m.introduceYourself();

	return 0;
}

