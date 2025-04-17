#ifndef PRODUCT_HPP
#define PRODUCT_HPP


#include <string>


class Product {
	public:
		int id;
		std::string name;
		double price;

		Product(int id, std::string name, double price);

};


#endif
