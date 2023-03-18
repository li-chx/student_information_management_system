#include "global.h"

int login()
{
	encipher* checker = &enci;
	ifstream in;
	in.open("code.txt", ios::in);
	try
	{
		if (!in.is_open())
		{
			throw - 1;
		}
		else
		{
			char ch;
			in >> ch;
			if (in.eof())
				throw - 2;
		}
	}
	catch (int error_code)
	{
		in.close();
		switch (error_code)
		{
		case -1:
			color(12);
			cout << "系统找不到密码相关文件，可能是第一次使用或者重置密码" << endl;
			color(14);
			cout << "请创建一个管理员账户" << endl;
			color();
			break;
		case -2:
			color(12);
			cout << "管理员身份文件无效，需要重新创建管理员账户" << endl;
			color();
			break;
		default:
			color(4);
			cout << "出现未知错误";
			return -1;
		}
		string codea, codeb, username;
	begin:
		color(14);
		cout << "用户名:";
		cin >> username;
		cout << "密码:";
		cin >> codea;
		cout << "请再次输入密码:";
		cin >> codeb;
		if (codea != codeb)
		{
			color(4);
			cout << "两次输入密码不一致" << endl;
			color(14);
			goto begin;
		}
		ofstream out("code.txt");
		out << username << " " << checker->ascii_to_sha1(username + codea);
		out.close();
		color(2);
		cout << "账户" << username << "已创建"<<endl;
		color();
		return 1;
	}
	string username, code, temp;
	color(2);
	cout << "欢迎进入学生信息管理系统" << endl;
	for(int i=0;i<3;i++)
	{
		in.seekg(ios::beg);
		color(14);
		cout << "用户名:";
		color();
		cin >> username;
		color(14);
		cout << "密码:";
		color();
		cin >> code;
		code = checker->ascii_to_sha1(username + code);
		code = username + " " + code;
		for (;;)
		{
			getline(in, temp);
			if (temp == code)
			{
				in.close();
				color(2);
				cout << "登陆成功，欢迎回来" << username << endl;
				color();
				return 0;
			}
			if (in.eof())
			{
				if (i == 2)
				{
					color(4);
					cout << "失败次数过多,想要重置密码，请删除文件code.txt";
					in.close();
					return -1;
				}
				color(12);
				cout << "抱歉，请重试" << endl;
				color();
				break;
			}
		}
	}
	return -1;
}
int menu()
{
	string temp;
	color(14);
	cout << "--------------菜单--------------" << endl;

		cout << "1.添加学生信息\n2.查询学生信息\n3.删除学生信息\n4.修改学生信息\n5.显示学生信息\n0.退出系统" << endl;
		for (;;)
		{
			cin >> temp;
			if (temp.length() == 1)
			{
				if (temp[0] <= '6' && temp[0] >= '0')
				{
					break;
				}
				else
					cout << "请重新输入" << endl;
			}
			else
			{
				cout << "请重新输入" << endl;
			}
		}
	return temp[0] - '0';
}