#include <iostream>

#include "Product.hpp"
#include "ProductManager.hpp"


int main() {
	ProductManager manager;

	Product p1(1, "Cipa", 69);

	manager.addProduct(p1);
	manager.displayProducts();
}

