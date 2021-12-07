#include "magasin.hpp"

Magasin::Magasin(){}
Magasin::~Magasin(){}
void Magasin::addProduct(Product product)
{
    _products.push_back(product);
    static std::vector<Client> listClient;
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
        if(_products[i].getTitle()==name)
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
        if(_products[i].getTitle()==name)
        {
            _products[i].setAmount(amount);
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
    _clients.push_back(client);
}

void Magasin::dispClient()
{
    for (int i = 0; i < _clients.size(); i++)
    {
        std::cout << _clients[i].getFirstname() << "    " << _clients[i].getName() << std::endl; 
    }
}

void Magasin::searchClient(std::string name)
{
    bool find=0;
    for(int i=0; i < _clients.size(); i++)
    {
        if(_clients[i].getName()==name || std::to_string(_clients[i].getId())==name)
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

void Magasin::addToCart(Client client, Product product)
{
    bool find=0;
    for(int i=0; i < _clients.size(); i++)
    {
        if(_clients[i].getName()==client.getName() || std::to_string(_clients[i].getId())==client.getId())
        {
            std::cout << _clients[i] << std::endl;
            find=1;
        }
        if(find==0)
            std::cout << "Ce client n'est pas dans notre magasin; yuhn,j"
    }
}

