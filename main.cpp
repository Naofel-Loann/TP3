#include <iostream>
#include "magasin.hpp"
#include "Client.hpp"
#include "Order.hpp"
int main()
{
	Magasin store;
	Client client1("Loann", "Kamli");
	Client client2("Younes", "Le Thies");

	Product fraise("Fraise", "fraise pas cher", 10, 2.99);
	Product merguez("Merguez", "Merguez pas cher", 20, 14);
	Product tel("Telephone", "Iphone 14", 30, 150);

	store.addProduct(fraise);
	store.addProduct(merguez);
	store.addProduct(tel);

	store.addClient(&client1);
	store.addClient(&client2);

	store.addToCart(client2, tel);
	store.addToCart(client2, fraise);
	store.addToCart(client1, merguez);

	store.modifyAmount(client1, merguez, 5);
	
	Order orderC1(client1);
	Order orderC2(client2);


	//store.validateOrder(orderC1);
	store.validateOrder(orderC2);
	store.setOrderStatus(orderC1, 1);
	store.dispClientOrder("Le Thies");
}