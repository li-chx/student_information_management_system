#include "global.hpp"
void color(short x)	//�Զ��庯���ݲ����ı���ɫ 
{
	if (x >= 0 && x <= 15)//������0-15�ķ�Χ��ɫ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);	//ֻ��һ���������ı�������ɫ 
	else//Ĭ�ϵ���ɫ��ɫ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

string list_head(bool nu)
{
	string ans = "ѧ��\t\t����\t\t�Ա�\t����\t�꼶/�༶\t��ͥ��ַ\t\t�ֻ��绰\t\n";
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
	ans += (gender ? "Ů\t" : "��\t");

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