#include <iostream>
#include "magasin.hpp"
#include "Client.hpp"
int main()
{
	Magasin store;
	Client client1("Loann", "Kamli");
	Client client2("Younes", "Le Thies");

	Product fraise("Fraise", "fraise pas cher", 10, 2.99);
	Product merguez("Merguez", "Merguez pas cher", 20, 14);
	Product tel("Telephone", "Iphone 14", 30, 150);

	client1.addProduct(merguez);

	store.addProduct(fraise);
	store.addClient(&client1);
	store.addClient(&client2);
	store.addToCart(client2, fraise);
	store.modifyAmount(client2, fraise, 5);
	store.delInCart(client2, fraise);
	std::cout << client2;
}