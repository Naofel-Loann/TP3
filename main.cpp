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
void restore(Magasin &store);

int main()
{
	Magasin store;
	restore(store);	
	//CODE A DECOMMENTER POUR LES TEST
	
	/*Client client1("Loann", "Kamli");
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
	store.addToCart(client2, merguez);
	store.addToCart(client1, merguez);
	store.modifyAmount(client2, fraise, 8);
	store.modifyAmount(client2, merguez, 4);
	store.modifyAmount(client1, merguez, 5);

	Order ordertest(&client1);
	store.validateOrder(store.searchClient(client1.getName()));
	Order ordertest2(&client2);
	store.validateOrder(store.searchClient(client2.getName()));*/

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
	save(store);
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
	char delim = ',';

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
		Client *client = store.getClient()[i];
		int id = client->getID();
		std::string name = client->getName();
		std::string firstname = client->getFirstname();
		std::vector<std::string> productName;
		std::vector<int> quantity = client->getAmount();
		for(int j =0 ; j< client->getCart().size(); j++)
			productName.push_back(client->getCart()[j].getTitle());

		clientsFile << firstname << delim << name << delim;
		if(productName.size() != 0)
		{
			for(int j = 0; j< client->getCart().size()-1 ; j++)
				clientsFile << productName[j] << ';';
			clientsFile << productName[productName.size()-1] << delim ;
		}
		else
			clientsFile << '0' << delim << '0';
		if(quantity.size() != 0)
		{
			for(int j = 0; j< quantity.size()-1 ; j++)
				clientsFile << quantity[j] << ';';
			clientsFile << quantity[quantity.size()-1];
		}
		clientsFile << std::endl;
	}
	clientsFile.close();


	//Sauvegarde des commandes
	path = "save/orders.csv";
	std::ofstream ordersFile{ path, std::ios::trunc };
	for (int i = 0; i < store.getOrder().size(); i++)
	{
		Order *order = store.getOrder()[i];
		int id = order->getID();
		std::string clientName = order->getClient()->getName();
		std::vector<std::string> productsName;
		std::vector<int> productQuantity = order->getAmount();
		bool status = order->getStatus();
		for(int j=0; j< order->getProduct().size(); j++)
			productsName.push_back(order->getProduct()[j].getTitle());
		
		ordersFile << clientName << delim;

		if(productsName.size() != 0)
		{
			for(int j=0; j< productsName.size()-1; j++)
				ordersFile << productsName[j] << ';';
			ordersFile << productsName[productsName.size()-1] << delim;
		}
		if(productQuantity.size() != 0)
		{
			for(int j=0; j< productQuantity.size()-1; j++)
				ordersFile << productQuantity[j] << ';';
			ordersFile << productQuantity[productQuantity.size()-1] << delim;
		}
		ordersFile << status << std::endl;
	}
	ordersFile.close();
}


void restore(Magasin &store)
{
	/////////////////////CHARGEMENT DES PRODUITS//////////////////////////////////
	std::string fname = "save/products.csv";
	std::vector<std::vector<std::string>> productsContent;
	std::vector<std::string> row;
	std::string line, word;
	std::vector<Product*> productsList;
	std::string title, desc;
	float price;
	int stock;

	std::fstream file (fname, std::ios::in);
	if(file.is_open())
	{
		while(std::getline(file, line))
		{
			row.clear();
			std::stringstream str(line);
			while(getline(str, word, ','))
				row.push_back(word);
			productsContent.push_back(row);
		}
	}
	else
	{
		return;
	}
	for(int i=0;i<productsContent.size();i++) //Pour chaque ligne
	{
		title = productsContent[i][0];
		desc = productsContent[i][1];
		price = std::stof(productsContent[i][2]);
		stock = std::stoi(productsContent[i][3]);
		Product product(title, desc, stock, price);
		Product *p = new Product(product);
		productsList.push_back(p);
	}
	store.setProducts(productsList);
	/////////////////////CHARGEMENT DES CLIENTS//////////////////////////////////
	fname = "save/clients.csv";
	std::vector<std::vector<std::string>> clientsContent;
	row.erase( row.begin(), row.end() );;
	std::vector<Client*> clientsList;
	std::string firstname, name;

	std::fstream clientfile (fname, std::ios::in);
	if(clientfile.is_open())
	{
		while(std::getline(clientfile, line))
		{
			row.clear();
			std::stringstream str(line);
			while(getline(str, word, ','))
				row.push_back(word);
			clientsContent.push_back(row);
		}
	}
	else
	{
		std::cout<<"Impossible d'ouvrir la sauvegarde des clients." << std::endl;
		return;
	}

 
	for(int i=0;i<clientsContent.size();i++) //Pour chaque ligne
	{
		std::vector<Product> clientProduct; //vecteur qui stock les produits dans le panier du client
		std::vector<int> clientQuantity; //vecteur qui stock les quantités des produits dans le panier du client
		firstname = clientsContent[i][0]; 
		name = clientsContent[i][1];
		
		std::stringstream str(clientsContent[i][2]); 
		while(getline(str, word, ';')) //stockage des produits dans un vecteur
			clientProduct.push_back(*store.searchProduct(word)); //ajout des produits dans un vecteur

		std::stringstream str2(clientsContent[i][3]); 
		while(getline(str2, word, ';')) //stockage des quantités des produits dans un vecteur
			clientQuantity.push_back(std::stoi(word)); //ajout des quantités dans un vecteur
		
		Client client(firstname, name);
		client.addCart(clientProduct);
		client.addQuantity(clientQuantity);
		Client *c = new Client(client);
		clientsList.push_back(c);
	}
	store.setClients(clientsList);

/////////////////////CHARGEMENT DES COMMANDES//////////////////////////////////
	fname = "save/orders.csv";
	std::vector<std::vector<std::string>> ordersContent;
	row.erase( row.begin(), row.end() );;
	std::vector<Order*> ordersList;

	std::fstream ordersFile (fname, std::ios::in);
	if(ordersFile.is_open())
	{
		while(std::getline(ordersFile, line))
		{
			row.clear();
			std::stringstream str(line);
			while(getline(str, word, ','))
				row.push_back(word);
			ordersContent.push_back(row);
		}
	}
	else
	{
		return;
	}
	for(int i=0;i<ordersContent.size();i++) //Pour chaque ligne
	{
		std::vector<Product> ordersProduct; //vecteur qui stock les produits de la commande
		std::vector<int> ordersQuantity; //vecteur qui stock les quantités des produits  de la commande 
		
		name = ordersContent[i][0];

		std::stringstream str(ordersContent[i][1]); 
		while(getline(str, word, ';')) //stockage des produits dans un vecteur
			ordersProduct.push_back(*store.searchProduct(word)); //ajout des produits dans un vecteur

		std::stringstream str2(ordersContent[i][2]); 
		while(getline(str2, word, ';')) //stockage des quantités des produits dans un vecteur
			ordersQuantity.push_back(std::stoi(word)); //ajout des quantités dans un vecteur
		
		bool status = (ordersContent[i][3] == "1");

		Order order(store.searchClient(name));
		order.setCart(ordersProduct);
		order.setQuantity(ordersQuantity);
		order.setStatus(status);
		Order *o = new Order(order);
		ordersList.push_back(o);
	}
	store.setOrders(ordersList);
}