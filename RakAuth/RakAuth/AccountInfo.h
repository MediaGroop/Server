#pragma once
#include <string>
using namespace std;

struct AccountInfo{
	string login;
	string password;
	string mail;
	bool authorized;
	bool premium; // pay2play implemetation
	bool beta; // beta test implemetation
};