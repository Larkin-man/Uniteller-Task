#include <tchar.h>
		
const int ALLCHARS = 26; //букв в афавите
const int DISABLECHARS = 7; //количество запрещенных
const int ENABLECHARS = ALLCHARS - DISABLECHARS;
const int ALLNUMS = 9; //использовано цифр
const int ALLBLOCKS = 10; //Блоков индексов
const int IDSLEN = ALLBLOCKS * 3 - 1 + 1;

typedef char TUID[2];

class UnitellerID
{
private:
	TUID FID;
	static char Alphabet[ENABLECHARS];
	int FIndex;
	char FIDS[IDSLEN]; //nullterm

protected:
	int GetPos(char symb)
	{
		int i = 0;
		for (; i < ENABLECHARS; i++)
		if (Alphabet[i] == symb)
			return i;
		return i;
    }

public:
	__fastcall UnitellerID();
	__fastcall ~UnitellerID();	
	char ID[2];
	int GetIndex(TUID ID1);
	char* SetIndex(int Index);
	int SetID(char *ID); //NULL TEMINAtED StriNg
};            

//В идентификаторах никогда не должны присутствовать буквы «D», «F», «G», «J», «M», «Q», «V» и цифра «0».
char UnitellerID::Alphabet[] = "ABCEHIKLNOPRSTUWXYZ";

__fastcall UnitellerID::UnitellerID() { FIDS[IDSLEN-1] = '\0'; }

__fastcall UnitellerID::~UnitellerID() { }

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

int UnitellerID::SetID(char *ID)
{
	int i = 0;
	int idx = 0;
	for (i = 0; i < 3; i+=3)
	{
		if (ID[i] >= 'A' && ID[i] <= 'Z')
		{
			idx += GetPos(ID[i]) * ALLNUMS;
			if (ID[i+1] >= '1' && ID[i+1] <= '9' )
			{
				idx += ID[i+1] - '1';
				if (ID[i+2] != '-')
					break;
			}
			else
				break;
		}
		else
			break;
	}
	return idx;
}

				
