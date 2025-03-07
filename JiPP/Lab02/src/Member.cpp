#include <string>

#include "Member.hpp"


Member::Member(std::string name) {
	this->name = name;
	booksBorrowed = 0;
}

void Member::borrowBook() {	booksBorrowed++; }

void Member::returnBook() {
	if (booksBorrowed > 0) booksBorrowed--;
}

void Member::setName(std::string name) { this->name = name; }
void Member::setBooksBorrowed(unsigned int booksBorrowed) { this->booksBorrowed = booksBorrowed; }

std::string Member::getName() { return name; }
unsigned int Member::getBooksBorrowed() { return booksBorrowed; }

