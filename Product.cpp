#include "Product.hpp"
#include <iostream>

Product::Product(){}
Product::~Product(){}
Product::Product(std::string title, std::string desc, int amount, float price): _title(title), _desc(desc), _amount(amount), _price(price)
{
    static int id=0;
    _id = id++;
}
int Product::getID()
{
    return _id;
}
std::string Product::getTitle()
{
    return _title;
}
std::string Product::getDesc()
{
    return _desc;
}
int Product::getAmount()
{
    return _amount;
}
float Product::getPrice()
{
    return _price;
}
void Product::setAmount(int amount)
{
    _amount = amount;
}

std::ostream &operator<<(std::ostream &flux,  Product& product)
{
    flux << " ID Produit: " << product.getID() << "\n Titre Produit: " << product.getTitle() << "\n Descirption Produit: " << product.getDesc() << "\n Prix Produit: " << product.getPrice() << "\n Quantite disponible: " <<  product.getAmount() << std::endl;
    return flux;
}
