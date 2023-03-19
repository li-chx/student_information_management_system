#include "stu_info.hpp"

student::student(string inum, string iname, bool igender, unsigned int iage, array<int, 2>igrade_class, string iaddress, string iPhone_number)
{
	num = inum;
	name = iname;
	gender = igender;
	age = iage;
	grade_class = igrade_class;
	address = iaddress;
	Phone_number = iPhone_number;
}

string student::show_all_ele()
{
	string ans;
	ans = info_list(num,name,gender,age,grade_class,address,Phone_number);
	return ans;
}

bool student::check(string chnum, string chname)
{
	if (chnum != "" && chname != "")
	{
		if (num == chnum && name == chname)
			return true;
		else
			return false;
	}
	if (num == chnum)
		return true;
	if (name == chname)
		return true;
	return false;
}

string student::rnum()
{
	return num;
}

string student::rname()
{
	return name;
}

bool student::rgender()
{
	return gender;
}

unsigned int student::rage()
{
	return age;
}

array<int, 2> student::gra_cla()
{
	return grade_class;
}
