#include "global.hpp"
void color(short x)	//自定义函根据参数改变颜色 
{
	if (x >= 0 && x <= 15)//参数在0-15的范围颜色
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);	//只有一个参数，改变字体颜色 
	else//默认的颜色白色
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

string list_head(bool nu)
{
	string ans = "学号\t\t姓名\t\t性别\t年龄\t年级/班级\t家庭地址\t\t手机电话\t\n";
	if (nu)
		ans.insert(0, string("   "));
	return ans;
}

string info_list(string num, string name, bool gender, unsigned int age, array<int, 2>grade_class, string address, string Phone_number)
{
	string ans;
	if (num.length() < 8)
		ans.append(num + "\t\t");
	else
		ans.append(num + "\t");
	if (name.length() < 8)
		ans.append(name + "\t\t");
	else
		ans.append(name + "\t");
	ans += (gender ? "女\t" : "男\t");

	ans += to_string(age) + "\t" + to_string(grade_class[0]) + "/" + to_string(grade_class[1]) + "\t\t";
	if (address.length() < 8)
		ans.append(address + "\t\t\t" + Phone_number);
	else
		if (address.length() < 16)
			ans.append(address + "\t\t" + Phone_number);
		else
			ans.append(address + "\t" + Phone_number);
	return ans;
}

void clc()
{
	int ch = 0;
	while ((ch = getchar()) != EOF && ch != '\n')
	{
		;
	}
}

void clear()
{
	system("cls");
}