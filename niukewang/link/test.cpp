#include<iostream>

class Test{

private:
 static unsigned char sFlags;
 char mNumber;
public:
	Test(char number) {sFlags^= number; mNumber = number;}
	~Test(){ sFlags ^= mNumber; }
	static char getFlag(){return sFlags; }

};

unsigned char Test::sFlags = 14;


int main
{
    Test* p1 = new Test(-7);
	Test* p2 = new Test(8);
	delete p2;
	cout<<"flag = "<<(int)Test::getFlag()<<endl;
	return 0;
}
