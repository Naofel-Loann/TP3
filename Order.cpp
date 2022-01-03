#include "Order.hpp"

Order::Order(Client &client): _client(client) 
{
    _products = client.getCart();
    _status = false;
    _amount = client.getAmount();
    static int id = 0;
    _id = id++;
}
Order::~Order(){}

int Order::getID()
{
    return _id;
}
Client Order::getClient()
{
    return _client;
}
std::vector<Product> Order::getProduct()
{
    return _products;
}
bool Order::getStatus()
{
    return _status;
}

std::string Order::dispProducts()
{
    std::stringstream ss;
    std::string result;
    for (int i = 0; i < _products.size(); i++)
    {
        ss << "\n" << _products[i] << " Quantite voulue: " << _amount[i] << std::endl;
    }
    result = ss.str();
    return result;
}

void Order::setStatus(bool state)
{
    _status = state;
}

std::ostream &operator<<(std::ostream &flux,  Order& order)
{
    flux << "ID commande: " << std::to_string(order.getID()) <<"\nClient: " << order.getClient().getFirstname() << " " << order.getClient().getName() << "\nProduits de la commande: " << order.dispProducts() << " Status de la commande: " << order.getStatus() << std::endl;
    return flux;
}