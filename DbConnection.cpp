#include "DbConnection.h"
#include <string>
#include <SQLAPI.h>
#include <iostream>
#include <vector>

SAConnection sqlCon;
SACommand sqlCmd(&sqlCon);

void DbConnection::ConnectToDatabase(const std::string databaseServer, const std::string userName, const std::string password)
{
	sqlCon.Connect(
		databaseServer.c_str(),
		userName.c_str(),
		password.c_str(),
		SA_SQLServer_Client
	);
}
void DbConnection::ConnectToDatabase(const std::string database, const std::string server, const std::string userName, const std::string password)
{
	sqlCon.Connect(
		(database + server).c_str(),
		userName.c_str(),
		password.c_str(),
		SA_SQLServer_Client
	);
}

void DbConnection::DisconnectFromDatabase()
{
	sqlCon.Disconnect();
}


std::vector<Inventory::Book> DbConnection::GetBooks()
{
	std::vector<Inventory::Book> books;

	const SAString cmdText = "SELECT * FROM [dbo].[Books]";

	sqlCmd.setCommandText(_TSA(cmdText));

	sqlCmd.Execute();

	while (sqlCmd.FetchNext())
	{
		Inventory::Book book;
		book.Id = sqlCmd.Field(_TSA("Id")).asLong();
		book.Title = sqlCmd.Field(_TSA("Title")).asString().GetMultiByteChars();
		book.ISBN = sqlCmd.Field(_TSA("ISBN")).asString().GetMultiByteChars();
		book.PublishDate = sqlCmd.Field(_TSA("PublishDate")).asString().GetMultiByteChars();
		book.AuthorId = sqlCmd.Field(_TSA("AuthorId")).asLong();

		books.push_back(book);
	}

	return books;


}

std::vector<Inventory::Author> DbConnection::GetAuthors()
{
	std::vector<Inventory::Author> authors;

	const SAString cmdText = "SELECT * FROM [dbo].[Authors]";

	sqlCmd.setCommandText(_TSA(cmdText));

	sqlCmd.Execute();

	while (sqlCmd.FetchNext())
	{
		Inventory::Author author;
		author.Id = sqlCmd.Field(_TSA("Id")).asLong();
		author.FirstName = sqlCmd.Field(_TSA("FirstName")).asString().GetMultiByteChars();
		author.LastName = sqlCmd.Field(_TSA("LastName")).asString().GetMultiByteChars();

		authors.push_back(author);
	}

	return authors;


}

bool DbConnection::LogIn(std::string userName, std::string password)
{
	const SAString cmdText = "SELECT * FROM [dbo].[Account] WHERE [UserName] = :1";

	sqlCmd.setCommandText(_TSA(cmdText));

	sqlCmd.Param(1).setAsString() = _TSA(userName.c_str());

	sqlCmd.Execute();

	while (sqlCmd.FetchNext())
	{
		std::string user = sqlCmd.Field(_TSA("UserName")).asString().GetMultiByteChars();
		std::string userPass = sqlCmd.Field(_TSA("UserPassword")).asString().GetMultiByteChars();

		if (user.empty() || userPass.empty())
		{
			return false;
		}

		if (userPass != password)
		{
			return false;
		}

		return true;
	}
}

bool DbConnection::InsertAuthor(std::string firstName, std::string lastName)
{
	try
	{
		sqlCmd.setCommandText(_TSA("InsertAuthor"));
		sqlCmd.Param(_TSA("firstName")).setAsString() = _TSA(firstName.c_str());
		sqlCmd.Param(_TSA("lastName")).setAsString() = _TSA(lastName.c_str());

		sqlCmd.Execute();

		return true;
	}
	catch(int error)
	{
		return false;
	}
}

bool DbConnection::InsertBook(std::string title, std::string publishDate, std::string isbn, std::string firstName, std::string lastName)
{
	try
	{
		sqlCmd.setCommandText(_TSA("InsertBook"));
		sqlCmd.Param(_TSA("title")).setAsString() = _TSA(title.c_str());
		sqlCmd.Param(_TSA("publishDate")).setAsString() = _TSA(publishDate.c_str());
		sqlCmd.Param(_TSA("isbn")).setAsString() = _TSA(isbn.c_str());
		sqlCmd.Param(_TSA("authorFirstName")).setAsString() = _TSA(firstName.c_str());
		sqlCmd.Param(_TSA("authorLastName")).setAsString() = _TSA(lastName.c_str());

		sqlCmd.Execute();

		return true;
	}
	catch (int exception)
	{
		return false;
	}

	return true;
}