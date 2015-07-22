#pragma once
#include <string>
#include "minIni.h"
#include "FileManager.h"

class ConfigLoader{
private:
	ConfigLoader(){};
	~ConfigLoader(){};
public:
	 map <std::string, std::string> _vals;
	 static ConfigLoader& getInstance();
	 static void createDefault(std::string);
	 static void init(std::string);
	 static std::string getVal(std::string);
	 static int getIntVal(std::string);
};