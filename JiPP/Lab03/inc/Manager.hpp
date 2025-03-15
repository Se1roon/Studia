#ifndef MANAGER_HPP
#define MANAGER_HPP

#include "Employee.hpp"


class Manager : public Employee {
	public:
		unsigned int numberOfServants;

		void introduceYourself() override;

		friend void ChangeSalary(Manager& manager, unsigned int salary);
};


#endif
