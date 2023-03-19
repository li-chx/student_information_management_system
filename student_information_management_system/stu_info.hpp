#pragma once
#include "global.hpp"
using namespace std;
class student
{
public:
	student() = default;
	student(string inum, string iname, bool igender, unsigned int iage, array<int, 2>igrade_class, string iaddress, string iPhone_number);
	string show_all_ele();
	bool check(string chnum, string chname);
	string rnum();
	string rname();
	bool rgender();
	unsigned int rage();
	array<int, 2> gra_cla();
private:
	string num;
	string name;
	bool gender;//0ÄĞ1Å®
	unsigned int age;
	array<int, 2>grade_class;
	string address;
	string Phone_number;
};