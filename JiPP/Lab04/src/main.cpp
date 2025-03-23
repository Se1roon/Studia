#include <vector>
#include <iostream>

#include "Order.hpp"
#include "Book.hpp"


int main() {
	Book book1("Book1", "Autor1", 10.99);
	Book book2("Book2", "Autor2", 20.99);

	Order order;

	order += { .book = book1, .quantity = 2 };
	order += { .book = book2, .quantity = 3 };

	order.printOrder();

	std::cout << "Total price: " << order.calculate_total_price() << "\n";
	std::cout << "Total price (+shipping): " << order.calculate_total_price(5) << "\n";
}

