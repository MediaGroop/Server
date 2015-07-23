#pragma once
#include <functional>
#include <map>
struct CommandListener
{
private:
	static std::map<char*, std::function<void(char*)>> _handlers;
public:
	static void handle(char*);
	static void addHandler(char*, std::function<void(char*)>);
	static void removeHandler(char*);
};