#pragma once
#include <string>
#include <SQLAPI.h>
#include <iostream>

class SignIn
{
public:
	std::string userName;
	std::string password;
	bool isLoggedIn;

	bool VerifySignIn(std::string userName, std::string password);

private:
	bool CheckUserData(std::string userName, std::string password);
};