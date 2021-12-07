#ifndef MAGASIN_H
#define MAGASIN_H

#include <iostream>
#include <vector>
#include "Product.hpp"
#include "Client.hpp"
#include "Order.hpp"

class Magasin
{
public:
	Magasin();
	~Magasin();
	void addProduct(Product product);
	void display();
	void searchProduct(std::string name);
	void upadateAmount(std::string name, int amount);
private:
	std::vector<Product> _products;
	std::vector<Client> _clients;
	std::vector<Order> _orders;
};

#endif