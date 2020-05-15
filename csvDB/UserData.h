#pragma once
#include <string>

struct UserData {
	UserData(std::string name, std::string number);
	std::string name;
	std::string number;
};