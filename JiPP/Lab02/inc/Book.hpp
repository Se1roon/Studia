#ifndef BOOK_H
#define BOOK_H

#include <string>


class Book {
	public:
		Book(std::string title, std::string author, std::string isbn);
		~Book();

		void getInfo();

		void setTitle(std::string title);
		void setAuthor(std::string author);
		void setIsbn(std::string isbn);
		void setAvailability(bool state);

		std::string getTitle();
		std::string getAuthor();
		std::string getIsbn();
		bool isAvailable();

	private:
		std::string title;
		std::string author;
		std::string isbn;
		bool available;
};

#endif
