#include "UnitellerClass.hpp"
#pragma hdrstop
#pragma argsused

#include <tchar.h>
#include <stdio.h>
#include <conio.h>

int _tmain(int argc, _TCHAR* argv[])
{
	UnitellerID d;
	//printf("%s %s\n",da,UnitellerID::Alphabet);
	int i;
	//for (i = 0; i < 25; i++)
	//	printf("%d:%s;%d\n",i,d.SetIndex(i),d.GetIndex(d.SetIndex(i)));
	d.SetID("V7");
	printf("V7\n%s<<%d ",d.FIDS,d.Length);

	d.SetID("G1-A5-H9");
	printf("G1-A5-H9=%d\n",d.Length);
	printf("%s<<\n",d.FIDS);
	d.SetID("G1-A5-H9-I2-J3-K4-L5-N6-M7-O8DFSFS");
	printf("\nG1-A5-H9-I2-J3-K4-L5-N6-M7-O8DFSFS=%d",d.Length);
	printf("%s<<\n",d.FIDS);
	getch();
	return 0;
}
