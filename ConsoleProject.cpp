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
	for (int i = 0; i < 25; i++)
	{
		printf("%d:%s;%d\n",i,d.SetIndex(i),d.GetIndex(d.SetIndex(i)));
	}
	getch();
	return 0;
}
