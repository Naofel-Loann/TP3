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
	std::vector<Product*> getProduct();
	std::vector<Client*> getClient();
	std::vector<Order*> getOrder();
	void addProduct(Product product);
	void dispProducts();
	Product *searchProduct(std::string name);
	void upadateAmount(std::string name, int amount);
	void addClient(Client client);
	void dispClient();
	Client *searchClient(std::string name);
	void addToCart(Client &client, Product &product);
	void delInCart(Client &client,Product &product);
	void modifyAmount(Client& client, Product& product, int amount);
	void validateOrder(Order order);
	void setOrderStatus(Order order, bool state);
	void dispOrder();
	void dispClientOrder(std::string name);
	bool clientExist(std::string name);
	bool productExist(std::string name);
	bool searchInCart(Client client, std::string name);
	bool checkAmount(std::string name, int amount);
private:
	std::vector<Product*> _products;
	std::vector<Client*> _clients;
	std::vector<Order*> _orders;
};

#endif