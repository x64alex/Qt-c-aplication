#pragma once
#include <vector>
#include "Issue.h"
class Repo
{
private:
	std::vector<Issue> issues;
public:
	Repo();
	void addIssue(Issue &i);
	void removeIssue(Issue& i);
	void loadFromFile();
	void save();
	void modify(int ix, std::string solv);
	void sortV();
	std::vector<Issue> getIssues();
};

