#include "service.hpp"


manager::manager()
{

}

void manager::add()
{
	string temp;
	color(3);
	cout << "��ӭʹ��ѧ����Ϣ¼����" << endl;
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
	for (;;)
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
	cout << "ѧ����Ϣ:" << endl;
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
	cout << "��ӭʹ��ѧ����Ϣ��ѯ��" << endl;
	color(14);
	cout << "��������Ҫ��ѯ��ѧ����ѧ�Ż�����";
	color();
	cin >> test;
	search_all(test);
	if (sel_database.empty())
	{
		color(12);
		cout << "δ��ѯ�����ѧ����Ϣ��" << endl;
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
	cout << "��ӭʹ��ѧ����Ϣɾ����" << endl;
	color(14);
	cout << "��������Ҫɾ����ѧ����ѧ�Ż�����";
	color();
	cin >> test;
	search_all(test);
	if (sel_database.empty())
	{
		color(12);
		cout << "δ��ѯ�����ѧ����Ϣ��" << endl;
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
		cout << "��ѯ���������������Ľ������β�����" << endl << "(A)ɾ��ȫ��,(N)��������,����������ɾ����Ӧѧ����Ϣ,��Ҫɾ��������Ϣ���ÿո�ָ�" << endl;
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
					cout << "�����ѳ���" << endl;
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
					cout << "���벻�Ϸ�";
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
		cout << "��ɾ����Щѧ����Ϣ������yȷ��" << endl;
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
			cout << "�����ѳ���" << endl;
			return;
		}
	}
	else
	{
		color(11);
		cout << list_head(1);
		setcolor_output(1);
		color(6);
		cout << "��ɾ����ѧ����Ϣ������yȷ��" << endl;
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
			cout << "�����ѳ���" << endl;
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
	cout << "��ӭʹ��ѧ����Ϣ�޸���" << endl;
	color(14);
	cout << "��������Ҫɾ����ѧ����ѧ�Ż�����";
	color();
	cin >> test;
	search_all(test);
	if (sel_database.empty())
	{
		color(12);
		cout << "δ��ѯ�����ѧ����Ϣ��" << endl;
		return;
	}
	if (sel_database.size() > 1)
	{
		color(11);
		cout << list_head(1);
		setcolor_output(1);
		color(6);
		cout << "��ѯ���������������Ľ������ѡ����Ҫ�޸�����ѧ������Ϣ" << endl;
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
				cout << "���벻�Ϸ�";
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
	cout << "�����ĸ�ѧ����Ϣ������yȷ��" << endl;
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
		cout << "�����ѳ���" << endl;
		return;
	}
}
}

void manager::show()
{
	color(14);
	cout << "��ӡ����ѧ����ѧ����Ϣ";
	color(11);
	cout << list_head();
	color(14);
	for (student x : database)
		cout << x.show_all_ele() << endl;
	cout << "ȫ����Ϣ��ӡ���" << endl;
	clc();
	cout << "����������˳�" << endl;
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