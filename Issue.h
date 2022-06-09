#pragma once
#include <string>
class Issue
{
public:
	std::string description, status, reporter, solver;
	Issue(std::string description, std::string status, std::string reporter, std::string solver);
	std::string toStr();
	void resolve();
	void setSolver(std::string solv);
};

