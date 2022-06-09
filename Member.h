#pragma once
#include <string>
class Member
{
private:
public:
	Member(std::string name, std::string type);
	std::string	name, type;
	std::string getName();
	std::string getType();
};
