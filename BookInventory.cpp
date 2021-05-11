// BookInventory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "DbConnection.h"
#include <stdio.h>
#include <iostream>
#include <exception>


int main()
{

	try
	{
 		DbConnection con;

		con.ConnectToDatabase(
			"DESKTOP-O0690I6@BookInventory",
			"",
			""
		);

		std::vector<DbConnection::Book> books = con.GetBooks();

		std::vector<DbConnection::Author> authors = con.GetAuthors();
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
