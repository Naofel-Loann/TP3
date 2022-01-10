#include "Magasin.hpp"

Magasin::Magasin(){}

std::vector<Product*> Magasin::getProduct(){return _products;}
std::vector<Client*> Magasin::getClient(){return _clients;}
std::vector<Order*> Magasin::getOrder(){return _orders;}

void Magasin::addProduct(Product product)
{
    Product *p = new Product(product);
    _products.push_back(p);
}

void Magasin::dispProducts()
{
    for(int i=0; i < _products.size(); i++)
    {
        std::cout << *(_products[i]) << "\n";
    }
}

Product *Magasin::searchProduct(std::string name)
{
    for(int i=0; i < _products.size(); i++)
        if(_products[i]->getTitle()==name)
            return _products[i];

    std::cout << "Aucun produit trouve a ce nom " << std::endl;
    return NULL;
}

Client *Magasin::searchClient(std::string name)
{
    for(int i=0; i < _clients.size(); i++)
        if(_clients[i]->getName()==name || std::to_string(_clients[i]->getID())==name)
           return _clients[i];

    std::cout << "Erreur: Aucun client trouve a ce nom " << std::endl;
    return 0;     
}

bool Magasin::productExist(std::string name)
{
    for(int i=0; i < _products.size(); i++)
        if(_products[i]->getTitle()==name)
            return true;
    return false;
}

bool Magasin::clientExist(std::string name)
{
    for(int i=0; i < _clients.size(); i++)
        if(_clients[i]->getName()==name || std::to_string(_clients[i]->getID())==name)
           return true;
    return false;
}

void Magasin::upadateAmount(std::string name, int amount)
{
    bool find=0;
    for(int i=0; i < _products.size(); i++)
    {
        if(_products[i]->getTitle()==name)
        {
            _products[i]->setAmount(amount);
            find=1;
        }
    }
    if (find==0)
    {
        std::cout << "Erreur: Aucun produit trouve a ce nom " << std::endl;
    }     
}

void Magasin::addClient(Client client)
{
    Client *c = new Client(client);
    _clients.push_back(c);
}

void Magasin::dispClient()
{
    for (int i = 0; i < _clients.size(); i++)
    {
        std::cout << _clients[i]->getID() << "    "<< _clients[i]->getFirstname() << "    " << _clients[i]->getName() << std::endl; 
    }
}

void Magasin::addToCart(Client& client, Product& product)
{
    bool findClient=0;
    bool findProduct=0;
    for(int i=0; i < _clients.size(); i++)
    {
        if(_clients[i]->getID()==client.getID())
        {
            findClient=true;
            for(int j=0; j < _products.size(); j++)
            {
                if(_products[j]->getID()==product.getID())
                {
                    findProduct=true;
                    _clients[i]->addProduct(product);
                    return;
                }
            }
        }
    }
    if(findClient==0)
    {
        std::cout << "Ce client n'est pas dans notre magasin" << std::endl;
        return;
    }
    if(findProduct==0)
    {
        std::cout << "Ce produit n'appartient pas au magasin" << std::endl;
    }
}

void Magasin::delInCart(Client& client, Product& product)
{
    bool findClient=0;
    bool findProduct=0;
    for(int i=0; i < _clients.size(); i++)
    {
        if(_clients[i]->getID()==client.getID())
        {
            findClient=1;
            //std::cout << _clients[i]->getName() << _clients[i]->getFirstname() << std::endl;
            for(int j=0; j < _products.size(); j++)
            {
                if(_products[j]->getID()==product.getID())
                {
                    findProduct=1;
                    _clients[i]->delProduct(product.getTitle());
                    return;
                }
            }
        }
    }
    if(findClient==0)
    {
        std::cout << "Ce client n'est pas dans notre magasin" << std::endl;
        return;
    }
    if(findProduct==0)
    {
        std::cout << "Ce produit n'appartient pas au magasin" << std::endl;
    }
}

void Magasin::modifyAmount(Client& client, Product& product, int amount)
{
    bool findClient=0;
    bool findProduct=0;
    for(int i=0; i < _clients.size(); i++)
    {
        if(_clients[i]->getID()==client.getID())
        {
            findClient=1;
            for(int j=0; j < _products.size(); j++)
            {
                if(_products[j]->getID()==product.getID())
                {
                    findProduct=1;
                    _clients[i]->updateAmount(std::to_string(product.getID()), amount);
                    return;
                }
            }
        }
    }
    if(findClient==0)
    {
        std::cout << "Ce client n'est pas dans notre magasin" << std::endl;
        return;
    }
    if(findProduct==0)
    {
        std::cout << "Ce produit n'appartient pas au magasin" << std::endl;
    }
}

void Magasin::validateOrder(Order order)
{
    if(order.getProduct().size()==0)
    {
        std::cout << "Le panier de ce client est vide." << std::endl;
        return;
    }
    for(int i = 0; i< order.getProduct().size(); i++)
    {
        if(order.getAmount()[i] > searchProduct(order.getProduct()[i].getTitle())->getAmount())
        {
            std::cout << "Quantite voulue trop importante par rapport au stock du magasin." << std::endl;
            return;
        }
        upadateAmount( order.getProduct()[i].getTitle(), searchProduct(order.getProduct()[i].getTitle())->getAmount()-order.getAmount()[i]);
    }
    order.getClient()->emptyCart();
    setOrderStatus(order, 1);
}

void Magasin::setOrderStatus(Order order, bool state)
{
    order.setStatus(state);
    if(state == 1)
    {
        Order *o = new Order(order);
        _orders.push_back(o);
        order.setStatus(1);
        std::cout << "La commande a bien ete validee !" << std::endl;
    }
}

void Magasin::dispOrder()
{
    std::cout << "COMMANDES VALIDEES: " << std::endl;
    for (int i = 0; i < _orders.size(); i++)
        std::cout << *_orders[i] << std::endl;
}

void Magasin::dispClientOrder(std::string name)
{
    std::cout << "COMMANDES VALIDEES DE : " << name << std::endl;
    for (int i = 0; i < _orders.size(); i++)
        if(_orders[i]->getClient()->getName() == name)
            std::cout << *(_orders[i]) << std::endl;
}

bool Magasin::searchInCart(Client client, std::string name)
{
    for(int i=0; i<client.getCart().size(); i++)
        if(client.getCart()[i].getTitle()==name)
            return true;
    return false;
}

bool Magasin::checkAmount(std::string name, int amount)
{  
    if(searchProduct(name)->getAmount() >= amount)
        return true;
    return false;    
}

Magasin::~Magasin()
{
    std::vector<Product*>::iterator it;
    for(it = _products.begin(); it != _products.end(); it++)
        delete(*it);
    std::vector<Client*>::iterator it2;
    for(it2 = _clients.begin(); it2 != _clients.end(); it2++)
        delete(*it2);
}