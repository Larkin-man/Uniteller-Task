#include "UnitellerClass.hpp"
//#pragma hdrstop
//#pragma argsused

#include <tchar.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>

int main()
//{
//int _tmain(int argc, _TCHAR* argv[])
{
	UnitellerID tst;
	//printf("%s %s\n",da,UnitellerID::Alphabet);
	//for (i = 0; i < 25; i++)
	//	printf("%d:%s;%d\n",i,d.SetIndex(i),d.GetIndex(d.SetIndex(i)));
	tst.SetID("V7");
	//printf("V7\n%s<<%d ",d.FIDS,d.Length);

	tst.SetID("G1-A5-H9");
	printf("G1-A5-H9=%d\n",0);
	//printf("%s<<\n",tst.FIDS);
	tst.SetID("G1-A5-H9-I2-J3-K4-N6-L8-C7-O8DFSFS");
	printf("\nG1-A5-H9-I2-J3-K4-N6-L8-C7-O8DFSFS=%d",0);
	//printf("\n%s<<\n",d.FIDS);

	printf("%s++\n",tst++);
	printf("%s++\n",tst++);

	tst.SetID("Z8");
	printf("Z8\n%s<<%d ",tst++,0);
	printf("++\n%s<<%d ",tst++,0);
	printf("++\n%s<<%d ",tst++,0);

	tst.SetID("A8-Z8");
	printf("A8-Z8\n%s<<%d ",tst++, 0);
	printf("++\n%s<<%d ",tst++, 0);
	printf("++\n%s<<%d ",tst++, 0);

	tst.SetID("Z9-Z9");
	printf("Z9-Z9\n%s<<%d ",tst++, 0);
	printf("++\n%s<<%d ",tst++, 0);

	tst.SetID("Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z7");
	printf("++\n%s<<%d ",tst++, 0);
	printf("++\n%s<<%d ",tst++, 0);
	printf("++\n%s<<%d ",tst++, 0);

	_getch();
	return 0;
}
