#include <iostream>

#include "Book.hpp"

Book::Book(std::string title, std::string author, std::string isbn) : 
	title(title), author(author), isbn(isbn), available(true) 
{
}

Book::~Book() {
//	std::cout << "Niszczę książkę\n";
}

void Book::getInfo() {
	std::cout << "Title: " << title << "\n";
	std::cout << "Author: " << author << "\n";
	std::cout << "Isbn: " << isbn << "\n";
	std::cout << "Available: " << available << "\n";
	
	return;
}

void Book::setTitle(std::string title) { this->title = title; }
void Book::setAuthor(std::string author) { this->author = author; }
void Book::setIsbn(std::string isbn) { this->isbn = isbn; }
void Book::setAvailability(bool state) { available = state; }

std::string Book::getTitle() { return title; }
std::string Book::getAuthor() { return author; }
std::string Book::getIsbn() { return isbn; }
bool Book::isAvailable() { return available; }

