#include "service.hpp"


manager::manager()
{

}

void manager::add()
{
	string temp;
	color(3);
	cout << "欢迎使用学生信息录入向导" << endl;
	color(14);
	cout << "请问你希望以何种方式录入学生信息？" << endl;
	cout << "(1)录入单个学生信息(默认)\n(2)以文件方式录入多个学生的信息\n输入1或2";
	color();
	cin >> temp;
	if (temp == "2")
	{

	}
	string num;
	string name;
	bool gender = false;//0男1女
	unsigned int age;
	array<int, 2>grade_class = { 0,0 };
	string address;
	string Phone_number;

	color(14);
	cout << "（进度0/8）学生学号:";
	color();
	cin >> num;
	color(14);
	cout << "（进度1/8）学生姓名:";
	color();
	cin >> name;
	color(14);
	cout << "（进度2/8）学生性别:(男/女)";
	for (;;)
	{
		color();
		cin >> temp;
		if (temp == "男" || temp == "女")
			break;
		color(12);
		cout << "输入非法,请重新输入";
	}
	if (temp == "女")
		gender = true;
	color(14);
	cout << "（进度3/8）学生年龄:(阿拉伯数字)";
	for (;;)
	{
		color();
		cin >> temp;
		auto test = [](string age)->bool {
			if (age.length() == 0 || age.length() >= 4)
				return false;
			for (char x : age)
			{
				if ('0' <= x && x <= '9')
					continue;
				return false;
			}
			return true;
		};
		if (test(temp))
			break;
		else
		{
			color(12);
			cout << "输入非法,请重新输入";
		}
	}
	age = atoi(temp.c_str());

	color(14);
	cout << "（进度4/8）学生年级:(阿拉伯数字)";
	for (;;)
	{
		color();
		cin >> temp;
		auto test = [](string age)->bool {
			if (age.length() == 0 || age.length() >= 3)
				return false;
			for (char x : age)
			{
				if ('0' <= x && x <= '9')
					continue;
				return false;
			}
			return true;
		};
		if (test(temp))
			break;
		else
		{
			color(12);
			cout << "输入非法,请重新输入";
		}
	}
	grade_class[0] = atoi(temp.c_str());

	color(14);
	cout << "（进度5/8）学生班级:(阿拉伯数字)";
	for (;;)
	{
		color();
		cin >> temp;
		auto test = [](string age)->bool {
			if (age.length() == 0 || age.length() >= 3)
				return false;
			for (char x : age)
			{
				if ('0' <= x && x <= '9')
					continue;
				return false;
			}
			return true;
		};
		if (test(temp))
			break;
		else
		{
			color(12);
			cout << "输入非法,请重新输入";
		}
	}
	grade_class[1] = atoi(temp.c_str());

	color(14);
	cout << "（进度6/8）学生家庭地址:";
	color();
	cin >> address;
	color(14);
	cout << "（进度7/8）学生手机电话:";
	color();
	cin >> Phone_number;
	color(14);
	student stu{ num, name, gender, age, grade_class, address, Phone_number };
	database.push_back(stu);
	color(14);
	cout << "录入完成" << endl;
	cout << "学生信息:" << endl;
	color(11);
	cout << list_head();
	color(14);
	cout << info_list(num, name, gender, age, grade_class, address, Phone_number) << endl;
	return;
}

void manager::search()
{
	string test, ans;
	color(3);
	cout << "欢迎使用学生信息查询向导" << endl;
	color(14);
	cout << "请输入想要查询的学生的学号或名字";
	color();
	cin >> test;
	search_all(test);
	if (sel_database.empty())
	{
		color(12);
		cout << "未查询到相关学生信息！" << endl;
		return;
	}
	color(11);
	cout << list_head();
	setcolor_output();
}

void manager::del()
{
	vector<list<student>::iterator>sel_database_tem;
	vector<int>sel_database_color_tem;
	string test, ans;
	color(3);
	cout << "欢迎使用学生信息删除向导" << endl;
	color(14);
	cout << "请输入想要删除的学生的学号或名字";
	color();
	cin >> test;
	search_all(test);
	if (sel_database.empty())
	{
		color(12);
		cout << "未查询到相关学生信息！" << endl;
		return;
	}
	string delstatus = "";
	vector<int>del_ele;
	if (sel_database.size() > 1)
	{
		color(11);
		cout << list_head(1);
		setcolor_output(1);
		color(6);
		cout << "查询到多条符合条件的结果，如何操作？" << endl << "(A)删除全部,(N)撤销操作,或输入数字删除对应学生信息,想要删除多条信息可用空格分隔" << endl;
		for (;;)
		{
			color();
			clc();
			getline(cin, delstatus);
			if (delstatus.length() == 1)
			{
				if (delstatus[0] == 'A')
				{
					for (int i = 0; i < sel_database.size(); i++)
						del_ele.push_back(i);
					break;
				}
				if (delstatus[0] == 'N')
				{
					color(14);
					cout << "操作已撤销" << endl;
					return;
				}
			}

			for (char x : delstatus)
			{
				if ('1' <= x && x <= sel_database.size() + '0')
				{
					del_ele.push_back(x - '0' - 1);
				}
				else
				{
					if (x == ' ')
						continue;
					color(14);
					cout << "输入不合法";
					continue;
				}
			}
			break;
		}
	}
	else
		del_ele.push_back(0);
	for (int i = 0; i < del_ele.size(); i++)
	{
		sel_database_tem.push_back(sel_database[i]);
		sel_database_color_tem.push_back(sel_database_color[i]);
	}
	sel_database.clear(), sel_database_color.clear();
	sel_database = sel_database_tem, sel_database_color = sel_database_color_tem;
	if (sel_database.size() > 1)
	{
		color(11);
		cout << list_head(1);
		setcolor_output(1);
		color(6);
		cout << "将删除这些学生信息，输入y确认" << endl;
		char x;
		x = getchar();
		if (x == 'y' || x == 'Y')
		{
			for (list<student>::iterator it : sel_database)
				database.erase(it);
		}
		else
		{
			color(14);
			cout << "操作已撤销" << endl;
			return;
		}
	}
	else
	{
		color(11);
		cout << list_head(1);
		setcolor_output(1);
		color(6);
		cout << "将删除该学生信息，输入y确认" << endl;
		char x;
		clc();
		x = getchar();
		if (x == 'y' || x == 'Y')
		{
			for (list<student>::iterator it : sel_database)
				database.erase(it);
		}
		else
		{
			color(14);
			cout << "操作已撤销" << endl;
			return;
		}
	}
}

void manager::change()
{
	vector<list<student>::iterator>sel_database_tem;
	vector<int>sel_database_color_tem;
	string test, ans;
	string choice;
	int fin_choice;
	color(3);
	cout << "欢迎使用学生信息修改向导" << endl;
	color(14);
	cout << "请输入想要删除的学生的学号或名字";
	color();
	cin >> test;
	search_all(test);
	if (sel_database.empty())
	{
		color(12);
		cout << "未查询到相关学生信息！" << endl;
		return;
	}
	if (sel_database.size() > 1)
	{
		color(11);
		cout << list_head(1);
		setcolor_output(1);
		color(6);
		cout << "查询到多条符合条件的结果，请选择想要修改哪名学生的信息" << endl;
		for (;;)
		{
			color();
			clc();
			cin >> choice;
			auto test_all_num = [](string test) {
				for (char x : test)
					if (!(0 <= x && x <= 9))
						return false;
				return true;
			};
			if (test_all_num(choice))
			{
				fin_choice = atoi(choice.c_str()) - 1;
			}
			else
			{
				color(14);
				cout << "输入不合法";
				continue;
			}

			break;
		}
	}
	else
		fin_choice = 0;
	sel_database_tem.push_back(sel_database[fin_choice]);
	sel_database_color_tem.push_back(sel_database_color[fin_choice]);
	sel_database.clear(), sel_database_color.clear();
	sel_database = sel_database_tem, sel_database_color = sel_database_color_tem;
	color(11);
	cout << list_head(1);
	setcolor_output(1);
	color(6);
	cout << "将更改该学生信息，输入y确认" << endl;
	char x;
	clc();
	x = getchar();
	if (x == 'y' || x == 'Y')
	{
		for (list<student>::iterator it : sel_database)
			database.erase(it);
	}
	else
	{
		color(14);
		cout << "操作已撤销" << endl;
		return;
	}
}
}

void manager::show()
{
	color(14);
	cout << "打印所有学生的学生信息";
	color(11);
	cout << list_head();
	color(14);
	for (student x : database)
		cout << x.show_all_ele() << endl;
	cout << "全部信息打印完毕" << endl;
	clc();
	cout << "输入任意键退出" << endl;
	char x = _getch();
}

manager::~manager()
{
}


void manager::search_all(string test)
{
	sel_database.clear();
	sel_database_color.clear();
	for (list<student>::iterator it = database.begin(); it != database.end(); it++)
	{
		if (it->check(test, test))
		{
			sel_database.push_back(it);
			sel_database_color.push_back(3);
			continue;
		}
		if (it->check(test, ""))
		{
			sel_database.push_back(it);
			sel_database_color.push_back(1);
		}
		if (it->check("", test))
		{
			sel_database.push_back(it);
			sel_database_color.push_back(2);
		}
	}
}
void manager::setcolor_output(bool nu)
{
	for (size_t i = 0; i < sel_database.size(); i++)
	{
		string number;
		number.push_back('(');
		number.push_back((char)(i + '0' + 1));
		number.push_back(')');
		list<student>::iterator it = sel_database[i];
		string left = it->show_all_ele();
		int mode = sel_database_color[i];
		switch (mode)
		{
		case 1:
		{
			string temp;
			temp.insert(0, left.c_str(), left.find('\t'));
			color(13);
			if (nu)
				temp.insert(0, number);
			cout << temp;
			color(14);
			temp.clear();
			temp.insert(0, left, left.find('\t'), left.length());
			cout << temp << endl;
			break;
		}
		case 2:
		{
			string temp;
			color(14);
			temp.insert(0, left.c_str(), left.find('\t'));
			if (nu)
				temp.insert(0, number);
			cout << temp;
			color(13);
			size_t i = 0;
			for (i = left.find('\t'); left[i] == '\t'; i++);
			temp.clear();
			temp.insert(0, left, left.find('\t'), left.find('\t', i) - 1);
			cout << temp;
			color(14);
			temp.clear();
			temp.insert(0, left, left.find('\t', i), left.length());
			cout << temp << endl;
			break;
		}
		case 3:
		{
			string temp;
			color(13);
			size_t i = 0;
			for (i = left.find('\t'); left[i] == '\t'; i++);
			temp.insert(0, left, 0, left.find('\t') + left.find('\t', i) - 1);
			if (nu)
				temp.insert(0, number);
			cout << temp;
			color(14);
			temp.clear();
			temp.insert(0, left, left.find('\t', i), left.length());
			cout << temp << endl;
			break;
		}
		}
	}
}