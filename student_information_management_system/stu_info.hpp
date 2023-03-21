#pragma once
#include "global.hpp"
using namespace std;
class student
{
public:
	student();
	student(string inum, string iname, bool igender, unsigned int iage, array<int, 2>igrade_class, string iaddress, string iPhone_number);
	void change_ele(vector<string> eles);
	string show_all_ele();
	bool check(string chnum, string chname);


	string rnum();
	string rname();
	bool rgender();
	unsigned int rage();
	array<int, 2> gra_cla();
private:
	string num;//学号
	string name;//姓名
	bool gender;//0男1女
	unsigned int age;//年龄
	array<int, 2>grade_class;//班级&年级
	string address;//地址
	string Phone_number;//电话
};