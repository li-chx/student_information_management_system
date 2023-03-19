#pragma once
#include "global.hpp"
using namespace std;
class student;
class manager
{
public:
	manager();
	void add();
	void search();
	void del();
	void change();
	void show();
	~manager();
private:
	list<student>database;
	list<student>::iterator first;
};
extern manager manager_sys;