#include <tchar.h>
		
const int ALLCHARS = 26; //���� � �������
const int DISABLECHARS = 7; //���������� �����������
const int ENABLECHARS = ALLCHARS - DISABLECHARS;
const int ALLNUMS = 9; //������������ ����

typedef char TUID[2];

class UnitellerID
{
private:
	TUID FID;
	static char Alphabet[ENABLECHARS];
	int FIndex;

protected:

public:
	__fastcall UnitellerID();
	__fastcall ~UnitellerID();	
	char ID[2];
	int GetIndex(TUID ID1);
	char* SetIndex(int Index);
};            

//� ��������������� ������� �� ������ �������������� ����� �D�, �F�, �G�, �J�, �M�, �Q�, �V� � ����� �0�.
char UnitellerID::Alphabet[] = "ABCEHIKLNOPRSTUWXYZ";

__fastcall UnitellerID::UnitellerID() { }

__fastcall UnitellerID::~UnitellerID() { }

int UnitellerID::GetIndex(TUID ID1)
{
	int i = 0;
	for (; i < ENABLECHARS; i++)
		if (Alphabet[i] == ID1[i])
			break;
	FIndex *= ALLNUMS;
	FIndex += ID1[1] - '1';
	return FIndex;
}

char* UnitellerID::SetIndex(int Index)
{
	FIndex = Index % ALLNUMS + 1;
	FID[1] = '0' + FIndex;
	FIndex = Index / ALLNUMS;
	FID[0] = Alphabet[FIndex];
	return FID;
}

				
