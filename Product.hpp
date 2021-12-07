#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>

class Product
{
public:
	Product();
	Product(std::string title, std::string desc, int amount, float price);
	std::string getTitle();
	std::string getDesc();
	int getAmount();
	float getPrice();
	void setAmount(int amount);
	~Product();
private:
	std::string _title;
	std::string _desc;
	int _amount;
	float _price;
};

std::ostream &operator<<(std::ostream &flux,  Product& product);
#endif