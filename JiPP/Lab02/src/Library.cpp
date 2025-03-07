#include <iostream>

#include "Library.hpp"
#include "Book.hpp"


void Library::addBook(Book* b) {
	books.push_back(b);
}

void Library::removeBook(Book* b) {
	int i = 0;
	for (Book* book : books) {
		if (book == b) break;
		i++;
	}

	books.erase(books.begin() + i);
}

void Library::borrowBook(Book* b) {
	if (!b->isAvailable()) {
		std::cout << "Książka o tytule \"" << b->getTitle() << "\" jest niedostępna.\n";
		return;
	}

	b->setAvailability(false);
	return;	
}

void Library::returnBook(Book* b) {
	b->setAvailability(true);
	return;
}

void Library::displayBooks() {
	for (Book* book : books) {
		book->getInfo();
		std::cout << "\n";
	}
}

