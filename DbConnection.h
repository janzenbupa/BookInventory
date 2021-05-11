#pragma once
#include <string>
#include <SQLAPI.h>
#include <iostream>
#include <vector>

class DbConnection
{

public:
	
	struct Book
	{
		int Id;
		std::string Title;
		std::string ISBN;
		std::string PublishDate;
		int AuthorId;
	};

	struct Author
	{
		int Id;
		std::string FirstName;
		std::string LastName;
	};

	void ConnectToDatabase(const std::string databaseServer, const std::string userName, const std::string password);

	void ConnectToDatabase(const std::string database, const std::string server, const std::string userName, const std::string password);

	void DisconnectFromDatabase();

	std::vector<Book> GetBooks();

	std::vector<Author> GetAuthors();
};