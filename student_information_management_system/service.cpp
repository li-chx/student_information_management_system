#include "service.hpp"

manager::manager()
{

}


void manager::add()
{
	string temp;
	color(3);
	cout << "��ӭʹ��ѧ����Ϣ¼����"<<endl;
	color(14);
	cout << "������ϣ���Ժ��ַ�ʽ¼��ѧ����Ϣ��" << endl;
	cout << "(1)¼�뵥��ѧ����Ϣ(Ĭ��)\n(2)���ļ���ʽ¼����ѧ������Ϣ\n����1��2";
	color();
	cin >> temp;
	if (temp == "2")
	{
		
	}
	string num;
	string name;
	bool gender = false;//0��1Ů
	unsigned int age;
	array<int, 2>grade_class = { 0,0 };
	string address;
	string Phone_number;

	color(14);
	cout << "������0/8��ѧ��ѧ��:";
	color();
	cin >> num;
	color(14);
	cout << "������1/8��ѧ������:";
	color();
	cin >> name;
	color(14);
	cout << "������2/8��ѧ���Ա�:(��/Ů)";
	for(;;)
	{
		color();
		cin >> temp;
		if (temp == "��" || temp == "Ů")
			break;
		color(12);
		cout << "����Ƿ�,����������";
	}
	if (temp == "Ů")
		gender = true;
	color(14);
	cout << "������3/8��ѧ������:(����������)";
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
			cout << "����Ƿ�,����������";
		}
	}
	age = atoi(temp.c_str());

	color(14);
	cout << "������4/8��ѧ���꼶:(����������)";
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
			cout << "����Ƿ�,����������";
		}
	}
	grade_class[0] = atoi(temp.c_str());

	color(14);
	cout << "������5/8��ѧ���༶:(����������)";
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
			cout << "����Ƿ�,����������";
		}
	}
	grade_class[1] = atoi(temp.c_str());

	color(14);
	cout << "������6/8��ѧ����ͥ��ַ:";
	color();
	cin >> address;
	color(14);
	cout << "������7/8��ѧ���ֻ��绰:";
	color();
	cin >> Phone_number;
	color(14);
	student stu{ num, name, gender, age, grade_class, address, Phone_number };
	database.push_back(stu);
	color(14);
	cout << "¼�����" << endl;
	cout << "ѧ����Ϣ:"<<endl;
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
	cout << "��ӭʹ��ѧ����Ϣ��ѯ��" << endl;
	color(14);
	cout << "��������Ҫ��ѯ��ѧ����ѧ�Ż�����";
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
		cout << "Ϊ��ѯ�����ѧ����Ϣ��" << endl;
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
