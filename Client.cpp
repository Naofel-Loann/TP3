#include "Client.hpp"
#include <sstream>

Client::Client(std::string firstname, std::string name): _firstname(firstname), _name(name)
{
    static int id=0;
    _id = id++;
}

Client::~Client(){}

int Client::getID()
{
    return _id;
}
std::string Client::getFirstname()
{
    return _firstname;
}
std::string Client::getName()
{
    return _name;
}

std::vector<Product> Client::getCart()
{
    return _cart;
}

std::vector<int> Client::getAmount()
{
    return _amount;
}

void Client::addProduct(Product& product)
{
    _cart.push_back(product);
    _amount.push_back(1);
}

void Client::emptyCart()
{
    _cart.clear();
    _amount.clear();
}
void Client::updateAmount(std::string name, int amount)
{
    bool find=0;
    for(int i=0; i < _cart.size(); i++)
    {
        if(_cart[i].getTitle()==name || std::to_string(_cart[i].getID())==name)
        {
            _amount[i] = amount;
            find=1;
        }
    }
    if (find==0)
    {
        std::cout << "Erreur: Aucun produit trouve a ce nom." << std::endl;
    }
}

void Client::delProduct(std::string name)
{
    bool find=0;
    for(int i=0; i < _cart.size(); i++)
    {
        if(_cart[i].getTitle()==name)
        {
            find=1;
            _cart.erase(_cart.begin() + i);
            _amount.erase(_amount.begin()+i);
        }
    }
    if (find==0)
    {
        std::cout << "Aucun produit trouve a ce nom " << std::endl;
    }
}

std::string Client::dispCart()
{
    std::stringstream ss;
    std::string result;
    for (int i = 0; i < _cart.size(); i++)
        ss << "\n" << _cart[i] << " Quantite voulue: " << _amount[i] << std::endl;

    result = ss.str();
    return result;
}

std::ostream &operator<<(std::ostream &flux,  Client& client)
{
    flux << "Client ID: "<< client.getID() << "\nPrenom: " << client.getFirstname() << "\nNom: " <<  client.getName() << client.dispCart() << std::endl;
    return flux;
}

void Client::addCart(std::vector<Product> vec)
{
    for(int i=0; i< vec.size() ; i++)
    {
        _cart.push_back(vec[i]);
    }
}
void Client::addQuantity(std::vector<int> vec)
{
    for(int i=0; i< vec.size() ; i++)
    {
        _amount.push_back(vec[i]);
    }
}
