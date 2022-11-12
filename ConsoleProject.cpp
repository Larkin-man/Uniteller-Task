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
	d.SetID("G1-A5-H9-I2-J3-K4-N6-L8-C7-O8DFSFS");
	printf("\nG1-A5-H9-I2-J3-K4-N6-L8-C7-O8DFSFS=%d",d.Length);
	printf("\n%s<<\n",d.FIDS);

	printf("%s++\n",d++);
	printf("%s++\n",d++);

	d.SetID("Z8");
	printf("Z8\n%s<<%d ",d++,d.Length);
	printf("++\n%s<<%d ",d++,d.Length);
	printf("++\n%s<<%d ",d++,d.Length);

	d.SetID("A8-Z8");
	printf("A8-Z8\n%s<<%d ",d++, d.Length);
	printf("++\n%s<<%d ",d++, d.Length);
	printf("++\n%s<<%d ",d++, d.Length);

	d.SetID("Z9-Z9");
	printf("Z9-Z9\n%s<<%d ",d++, d.Length);
	printf("++\n%s<<%d ",d++, d.Length);

	d.SetID("Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z7");
	printf("++\n%s<<%d ",d++, d.Length);
	printf("++\n%s<<%d ",d++, d.Length);
	printf("++\n%s<<%d ",d++, d.Length);

	getch();
	return 0;
}
