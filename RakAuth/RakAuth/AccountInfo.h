#pragma once
#include <string>
#include "odb\core.hxx"
using namespace std;

#pragma db object
class AccountInfo{
public:
	AccountInfo(string l, string pass, string ma, bool pr, bool b): login_(l), password_(pass),
		mail_(ma), authorized_(false), premium_(pr), beta_(b){
	};

	const string& login() const
	{
		return this->login_;
	}

	const string& password() const
	{
		return password_;
	}

	const string& mail() const
	{
		return mail_;
	}

	const bool& premium() const
	{
		return premium_;
	}

	const bool& beta() const
	{
		return beta_;
	}

	//Dynamic field
	bool authorized_;

private:
	AccountInfo(){};
	friend class odb::access;
	
	#pragma db id
	string login_;

	string password_;
	string mail_;
	
	bool premium_; // pay2play implemetation
	bool beta_; // beta test implemetation

};