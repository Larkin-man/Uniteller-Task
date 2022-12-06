#include <tchar.h>

const int ALLCHARS = 26; //букв в афавите
const int DISABLECHARS = 7; //количество запрещенных
const int ENABLECHARS = ALLCHARS - DISABLECHARS;
const int ALLNUMS = 9; //использовано цифр
const int ALLBLOCKS = 10; //Блоков индексов
const int IDSLEN = ALLBLOCKS * 3;
const int BLOCKMULT = ENABLECHARS * ALLNUMS;
const char FIRSTNUM = '1';
const char LASTNUM = '9';
const char DELIMITER = '-';

typedef char TUID[2];

class UnitellerID
{
protected:
	TUID FID;
	static const char Alphabet[ENABLECHARS+1];// = "ff";
	static const char Disabled[DISABLECHARS+1];
	int FIndex;
	int GetPos(char symb);
	bool IfDisabled(char symb);
	void Clear(int from = 0);

public:
	__fastcall UnitellerID();
	//__fastcall ~UnitellerID();
	int GetIndex(TUID ID1);
	char* SetIndex(int Index);
	void SetID(const char *ID);
	char FIDS[IDSLEN];
	int Length;
	const char* operator ++(); //префиксные
	const char* operator ++(int) //постфиксные
	{
		return this->operator ++();
	}
};

//В идентификаторах никогда не должны присутствовать
//буквы «D», «F», «G», «J», «M», «Q», «V» и цифра «0».
const char UnitellerID::Alphabet[] = "ABCEHIKLNOPRSTUWXYZ";
const char UnitellerID::Disabled[] = "DFGJMQV";

__fastcall UnitellerID::UnitellerID()
{
	Clear();
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
	FIndex += ID1[1] - FIRSTNUM;
	return FIndex;
}

char* UnitellerID::SetIndex(int Index)
{
	FIndex = Index % ALLNUMS;
	FID[1] = FIRSTNUM + FIndex;
	FIndex = Index / ALLNUMS;
	FID[0] = Alphabet[FIndex];
	return FID;
}

void UnitellerID::SetID(const char *ID)
{
	int i = 0;
	for (i = 0; i < IDSLEN; i += 3)
		if (ID[i] >= 'A' && ID[i] <= 'Z')
		{
			//while (IfDisabled(ID[i]))
			//	ID[i] = ID[i] - 1;
			if (ID[i+1] >= FIRSTNUM && ID[i+1] <= LASTNUM)
			{
				if (ID[i+2] != DELIMITER)
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
		FIDS[i-1] = 0;
		i -= 2;
		Length = i;
		for (; i >= 0; i--)
			FIDS[i] = ID[i];
	}
	Clear(Length+1);
}

const char* UnitellerID::operator ++()
{
	if (Length <= 0)
		return FIDS;
	int i = Length;
	for (; i >= 0; i -= 3)
	{
		if (FIDS[i] < LASTNUM)
		{
			FIDS[i]++;
			return FIDS;
		}    //9
		else if (FIDS[i-1] < Alphabet[ENABLECHARS-1])
		{
			FIDS[i-1] = Alphabet[GetPos(FIDS[i-1])+1];
            FIDS[i] = FIRSTNUM;
			return FIDS;
		}    //Z9
		else
		{
			FIDS[i-1] = Alphabet[0];
			FIDS[i] = FIRSTNUM;
		}
	}
	if (i < 0)
	{
		if (Length >= (IDSLEN-3))
		{   //Ну допустим вернем конечное значение
			for (i = 0; i < IDSLEN; i += 3)
			{
				FIDS[i] = Alphabet[ENABLECHARS-1];
				FIDS[i+1] = LASTNUM;
			}
			return FIDS;
		}
		FIDS[Length+1] = DELIMITER;
		Length += 3;
		FIDS[Length-1] = Alphabet[0];
		FIDS[Length] = FIRSTNUM;
		FIDS[Length+1] = 0;
	}
	return FIDS;
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
	for (int i = 0; i < DISABLECHARS; i++)
	if (Disabled[i] == symb)
		return true;
	return false;
}

void UnitellerID::Clear(int from)
{
	for (; from < IDSLEN; from++)
		FIDS[from] = 0;
}
