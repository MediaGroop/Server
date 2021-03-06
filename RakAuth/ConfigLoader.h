#pragma once
#include <string>
#include "minIni.h"
#include "FileManager.h"
#include <map>

class ConfigLoader{
private:
	std::map <std::string, std::string> _vals;
	ConfigLoader(){};
	~ConfigLoader(){};
public:
	 static ConfigLoader& getInstance();
	 static void createDefault(std::string);
	 static void init(std::string);
	 static std::string getVal(std::string);
	 static int getIntVal(std::string);
};