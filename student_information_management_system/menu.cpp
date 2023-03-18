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
			cout << "ϵͳ�Ҳ�����������ļ��������ǵ�һ��ʹ�û�����������" << endl;
			color(14);
			cout << "�봴��һ������Ա�˻�" << endl;
			color();
			break;
		case -2:
			color(12);
			cout << "����Ա����ļ���Ч����Ҫ���´�������Ա�˻�" << endl;
			color();
			break;
		default:
			color(4);
			cout << "����δ֪����";
			return -1;
		}
		string codea, codeb, username;
	begin:
		color(14);
		cout << "�û���:";
		cin >> username;
		cout << "����:";
		cin >> codea;
		cout << "���ٴ���������:";
		cin >> codeb;
		if (codea != codeb)
		{
			color(4);
			cout << "�����������벻һ��" << endl;
			color(14);
			goto begin;
		}
		ofstream out("code.txt");
		out << username << " " << checker->ascii_to_sha1(username + codea);
		out.close();
		color(2);
		cout << "�˻�" << username << "�Ѵ���"<<endl;
		color();
		return 1;
	}
	string username, code, temp;
	color(2);
	cout << "��ӭ����ѧ����Ϣ����ϵͳ" << endl;
	for(int i=0;i<3;i++)
	{
		in.seekg(ios::beg);
		color(14);
		cout << "�û���:";
		color();
		cin >> username;
		color(14);
		cout << "����:";
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
				cout << "��½�ɹ�����ӭ����" << username << endl;
				color();
				return 0;
			}
			if (in.eof())
			{
				if (i == 2)
				{
					color(4);
					cout << "ʧ�ܴ�������,��Ҫ�������룬��ɾ���ļ�code.txt";
					in.close();
					return -1;
				}
				color(12);
				cout << "��Ǹ��������" << endl;
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
	cout << "--------------�˵�--------------" << endl;

		cout << "1.���ѧ����Ϣ\n2.��ѯѧ����Ϣ\n3.ɾ��ѧ����Ϣ\n4.�޸�ѧ����Ϣ\n5.��ʾѧ����Ϣ\n0.�˳�ϵͳ" << endl;
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
					cout << "����������" << endl;
			}
			else
			{
				cout << "����������" << endl;
			}
		}
	return temp[0] - '0';
}