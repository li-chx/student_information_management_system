#include "service.hpp"

manager::manager()
{

}


void manager::add()
{
	string temp;
	color(3);
	cout << "欢迎使用学生信息录入向导"<<endl;
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
	for(;;)
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
	for(;;)
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
	cout << "学生信息:"<<endl;
	color(11);
	cout << list_head();
	color(14);
	cout << info_list(num, name, gender, age, grade_class, address, Phone_number) << endl;
	return;
}

void manager::search()
{
	string test, ans;
	bool showhead = false;
	color(3);
	cout << "欢迎使用学生信息查询向导" << endl;
	color(14);
	cout << "请输入想要查询的学生的学号或名字";
	color();
	cin >> test;
	for (auto x : database)
	{
		if (x.check(test, ""))
		{
			string temp;
			ans = x.show_all_ele();
			color(11);
			if(!showhead)
				cout << list_head();
			showhead = true;
			temp.insert(0, ans.c_str(), ans.find('\t'));
			color(13);
			cout << temp;
			color(14);
			temp.clear();
			temp.insert(0, ans, ans.find('\t'), ans.length());
			cout << temp << endl;
		}
		if (x.check("", test))
		{
			string temp;
			ans = x.show_all_ele();
			color(11);
			if (!showhead)
				cout << list_head();
			showhead = true;
			color(14);
			temp.insert(0, ans.c_str(), ans.find('\t'));
			cout << temp;
			color(13);
			int i = 0;
			for (i = ans.find('\t'); ans[i] == '\t'; i++);
			temp.clear();
			temp.insert(0, ans, ans.find('\t'), ans.find('\t', i) - 1);
			cout << temp;
			color(14);
			temp.clear();
			temp.insert(0, ans, ans.find('\t', i), ans.length());
			cout << temp << endl;
		}
	}
	if (!showhead)
	{
		color(12);
		cout << "为查询到相关学生信息！" << endl;
	}
}

void manager::del()
{
}

void manager::change()
{
}

void manager::show()
{
}

manager::~manager()
{
}
