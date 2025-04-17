#include <vector>
#include <iostream>
#include <fstream>

#include "Product.hpp"
#include "ProductManager.hpp"


ProductManager::ProductManager() {
	std::ifstream file("./products", std::ios::in | std::ios::binary);
	if (!file.is_open()) {
		std::ofstream create("./products", std::ios::binary);
		create.close();
		file.open("./products", std::ios::in | std::ios::binary);
	}

	while (file.peek() != EOF) {
		int id = 0;
		file.read((char *)&id, sizeof(id));

		int32_t length = 0;

		file.read((char *)&length, sizeof(length));
		
		std::string s(length, '\0');
		file.read(&s[0], length);

		double price = 0;
		file.read((char *)&price, sizeof(price));

		Product p(id, s, price);
		products.push_back(p);
	}

	file.close();
}

ProductManager::~ProductManager() {
	std::cout << "Saving!\n";
	std::ofstream file("./products", std::ios::out | std::ios::trunc | std::ios::binary);
	
	for (Product p : products) {
		std::cout << "Current id = " << p.id << "\n";
		int32_t name_len = p.name.length();
			
		file.write((char *)&p.id, sizeof(p.id));
		file.write((char *)&name_len, sizeof(name_len));
		file.write(&p.name[0], name_len);
		file.write((char *)&p.price, sizeof(p.price));
	}

	file.close();
}

int ProductManager::addProduct(Product& p) {
	// Checks for id already existing
	products.push_back(p);

	return 0;
}

int ProductManager::removeProduct(int id) {
	// Check if id exists 
		
	int index = -1;
	for (Product p : products) {
		if (p.id == id) break;
		index += 1;
	}
	
	if (index < 0) throw 

	index += 1;
	products.erase(products.begin() + index, products.begin() + index + 1);

	return 0;
}

void ProductManager::displayProducts() {
	for (Product& p : products) {
		std::cout << "ID: " << p.id << "\n"
				  << "Name: " << p.name << "\n"
				  << "Price: " << p.price << "\n\n";
	}
}

