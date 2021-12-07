#include <iostream>
#include "magasin.hpp"
#include "Client.hpp"
int main()
{
	Magasin magasin;
	Client client1("Loann", "Kamli");
	Product fraise("Fraise", "fraise pas cher", 10, 2.99);
	Product merguez("Merguez", "Merguez pas cher", 20, 14);
	Product tel("Telephone", "Iphone 14", 30, 150);
	client1.addProduct(merguez);
	client1.addProduct(tel);
	client1.updateAmount("Merguez", 3);
	std::cout << client1 << std::endl;
}