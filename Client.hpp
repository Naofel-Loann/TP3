#ifndef CLIENT_H
#define CLIENT_H
#include <vector>
#include <sstream>
#include "Product.hpp"

class Client
{
public:
	Client(std::string fristname, std::string name);
	~Client();
	int getID();
	std::string getFirstname();
	std::string getName();
	std::vector<Product> getCart();
	std::string dispCart();
	void addProduct(Product& product);
	void emptyCart();
	void delProduct(std::string name);
	void updateAmount(std::string name, int amount);
private:
	int _id;
	std::string _firstname;
	std::string _name;
	std::vector<Product> _cart;
	std::vector<int> _amount;
};
std::ostream &operator<<(std::ostream &flux,  Client& client);

#endif 