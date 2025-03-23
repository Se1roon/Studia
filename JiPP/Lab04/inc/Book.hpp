#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>


class Book {
	public:
		std::string title;
		std::string author;
		double price;

		Book(std::string title, std::string author, double price);
};


#endif
