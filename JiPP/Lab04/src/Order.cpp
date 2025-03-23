#include <vector>
#include <iostream>

#include "Order.hpp"
#include "Book.hpp"


void Order::printOrder() {
	for (struct order_entry_t entry : this->book_list) {
		std::cout << "Title: " << entry.book.title << "\n" <<
					 "Author: " << entry.book.author << "\n" <<
					 "Price: " << entry.book.price << "\n" <<
					 "Quantity: " << entry.quantity << "\n\n";
	}

	return;
}

double Order::calculate_total_price() {
	double total = 0;
	for (struct order_entry_t entry : book_list)
		total += entry.quantity * entry.book.price;

	return total;
}

double Order::calculate_total_price(double shipping) {
	return calculate_total_price() + shipping;
}

void Order::operator+=(struct order_entry_t entry) {
	book_list.push_back(entry);
}

