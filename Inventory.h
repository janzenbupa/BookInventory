#pragma once
#include "SignIn.h"
#include <string>
#include <vector>

class DbConnection;

class Inventory
{

public:
	struct Book
	{
		long long int Id;
		std::string Title;
		std::string ISBN;
		std::string PublishDate;
		long long int AuthorId;
	};

	struct Author
	{
		long long int Id;
		std::string FirstName;
		std::string LastName;
	};

	/*void AddBook(DbConnection& con, SignIn& signIn);
	void AddAuthor(DbConnection& con, SignIn& signIn);*/
};
