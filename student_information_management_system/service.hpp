#pragma once
#include "global.hpp"
using namespace std;
class student;
class manager
{
public:
	int loadinfo(string path = "data.txt");
	void saveinfo();
	void add();
	void search();
	void del();
	void change();
	void show();
private:
	void search_all(string test);
	void setcolor_output(bool nu = false);
	vector<list<student>::iterator>sel_database;
	vector<int>sel_database_color;
	list<student>database;

};
extern manager manager_sys;