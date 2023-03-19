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
	void search_all(string test);
	void setcolor_output(bool nu = false);
	vector<list<student>::iterator>sel_database;
	vector<int>sel_database_color;
	list<student>database;
	list<student>::iterator first;
};
extern manager manager_sys;