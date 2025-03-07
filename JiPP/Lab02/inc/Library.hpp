#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>

#include "Book.hpp"


class Library {
	public:
		void addBook(Book* b);
		void removeBook(Book* b);
		void borrowBook(Book* b);
		void returnBook(Book* b);
		void displayBooks();

	private:
		std::vector<Book*> books;
};

#endif
