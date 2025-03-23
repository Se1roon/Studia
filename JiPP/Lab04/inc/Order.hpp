#ifndef ORDER_HPP
#define ORDER_HPP

#include <vector>
#include <string>

#include "Book.hpp"


struct order_entry_t {
	Book book;
	int quantity;
};

class Order {
	public:
		void printOrder();

		double calculate_total_price();
		double calculate_total_price(double shipping);

		void operator+=(struct order_entry_t entry);

	private:
		std::vector<struct order_entry_t> book_list;
};


#endif
