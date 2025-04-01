#ifndef ADDRESSBOOK_HPP
#define ADDRESSBOOK_HPP

#include <string>
#include <vector>


typedef struct contact_t {
	std::string name;
	std::string phone_num;
} CONTACT;


class AddressBook {
	public:
		AddressBook();

		void printContacts();
		void sortContacts();
		std::string searchContacts(std::string name);
		void addContact(std::string name, std::string phone);

	private:
		std::vector<CONTACT> contact_list;
};


#endif
