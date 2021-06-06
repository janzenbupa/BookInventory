#pragma once
#include <string>
#include <SQLAPI.h>
#include "Inventory.h"
#include <iostream>
#include <vector>

class Inventory;

class DbConnection
{

public:

	void ConnectToDatabase(const std::string databaseServer, const std::string userName, const std::string password);

	void ConnectToDatabase(const std::string database, const std::string server, const std::string userName, const std::string password);

	void DisconnectFromDatabase();

	std::vector<Inventory::Book> GetBooks();

	std::vector<Inventory::Author> GetAuthors();

	bool LogIn(std::string userName, std::string password);

	bool InsertAuthor(std::string firstName, std::string lastName);

	bool InsertBook(std::string title, std::string publishDate, std::string isbn, long long int authorId);
};