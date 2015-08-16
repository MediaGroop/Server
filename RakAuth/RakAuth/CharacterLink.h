#pragma once
#include <string>
#include "odb\core.hxx"
using namespace std;

#pragma db object
class CharacterLink{
public:

	CharacterLink(string acc, string n, int id): acc_name_(acc), char_name_(n), serverId_(id){};
	
	CharacterLink(){};
	
	~CharacterLink(){};
	
	const string& login() const
	{
		return this->acc_name_;
	};
	
	const int& server() const
	{
		return this->serverId_;
	};

	const string& name() const
	{
		return this->char_name_;
	};

private:
	friend class odb::access;

	#pragma db id auto
	unsigned long id_;

	int serverId_;
	std::string char_name_;
	std::string acc_name_;
};