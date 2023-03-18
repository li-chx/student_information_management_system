#include "global.h"
encipher enci;
int main()
{
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
	menu();
}