#include <tchar.h>

typedef char TUID[2];

class UnitellerID
{
private:
	TUID FID;
	static char Alphabet[26];

protected:

public:
	__fastcall UnitellerID();
	__fastcall ~UnitellerID();
	static int i;	
	char ID[2];
};            

int UnitellerID::i = 2;
//� ��������������� ������� �� ������ �������������� ����� �D�, �F�, �G�, �J�, �M�, �Q�, �V� � ����� �0�.
char UnitellerID::Alphabet[] = "ABCEHIKLNOPRSTUWXYZ";

__fastcall UnitellerID::UnitellerID()
{
 
}

__fastcall UnitellerID::~UnitellerID()
{
 
}

				
