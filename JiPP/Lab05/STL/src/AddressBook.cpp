#include <iostream>
#include <algorithm>

#include "AddressBook.hpp"


AddressBook::AddressBook() {
	contact_list.push_back({ "Marian", "420-531-222" });
	contact_list.push_back({ "Krzysztof", "691-231-946" });
}

void AddressBook::printContacts() {
	for (CONTACT c : contact_list)
		std::cout << "Name: " << c.name << "\nPhone: " << c.phone_num << "\n\n";
}

void AddressBook::sortContacts() {
	auto comp = [](CONTACT c1, CONTACT c2) { return c1.name < c2.name; };
	std::sort(contact_list.begin(), contact_list.end(), comp);
}

std::string AddressBook::searchContacts(std::string name) {
	for (CONTACT c : contact_list)
		if (c.name == name) return c.phone_num;
	return "";
}

void AddressBook::addContact(std::string name, std::string phone) {
	CONTACT new_contact = { .name = name, .phone_num = phone };

	contact_list.push_back(new_contact);
}

