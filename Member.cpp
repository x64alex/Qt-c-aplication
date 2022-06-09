#include "Member.h"

Member::Member(std::string name, std::string type):name{name},type{type}
{
}

std::string Member::getName()
{
	return this->name;
}

std::string Member::getType()
{
	return this->type;
}
