#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include "Client.hpp"
#include "Product.hpp"

class Order
{
public:
	Order(Client client, std::vector<Product> product, bool status);
	~Order();
private:
	Client _client;
	std::vector<Product> _products;
	bool _status;
};

#endif