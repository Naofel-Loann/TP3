#include "magasin.hpp"

Magasin::Magasin(){}
Magasin::~Magasin(){}
void Magasin::addProduct(Product& product)
{
    _products.push_back(&product);
}

void Magasin::display()
{
    for(int i=0; i < _products.size(); i++)
    {
        std::cout << _products[i];
    }
}

void Magasin::searchProduct(std::string name)
{
    bool find=0;
    for(int i=0; i < _products.size(); i++)
    {
        if(_products[i]->getTitle()==name)
        {
            std::cout << _products[i];
            find=1;
        }
    }
    if (find==0)
    {
        std::cout << "Aucun produit trouve a ce nom " << std::endl;
    }   
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

void Magasin::addClient(Client *client)
{
    _clients.push_back(client);
}

void Magasin::dispClient()
{
    for (int i = 0; i < _clients.size(); i++)
    {
        std::cout << _clients[i]->getID() << "    "<< _clients[i]->getFirstname() << "    " << _clients[i]->getName() << std::endl; 
    }
}

void Magasin::searchClient(std::string name)
{
    bool find=0;
    for(int i=0; i < _clients.size(); i++)
    {
        if(_clients[i]->getName()==name || std::to_string(_clients[i]->getID())==name)
        {
            std::cout << _clients[i] << std::endl;
            find=1;
        }
    }
    if (find==0)
    {
        std::cout << "Erreur: Aucun client trouve a ce nom " << std::endl;
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
            findClient=1;
            //std::cout << _clients[i]->getName() << _clients[i]->getFirstname() << std::endl;
            for(int j=0; j < _products.size(); j++)
            {
                if(_products[j]->getID()==product.getID())
                {
                    findProduct=1;
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
            //std::cout << _clients[i]->getName() << _clients[i]->getFirstname() << std::endl;
            for(int j=0; j < _products.size(); j++)
            {
                if(_products[j]->getID()==product.getID())
                {
                    findProduct=1;
                    _clients[i]->updateAmount(product.getTitle(), amount);
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