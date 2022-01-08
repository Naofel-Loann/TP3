#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include "Client.hpp"
#include "Product.hpp"

class Order
{
public:
	Order(Client *client);
	~Order();
	int getID();
	Client *getClient();
	std::vector<Product> getProduct();
	std::vector<int> getAmount();
	bool getStatus();
	std::string dispProducts();
	void setStatus(bool state);
private:
	int _id;
	Client *_client;
	std::vector<Product> _products;
	std::vector<int> _amount;
	bool _status;
};
std::ostream &operator<<(std::ostream &flux,  Order& order);
#endif