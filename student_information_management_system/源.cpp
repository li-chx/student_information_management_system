#include "global.hpp"
//cout << "1.���ѧ����Ϣ\n2.��ѯѧ����Ϣ\n3.ɾ��ѧ����Ϣ\n4.�޸�ѧ����Ϣ\n5.��ʾѧ����Ϣ\n0.�˳�ϵͳ" << endl;
encipher enci;
manager manager_sys;
int main()
{
	manager_sys.loadinfo();
	color(2);
	errno_t err = 0;
	do
	{
		err = login();
		if(err==-1)
		{
			color();
			return -1;
		}
	} while (err != 0);
	for(;;)
	{
		err = menu();
		switch (err)
		{
		case 0:
			manager_sys.saveinfo();
			color();
			return 0;
		case 1:
			manager_sys.add();
			break;
		case 2:
			manager_sys.search();
			break;
		case 3:
			manager_sys.del();
			break;
		case 4:
			manager_sys.change();
			break;
		case 5:
			manager_sys.show();
			break;
		}
	}
}