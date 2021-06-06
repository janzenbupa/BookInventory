#include "Inventory.h"
#include "DbConnection.h"
#include "SignIn.h"
#include <iostream>
#include <vector>


void Inventory::AddBook(DbConnection& con, SignIn& signIn)
{
	std::string userName, password;

	std::cout << "Enter username: \n";
	std::cin >> userName;
	std::cout << "Enter password: ";
	std::cin >> password;

	bool loggedIn = signIn.VerifySignIn(userName, password);
}

void Inventory::AddAuthor(DbConnection& con, SignIn& signIn)
{
	std::string userName, password;

	std::cout << "Enter username: \n";
	std::cin >> userName;
	std::cout << "Enter password: ";
	std::cin >> password;

	bool loggedIn = signIn.VerifySignIn(userName, password);

}