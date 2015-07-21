#pragma once
#include <map>

using namespace std;

#include "minIni.h"
#include "stdafx.h"
#include "FileManager.h"

class ConfigLoader{
private:
	ConfigLoader(){};
	~ConfigLoader(){};
public:
	 map <string, string> _vals;
	 static ConfigLoader& getInstance();
	 static void createDefault();
	 static void init();
	 static std::string getVal(std::string);
	 static int getIntVal(std::string);
};