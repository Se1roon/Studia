#ifndef PRODUCT_MANAGER_HPP
#define PRODUCT_MANAGER_HPP


#include <vector>

#include "Product.hpp"


class ProductManager {
	public:
		ProductManager();
		~ProductManager();

		int addProduct(Product& p); // 0 - success
		int removeProduct(int id);
		void displayProducts();

	private:
		std::vector<Product> products;

};


#endif
