#include <tchar.h>
		
const int ALLCHARS = 26; //букв в афавите
const int DISABLECHARS = 7; //количество запрещенных
const int ENABLECHARS = ALLCHARS - DISABLECHARS;

typedef char TUID[2];

class UnitellerID
{
private:
	TUID FID;
	static char Alphabet[ENABLECHARS];

protected:

public:
	__fastcall UnitellerID();
	__fastcall ~UnitellerID();	
	char ID[2];
};            

//В идентификаторах никогда не должны присутствовать буквы «D», «F», «G», «J», «M», «Q», «V» и цифра «0».
char UnitellerID::Alphabet[] = "ABCEHIKLNOPRSTUWXYZ";

__fastcall UnitellerID::UnitellerID()
{
 
}

__fastcall UnitellerID::~UnitellerID()
{
 
}

				
