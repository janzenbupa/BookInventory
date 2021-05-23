// BookInventory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "DbConnection.h"
#include "SignIn.h"
#include <stdio.h>
#include <iostream>
#include <exception>


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

		std::vector<DbConnection::Book> books = con.GetBooks();

		std::vector<DbConnection::Author> authors = con.GetAuthors();

		std::string userName, password;

		std::cout << "Enter username: \n";
		std::cin >> userName;
		std::cout << "Enter password: ";
		std::cin >> password;

		bool loggedIn = signIn.VerifySignIn(userName, password);
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
