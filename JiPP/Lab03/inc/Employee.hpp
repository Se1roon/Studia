#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <string>


class Employee {
	public:
		std::string name;
		std::string surname;
		unsigned int salary;

		virtual void introduceYourself() = 0;
};


#endif
