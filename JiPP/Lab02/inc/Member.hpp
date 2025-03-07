#ifndef MEMBER_H
#define MEMBER_H

#include <string>


class Member {
	public:
		Member(std::string name);

		void borrowBook();
		void returnBook();

		void setName(std::string name);
		void setBooksBorrowed(unsigned int booksBorrowed);

		std::string getName();
		unsigned int getBooksBorrowed();

	private:
		std::string name;
		unsigned int booksBorrowed;
};

#endif
