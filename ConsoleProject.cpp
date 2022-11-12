#include <System.hpp>
#include "UnitellerClass.hpp"
#pragma hdrstop
#pragma argsused

#include <tchar.h>
#include <stdio.h>
#include <conio.h>

int _tmain(int argc, _TCHAR* argv[])
{
	AnsiString dd;
	UnitellerID d;
	//printf("%s %s\n",da,UnitellerID::Alphabet);
	int i;
	for (i = 0; i < 25; i++)
	{
		printf("%d:%s;%d\n",i,d.SetIndex(i),d.GetIndex(d.SetIndex(i)));
	}
	printf("%d=A1 ",d.SetID("A1"));
	printf("%d=B2 ",d.SetID("B2"));
	printf("%d=Z9 ",d.SetID("Z9"));
	printf("%d=A1-A1 ",d.SetID("A1-A1"));
	printf("%d=A1-A2 ",d.SetID("A1-A2"));
	printf("%d=A2-A1 ",d.SetID("A2-A1"));
	printf("%d=A1-A1-A1 ",d.SetID("A1-A1-A1"));
	unsigned long int p = 1;
	for (i = 0; i < 10; i++)
	{
		p *=171;
		printf("%d ",p);
	}
	getch();
	return 0;
}
