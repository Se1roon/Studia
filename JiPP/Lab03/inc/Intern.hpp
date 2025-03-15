#ifndef INTERN_HPP
#define INTERN_HPP

#include "Employee.hpp"


class Intern : private Employee {
	public:
		using Employee::name;
		using Employee::surname;

		void introduceYourself() override;
};


#endif
