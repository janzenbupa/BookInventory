#pragma once
#include <string>


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
};
