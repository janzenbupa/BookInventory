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


std::vector<DbConnection::Book> DbConnection::GetBooks()
{
	std::vector<DbConnection::Book> books;

	const SAString cmdText = "SELECT * FROM [dbo].[Books]";

	sqlCmd.setCommandText(_TSA(cmdText));

	sqlCmd.Execute();

	while (sqlCmd.FetchNext())
	{
		DbConnection::Book book;
		book.Id = sqlCmd.Field(_TSA("Id")).asLong();
		book.Title = sqlCmd.Field(_TSA("Title")).asString().GetMultiByteChars();
		book.ISBN = sqlCmd.Field(_TSA("ISBN")).asString().GetMultiByteChars();
		book.PublishDate = sqlCmd.Field(_TSA("PublishDate")).asString().GetMultiByteChars();
		book.AuthorId = sqlCmd.Field(_TSA("AuthorId")).asLong();

		books.push_back(book);
	}

	return books;


}

std::vector<DbConnection::Author> DbConnection::GetAuthors()
{
	std::vector<DbConnection::Author> authors;

	const SAString cmdText = "SELECT * FROM [dbo].[Authors]";

	sqlCmd.setCommandText(_TSA(cmdText));

	sqlCmd.Execute();

	while (sqlCmd.FetchNext())
	{
		DbConnection::Author author;
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