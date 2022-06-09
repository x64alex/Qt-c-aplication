#include "Issue.h"

Issue::Issue(std::string description, std::string status, std::string reporter, std::string solver): description{description},status{status},reporter{reporter},solver{solver}
{
}

std::string Issue::toStr()
{
	return this->description + " " + this->status + " " + this->reporter + " " + this->solver;
}

void Issue::resolve()
{
	this->status = "closed";
}

void Issue::setSolver(std::string solv)
{
	this->solver = solv;
}
