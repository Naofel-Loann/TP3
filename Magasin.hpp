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
	void addProduct(Product& product);
	void display();
	void searchProduct(std::string name);
	void upadateAmount(std::string name, int amount);
	void addClient(Client *client);
	void dispClient();
	void searchClient(std::string name);
	void addToCart(Client &client, Product &product);
	void delInCart(Client &client,Product &product);
	void modifyAmount(Client& client, Product& product, int amount);
	void validateOrder(Order& order);
	void setOrderStatus(Order& order, bool state);
	void dispOrder();
private:
	std::vector<Product*> _products;
	std::vector<Client*> _clients;
	std::vector<Order*> _orders;
};

#endif