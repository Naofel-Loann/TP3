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
	Product merguez("Merguez", "Merguez pas cher", 20, 14.99);
	Product tel("Telephone", "Iphone 14", 30, 150.99);

	store.addProduct(fraise);
	store.addProduct(merguez);
	store.addProduct(tel);

	store.addClient(&client1);
	store.addClient(&client2);

	store.addToCart(client2, tel);
	store.addToCart(client2, fraise);
	store.addToCart(client1, merguez);

	std::cout << "Quantite merguez disponible : " << store.searchProduct("Merguez").getAmount() << std::endl;
	store.modifyAmount(client1, merguez, 5);

	Order orderC1(&client1);
	Order orderC2(&client2);

	store.validateOrder(orderC1);	
	std::cout << client1;
	//CREATION DU MENU
	/*int choice = 0;
	while (choice == 0)
	{
		std::cout << "--------------------------------------------------------------" << std::endl;
		std::cout << "		   Choisissez une option" << std::endl;
		std::cout << "--------------------------------------------------------------" << std::endl;
		std::cout << "1  -	Gestion du magasin" << std::endl;
		std::cout << "2  -	Gestion des utillisateurs" << std::endl;
		std::cout << "3  -	Gestion des commandes" << std::endl;

		std::cin >> choice;
		if(choice < 1 || choice > 3)
		{
			std::cout << "Le choix n'est pas valide. Recommencez." << std::endl;
			choice = 0;
		}
	}

	if(choice == 1)
	{
		int choice2 = 0;
		while (choice2 == 0)
		{
			std::cout << "--------------------------------------------------------------" << std::endl;
			std::cout << "		   Gestion du magasin" << std::endl;
			std::cout << "--------------------------------------------------------------" << std::endl;
			std::cout << "1  -  Ajouter un produit au magasin" << std::endl;
			std::cout << "2  -	Afficher tous les produits du magasin" << std::endl;
			std::cout << "3  -	Afficher un produit" << std::endl;
			std::cout << "4  -	Mettre à jour la quantite d'un produit" << std::endl;
			
			std::cin >> choice2;
			if(choice2 < 1 || choice2 > 4)
			{
				std::cout << "Le choix n'est pas valide. Recommencez." << std::endl;
				choice2 = 0;
			}
		}
	}

	if(choice == 2)
	{
		int choice2 = 0;
		while (choice2 == 0)
		{
			std::cout << "--------------------------------------------------------------" << std::endl;
			std::cout << "		   Gestion des utilisateurs" << std::endl;
			std::cout << "--------------------------------------------------------------" << std::endl;
			std::cout << "1  -	Ajouter un client" << std::endl;
			std::cout << "2  -	Afficher tous les clients" << std::endl;
			std::cout << "3  -	Afficher un client" << std::endl;
			std::cout << "4  -	Ajouter un produit au panier d'un client" << std::endl;
			std::cout << "5  -	Supprimer un produit du panier d'un client" << std::endl;
			std::cout << "6  -	Modifier la quantité d'un produit du panier d'un client" << std::endl;
				
			std::cin >> choice2;
			if(choice2 < 1 || choice2 > 6)
			{
				std::cout << "Le choix n'est pas valide. Recommencez." << std::endl;
				choice2 = 0;
			}
		}		
	}

	if(choice == 3)
	{
		int choice2 = 0;
		while (choice2 == 0)
		{
			std::cout << "--------------------------------------------------------------" << std::endl;
			std::cout << "		   Gestion des commandes" << std::endl;
			std::cout << "--------------------------------------------------------------" << std::endl;
			std::cout << "1  -	Valider une commande" << std::endl;
			std::cout << "2  -	Mettre à jour le statut d'une commande" << std::endl;
			std::cout << "3  -	Afficher toutes les commandes validees" << std::endl;
			std::cout << "4  -	Afficher toutes les commandes d'un client" << std::endl;
				
			std::cin >> choice2;
			if(choice2 < 1 || choice2 > 4)
			{
				std::cout << "Le choix n'est pas valide. Recommencez." << std::endl;
				choice2 = 0;
			}
		}		
	}*/
}