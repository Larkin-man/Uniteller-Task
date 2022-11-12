#include <tchar.h>
		
const int ALLCHARS = 26; //букв в афавите
const int DISABLECHARS = 7; //количество запрещенных
const int ENABLECHARS = ALLCHARS - DISABLECHARS;
const int ALLNUMS = 9; //использовано цифр
const int ALLBLOCKS = 10; //Блоков индексов
const int IDSLEN = ALLBLOCKS * 3 - 1 + 1;
const int BLOCKMULT = ENABLECHARS * ALLNUMS;

typedef char TUID[2];

class UnitellerID
{
protected:
	TUID FID;
	static char Alphabet[ENABLECHARS];
	static char Disabled[DISABLECHARS];
	int FIndex;
	int GetPos(char symb);
	bool IfDisabled(char symb);

public:
	__fastcall UnitellerID();
	//__fastcall ~UnitellerID();
	int GetIndex(TUID ID1);
	char* SetIndex(int Index);
	void SetID(char *ID); //NULL TEMINAtED StriNg
	char FIDS[IDSLEN]; //nullterm
	int Length;
};            

//В идентификаторах никогда не должны присутствовать
//буквы «D», «F», «G», «J», «M», «Q», «V» и цифра «0».
char UnitellerID::Alphabet[] = "ABCEHIKLNOPRSTUWXYZ";
char UnitellerID::Disabled[] = "DFGJMQV";

__fastcall UnitellerID::UnitellerID()
{
	for (int i = 0; i < IDSLEN; i++)
		FIDS[i] = '\0';
    Length = 0;
}

//__fastcall UnitellerID::~UnitellerID() { }

int UnitellerID::GetIndex(TUID ID1)
{
	FIndex = 0;
	for (; FIndex < ENABLECHARS; FIndex++)
		if (Alphabet[FIndex] == ID1[0])
			break;
	FIndex *= ALLNUMS;
	FIndex += ID1[1] - '1';
	return FIndex;
}

char* UnitellerID::SetIndex(int Index)
{
	FIndex = Index % ALLNUMS;
	FID[1] = '1' + FIndex;
	FIndex = Index / ALLNUMS;
	FID[0] = Alphabet[FIndex];
	return FID;
}

void UnitellerID::SetID(char *ID)
{
	int i = 0;
	for (i = 0; i < IDSLEN; i += 3)
		if (ID[i] >= 'A' && ID[i] <= 'Z')
		{
			while (IfDisabled(ID[i]))
				ID[i] = ID[i] - 1;
			if (ID[i+1] >= '1' && ID[i+1] <= '9')
			{
				if (ID[i+2] != '-')
				{
					i += 3;
					break;
				}
			}
			else
				break;
		}
		else
			break;
	if (i > 0)
	{
		FIDS[i-1] = '\0';
		i -= 2;
		Length = i;
		for (; i >= 0; i--)
			FIDS[i] = ID[i];
	}
}

int UnitellerID::GetPos(char symb)
{
	int i = 0;
	for (; i < ENABLECHARS; i++)
	if (Alphabet[i] == symb)
		return i;
	return i;
}

bool UnitellerID::IfDisabled(char symb)
{
	int i = 0;
	for (; i < DISABLECHARS; i++)
	if (Disabled[i] == symb)
		return true;
	return false;
}
