#include <iostream>

#include "Library.hpp"
#include "Book.hpp"


int main() {
	Library lib;

	Book b("Film 0", "Autor 0", "1991");
	Book b1("Film 1", "Autor 1", "2001");
	Book b2("Film 2", "Autor 2", "2011");
	
	lib.addBook(&b);
	lib.addBook(&b1);
	lib.addBook(&b2);

	lib.borrowBook(&b);

	lib.displayBooks();

	lib.returnBook(&b);

	lib.displayBooks();

	return 0;
}

