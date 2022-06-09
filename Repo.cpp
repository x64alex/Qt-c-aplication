#include "Repo.h"
#include <algorithm>
#include <fstream>

using namespace std;

Repo::Repo()
{
	this->loadFromFile();
}

void Repo::addIssue(Issue& i)
{
	this->issues.push_back(i);
	this->save();

}

void Repo::removeIssue(Issue& v)
{
	int i = 0;
	for (auto el : this->issues) {
		if (el.toStr() == v.toStr()) {
			this->issues.erase(this->issues.begin() + i);
			break;
		}
		i++;
	}
	this->save();

}

void Repo::loadFromFile()
{
	this->issues.clear();
	ifstream fin("2.txt");
	string description, status, reporter, solver;
	while (fin >> description >> status >> reporter >> solver) {
		Issue i{ description,status,reporter,solver };
		this->addIssue(i);
	}
	fin.close();
}

void Repo::save()
{
	ofstream fout("2.txt");
	for (auto el : this->issues) {
		fout << el.toStr()<<"\n";
	}
	fout.close();
}

void Repo::modify(int ix,string solv)
{
	if (ix >= 0) {
		this->issues[ix].resolve();
		this->issues[ix].setSolver(solv);
	}
	this->save();
}

bool compare(Issue i1, Issue i2) {
	if (i1.status == i2.status) {
		return i1.description < i2.description;
	}
	return i1.status < i2.status;
}

void Repo::sortV()
{

	std::sort(this->issues.begin(), this->issues.end(), compare);
}

std::vector<Issue> Repo::getIssues()
{
	return this->issues;
}
