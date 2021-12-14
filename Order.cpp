#include "Order.hpp"

Order::Order(Client client, std::vector<Product> product, bool status): _client(client), _products(product), _status(status) {}
Order::~Order(){}