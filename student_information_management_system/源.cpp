#include "global.hpp"
//cout << "1.添加学生信息\n2.查询学生信息\n3.删除学生信息\n4.修改学生信息\n5.显示学生信息\n0.退出系统" << endl;
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