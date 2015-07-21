#include "ConfigLoader.h"

ConfigLoader& ConfigLoader::getInstance()
{
	static ConfigLoader l;
	return l;
}

void ConfigLoader::createDefault(){
	static char str[64];
	getcwd(str, 64);
	FileManager::createFile(strcat(str, "\\config.ini"));

	minIni ini("config.ini");

	ini.put("Pooler", "Port", "66534");
	ini.put("Pooler", "Key", "topsecret");
	ini.put("Pooler", "MaxCons", "10");

	ini.put("Auth", "Port", "66535");
	ini.put("Auth", "MaxCons", "1000");

}

std::string ConfigLoader::getVal(std::string key)
{
	//LOG(INFO) << "iterating through map, size";
	for (map<string, string>::iterator ii = ConfigLoader::getInstance()._vals.begin(); ii != ConfigLoader::getInstance()._vals.end(); ++ii)
	{
		//LOG(INFO) << key + " " + (*ii).first;
		if ((*ii).first == key) {
			return (*ii).second;
		}
	}
	//LOG(INFO) << "end of iterating through map...";

	LOG(ERROR) << "There's no value with given name!";
	return NULL;
}

int ConfigLoader::getIntVal(std::string key)
{
	return atoi((getVal(key)).c_str());
}

void ConfigLoader::init(){
	if (FileManager::fileExists("config.ini")){
		minIni ini("config.ini");
		string s, section;
		for (int is = 0; section = ini.getsection(is), section.length() > 0; is++) {
			for (int ik = 0; s = ini.getkey(section, ik), s.length() > 0; ik++) {
				ConfigLoader::getInstance()._vals.insert(pair<string, string>(section + "-" + s, ini.gets(section, s)));
				LOG(INFO) << section + "-" + s + " " + ini.gets(section, s);
			}
		}
	}
	else
	{
		ConfigLoader::createDefault();
		ConfigLoader::init();
	}
}