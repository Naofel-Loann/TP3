#include "magasin.hpp"

Magasin::Magasin(){}
Magasin::~Magasin(){}
void Magasin::addProduct(Product product)
{
    _products.push_back(product);
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