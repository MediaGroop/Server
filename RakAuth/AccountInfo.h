#pragma once
#include <string>
#include "odb\core.hxx"
#include "easylogging++.h"
using namespace std;

#pragma db object
class AccountInfo{
public:
	AccountInfo(string l, unsigned char* pass, string ma, bool pr, bool b) : login_(l),
		mail_(ma), premium_(pr), beta_(b){
		for (int j = 0; j < 20; ++j)
			password_[j] = pass[j];
	};

	string& login()
	{
		return this->login_;
	}

	unsigned char* password()
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

	AccountInfo(){
		login_ = "";
		mail_ = "";
		premium_ = false;
		beta_ = false;
	};

private:
	friend class odb::access;

#pragma db id
	string login_;

#pragma db type("BYTEA")
	unsigned char password_[20];

	string mail_;

	bool premium_; // pay2play implemetation
	bool beta_; // beta test implemetation

};
