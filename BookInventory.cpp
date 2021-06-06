// BookInventory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "DbConnection.h"
#include "Inventory.h"
#include "SignIn.h"
#include <stdio.h>
#include <iostream>
#include <exception>

std::vector<Inventory::Book> GetBooks(DbConnection&);
std::vector<Inventory::Author> GetAuthors(DbConnection&);
void AddBook(DbConnection&, SignIn&);
void AddAuthor(DbConnection&, SignIn&);

int main()
{

	try
	{
		DbConnection con;
		SignIn signIn;

		con.ConnectToDatabase(
			"DESKTOP-O0690I6@BookInventory",
			"",
			""
		);

		int userInput;
		std::cout << "What would you like to do?\n1. View Books\n2. View Authors\n3. Add Book\n4. Add Author\n";
		std::cin >> userInput;

		switch (userInput)
		{
		case 1:
			GetBooks(con);
			break;
		case 2:
			GetAuthors(con);
			break;
		case 3:
			AddBook(con, signIn);
			break;
		case 4:
			AddAuthor(con, signIn);
			break;
		default:
			std::cout << "Could not understand choice.";
			break;
		};


		/*while (con.FetchNext())
		{
			std::cout << con.Field(("Id")).asString() << "\n";
		}*/

		//long columns = con.FieldCount();

		con.DisconnectFromDatabase();
	}

	catch (std::exception e)
	{
		std::cout << e.what();
	}
}

std::vector<Inventory::Book> GetBooks(DbConnection& con)
{
	std::vector<Inventory::Book> books = con.GetBooks();

	return books;
}

std::vector<Inventory::Author> GetAuthors(DbConnection& con)
{
	std::vector<Inventory::Author> authors = con.GetAuthors();

	return authors;
}

void AddBook(DbConnection& con, SignIn& signIn)
{
	std::string userName, password;

	std::cout << "Enter username: \n";
	std::cin >> userName;
	std::cout << "Enter password: ";
	std::cin >> password;

	bool loggedIn = signIn.VerifySignIn(userName, password);
}

void AddAuthor(DbConnection& con, SignIn& signIn)
{
	std::string userName, password;

	std::cout << "Enter username: \n";
	std::cin >> userName;
	std::cout << "Enter password: ";
	std::cin >> password;

	bool loggedIn = signIn.VerifySignIn(userName, password);
}
