#include "SignIn.h"
#include "DbConnection.h"
#include <string>
#include <iostream>

bool SignIn::VerifySignIn(std::string userName, std::string password)
{
	if (!CheckUserData(userName, password))
	{
		return false;
	}

	DbConnection con;

	if (con.LogIn(userName, password))
	{
		return true;
	}

	return false;
}

bool SignIn::CheckUserData(std::string userName, std::string password)
{
	if (userName.find(" ") != std::string::npos|| password.find(" ") != std::string::npos)
	{
		return false;
	}

	return true;
}