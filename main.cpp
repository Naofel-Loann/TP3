#include <iostream>
#include <string>
#include <ctype.h>
#include <fstream>
#include <set>
#include <cerrno>
#include "Magasin.hpp"
#include "Client.hpp"
#include "Order.hpp"


void Clear();
std::string read_input();
int choiceMenu(int min, int max);
int setQuantity();
int principalMenu();
float setPrice();
void save(Magasin &store);

int main()
{
	Magasin store;	
	//CODE A DECOMMENTER POUR LES TEST
	
	Client client1("Loann", "Kamli");
	Client client2("Younes", "Le Thies");

	Product fraise("Fraise", "fraise pas cher", 10, 2.99);
	Product merguez("Merguez", "Merguez pas cher", 20, 14.99);
	Product tel("Telephone", "Iphone 14", 30, 150.99);

	store.addProduct(fraise);
	store.addProduct(merguez);
	store.addProduct(tel);

	store.addClient(client1);
	store.addClient(client2);

	store.addToCart(client2, tel);
	store.addToCart(client2, fraise);
	store.addToCart(client1, merguez);

	save(store);
	//CREATION DU MENU
	while (1)
	{	
		int menu2=0;
		int menu = principalMenu();
		if(menu == 1)
		{
			int choice2 = 0;
			while (menu2==0)
			{
				std::cout << "--------------------------------------------------------------" << std::endl;
				std::cout << "		   Gestion du magasin" << std::endl;
				std::cout << "--------------------------------------------------------------" << std::endl;
				std::cout << "	1  -  	Ajouter un produit au magasin" << std::endl;
				std::cout << "	2  -	Afficher tous les produits du magasin" << std::endl;
				std::cout << "	3  -	Afficher un produit" << std::endl;
				std::cout << "	4  -	Mettre a jour la quantite d'un produit dans le magasin" << std::endl;
				std::cout << "	5  -	Retour au menu principal" << std::endl;

				/*Client client2("Younes", "Le Thies");
				Product fraise("Fraise", "fraise pas cher", 10, 2.99);
				store.addClient(&client2);
				store.addProduct(fraise);*/

				choice2 = choiceMenu(1, 5);
				switch (choice2)
				{
					case 1:
					{
						Clear();
						std::string title, desc;
						int amount;
						float price;
						std::cout << "Entrez le titre du produit: ";
						title = read_input();
						std::cout << "Entrez la description du produit: ";
						std::getline(std::cin, desc);
						std::cout << "Entrez le prix du produit: ";
						price = setPrice();
						std::cout << "Entrez la quantite disponible du produit: ";
						amount = setQuantity();
						Product produit(title, desc, amount, price);
						store.addProduct(produit);
						std::cout << "Produit ajoute au magasin !" << std::endl;
						menu=1;
						break;
					}
					case 2:
						Clear();
						store.dispProducts();
						menu=1;
						break;
					case 3:
					{
						Clear();
						std::string name;
						std::cout << "Quel produit voulez vous afficher ?" << std::endl;
						std::cin >> name;
						if(store.productExist(name))
							std::cout << *(store.searchProduct(name)) << std::endl;
						else
							std::cout << "Aucun produit n'a ete trouve a ce nom." << std::endl;
						menu=1;
						break;
					}
					case 4:
					{
						Clear();
						std::string name;
						int quantite;
						std::cout << "De quel produit voulez vous modifier la quantite ?" << std::endl;
						std::cin >> name;
						if(!store.productExist(name))
						{
							std::cout << "Aucun produit n'a ete trouve a ce nom." << std::endl;
							menu=1;
							break;
						}
						std::cout << "Quelle est la nouvelle quantite de ce produit ?" << std::endl;
						std::cin >> quantite;
						std::cout << "Ancienne quantite :" << store.searchProduct(name)->getAmount() << std::endl;
						store.upadateAmount(name, quantite);
						std::cout << "Nouvelle quantite :" << store.searchProduct(name)->getAmount() << std::endl;
						menu=1;
						break;
					}
					case 5:
					{
						Clear();
						menu2=1;
						break;
					}
				}
			}
		}

		if(menu == 2)
		{
			int choice2 = 0;
			while (menu2 == 0)
			{
				std::cout << "--------------------------------------------------------------" << std::endl;
				std::cout << "		   Gestion des utilisateurs" << std::endl;
				std::cout << "--------------------------------------------------------------" << std::endl;
				std::cout << "	1  -	Creer un client" << std::endl;
				std::cout << "	2  -	Afficher tous les clients du magasin" << std::endl;
				std::cout << "	3  -	Afficher un client" << std::endl;
				std::cout << "	4  -	Ajouter un produit au panier d'un client" << std::endl;
				std::cout << "	5  -	Supprimer un produit du panier d'un client" << std::endl;
				std::cout << "	6  -	Modifier la quantite d'un produit du panier d'un client" << std::endl;
				std::cout << "	7  -	Vider le panier d'un client" << std::endl;
				std::cout << "	8  -	Retour au menu principal" << std::endl;
					
				choice2 = choiceMenu(1, 8);
				switch (choice2)
				{
					case 1:
					{
						Clear();
						std::string firstname, name;
						std::cout << "Entrez le prenom du client: ";
						firstname = read_input();
						std::cout << "Entrez le nom du client: ";
						std::getline(std::cin, name);
						Client client(firstname, name);
						store.addClient(client);
						std::cout << "Client cree !" << std::endl;
						break;
					}
					case 2:
						Clear();
						store.dispClient();
						break;
					case 3:
					{
						Clear();
						std::string name;
						std::cout << "Quel est le nom du client que vous voulez afficher ? : ";
						name = read_input();
						if(store.clientExist(name))
							std::cout << *(store.searchClient(name)) << std::endl;
						else
							std::cout << "Aucun client n'a ete trouve a ce nom." << std::endl;
						break;
					}
					case 4:
					{
						Clear();
						std::string product_name, client_name;
						std::cout << "Quel produit voulez vous ajouter ? : ";
						product_name = read_input();
						if(!store.productExist(product_name))
						{
							std::cout << "Aucun produit n'a ete trouve a ce nom: " << product_name << std::endl;
							break;
						}
						std::cout << std::endl << "A quel client voulez vous l'ajouter ? : " ;
						std::getline(std::cin, client_name);
						if(!store.clientExist(client_name))
						{
							std::cout << "Aucun client n'a ete trouve au nom de " << client_name << std::endl;
							break;
						}
						Client client = *store.searchClient(client_name);
						Product product = *store.searchProduct(product_name);
						store.addToCart(client, product);
						std::cout << "Produit bien ajoute au panier ! " << std::endl;
						break;
					}
					case 5:
					{
						Clear();
						std::string product_name, client_name;
						std::cout << std::endl << "Dans le panier de quel client ? : " ;
						client_name = read_input();
						if(!store.clientExist(client_name))
						{
							std::cout << "Aucun client n'a ete trouve au nom de " << client_name << std::endl;
							break;
						}
						std::cout << "Quel produit voulez vous supprimer ? : ";
						std::getline(std::cin, product_name);
						if(!store.searchInCart(*store.searchClient(client_name), product_name))
						{
							std::cout << "Ce produit n'est pas dans le panier du client." << std::endl;
							break;
						}
						store.delInCart(*store.searchClient(client_name), *store.searchProduct(product_name));
						std::cout << "Produit supprime !" << std::endl;
						break;
					}
					case 6:
					{
						Clear();
						std::string product_name, client_name;
						int newQuantite;
						std::cout << std::endl << "Dans le panier de quel client ? : " ;
						client_name = read_input();
						if(!store.clientExist(client_name))
						{
							std::cout << "Aucun client n'a ete trouve au nom de " << client_name << std::endl;
							break;
						}
						std::cout << "Quel produit voulez vous modifier ? : ";
						std::getline(std::cin, product_name);
						if(!store.searchInCart(*store.searchClient(client_name), product_name))
						{
							std::cout << "Ce produit n'est pas dans le panier du client." << std::endl;
							break;
						}
						std::cout << "Quelle est la nouvelle quantite ? : ";
						std::cin >> newQuantite;
						if(!store.checkAmount(product_name, newQuantite))
						{
							std::cout << "Impossible. Quantite superieur a celle disponible en stock" << std::endl;
							break;
						}
						store.modifyAmount(*store.searchClient(client_name), *store.searchProduct(product_name), newQuantite);
						std::cout << "Quantite bien modifie ! " << std::endl;
						break;
					}
					case 7:
					{
						Clear();
						std::string client_name;
						std::cout << std::endl << "Le panier de quel client ? : " ;
						client_name = read_input();
						if(!store.clientExist(client_name))
						{
							std::cout << "Aucun client n'a ete trouve au nom de " << client_name << std::endl;
							break;
						}
						store.searchClient(client_name)->emptyCart();
						std::cout << "Le panier a bien ete vide." << std::endl;
						break;
					}
					case 8:
						menu2=1;
						break;
				}
			}		
		}

		if(menu == 3)
		{
			int choice2 = 0;
			while (menu2 == 0)
			{
				std::cout << "--------------------------------------------------------------" << std::endl;
				std::cout << "		   Gestion des commandes" << std::endl;
				std::cout << "--------------------------------------------------------------" << std::endl;
				std::cout << "1  -	Valider une commande" << std::endl;
				std::cout << "2  -	Afficher toutes les commandes validees" << std::endl;
				std::cout << "3  -	Afficher toutes les commandes d'un client" << std::endl;
				std::cout << "4  -	Retour au menu principal" << std::endl;
					
				choice2 = choiceMenu(1, 8);
				switch (choice2)
				{
					case 1:
					{
						Clear();
						std::string client_name;
						std::cout << "Le panier de quel client voulez vous valider ?" << std::endl;
						client_name = read_input();
						if(!store.clientExist(client_name))
						{
							std::cout << "Aucun client n'a ete trouve au nom de " << client_name << std::endl;
							break;
						}
						Order order(store.searchClient(client_name));
						store.validateOrder(order);
						break;
					}
					case 2:
					{
						Clear();
						store.dispOrder();
						break;
					}
					case 3:
					{
						Clear();
						std::string client_name;
						std::cout << "Les commandes de quel client voulez vous afficher ?" << std::endl;
						client_name = read_input();
						if(!store.clientExist(client_name))
						{
							std::cout << "Aucun client n'a ete trouve au nom de " << client_name << std::endl;
							break;
						}
						store.dispClientOrder(client_name);
						break;
					}
					case 4:
						Clear();
						menu2=1;
						break;
				}
			}		
		}
		if (menu == 4)
		{
			break;
		}
		
	}	
}

std::string read_input()
{
	std::cin.ignore();
	std::string temp;
	std::getline(std::cin, temp);
	return temp;
}

int choiceMenu(int min, int max)
{
	int choice=0;
	std::cout << "Que voulez vous choisir? ";
	std::cin >> choice;
	while (!choice || choice < min || choice > max)
	{
		std::cin.clear();
    	std::cin.ignore(256, '\n');
		std::cout << "Choix " << choice << " non valide. Recommencez : ";
		std::cin >> choice;
	}
	if (choice >= min && choice <= max)
	{
		return choice;
	}
}

int setQuantity()
{
	int temp;
	std::cin >> temp;
	while (!temp)
	{
		std::cin.clear();
    	std::cin.ignore(256, '\n');
		std::cout << "La quantite doit etre entiere, numerique et positive. Recommencez : ";
		std::cin >> temp;
	}
	return int(temp);
}

float setPrice()
{
	float temp;
	std::cin >> temp;
	while (!temp)
	{
		std::cin.clear();
    	std::cin.ignore(256, '\n');
		std::cout << "Le prix numerique et positive. Recommencez : ";
		std::cin >> temp;
	}
	return temp;
}

int principalMenu()
{
	Clear();
	std::cout << "--------------------------------------------------------------" << std::endl;
	std::cout << "		   Choisissez une option" << std::endl;
	std::cout << "--------------------------------------------------------------" << std::endl;
	std::cout << "1  -	Gestion du magasin" << std::endl;
	std::cout << "2  -	Gestion des utillisateurs" << std::endl;
	std::cout << "3  -	Gestion des commandes" << std::endl;
	std::cout << "4  -	Fermer le magasin" << std::endl;
	int menu = choiceMenu(1, 4);
	return menu;
}

void Clear()
{
#if defined _WIN32
    system("cls");
    //clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
#elif defined (__APPLE__)
    system("clear");
#endif
}

void save(Magasin &store)
{
	char delim = ';';

	//Sauvegarde des produits
	const char* path = "save/products.csv";
	std::ofstream productsFile{ path, std::ios::trunc };
	for (int i = 0; i < store.getProduct().size(); i++)
	{
		std::string title = store.getProduct()[i]->getTitle();
		std::string desc = store.getProduct()[i]->getDesc();
		float price = store.getProduct()[i]->getPrice();
		int stock = store.getProduct()[i]->getAmount();
		productsFile << title << delim << desc << delim << price << delim << stock << std::endl;
	}
	productsFile.close();

	//Sauvegarde des clients
	path = "save/clients.csv";
	std::ofstream clientsFile{ path, std::ios::trunc };
	for (int i = 0; i < store.getClient().size(); i++)
	{
		int id = store.getClient()[i]->getID();
		std::string name = store.getClient()[i]->getName();
		std::string firstname = store.getClient()[i]->getFirstname();
		std::vector<std::string> productName;
		std::vector<int> quantity;
		for(int j =0 ; j< store.getClient()[i]->getCart().size(); j++)
		{
			productName[j] =  store.getClient()[i]->getCart()[j].getTitle();
			quantity[j] =  store.getClient()[i]->getCart()[j].getAmount();
		}
		
		clientsFile << id << delim << firstname << delim << name << delim;
		if(productName.size() != 0)
		{
			for(int j = 0; j< productName.size()-1 ; j++)
				clientsFile << productName[i] << ',';
			clientsFile << productName[productName.size()-1];
		}

	}
	clientsFile.close();
	
}
