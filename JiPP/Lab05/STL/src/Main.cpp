#include <iostream>

#include "AddressBook.hpp"


int main() {
	AddressBook book;

	book.addContact("Szymon", "531-243-717");
	book.addContact("Adrian", "312-333-954");
	book.addContact("George", "211-847-192");

	std::cout << "\n==========BEFORE SORT==========\n\n";
	book.printContacts();

	book.sortContacts();

	std::cout << "\n==========AFTER SORT===========\n\n";
	book.printContacts();


	std::string name;
	std::cout << "\nWhose phone number should I search for: ";
	std::cin >> name;

	std::string phone = book.searchContacts(name);
	if (phone != "") std::cout << name << "'s phone number: " << phone << "\n";
	else std::cout << "Could not find " << name << "'s phone number\n";

	return 0;
}

