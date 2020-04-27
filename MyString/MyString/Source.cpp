#include <iostream>
#include "MyString.h"

using namespace std;


void callByReference(MyString & s)
{
	cout << s << endl;
}

void callByValue(MyString s)
{
	cout << s << endl;
}

MyString moveTest(MyString & s)
{
	cout << "Before temp";
	MyString temp(s);
	cout << "After temp";
	cout << s << endl;
	return s;
}

int main()
{
	MyString a{};
	MyString b{ "Merhaba" };
	MyString c = " Dunya!";
	MyString d(b);
	
	cout << a << b << c << d << endl;

	a = b + c + " " + b;

	cout << a << endl;

	MyString f{ "manisa" };
	MyString g{ "malatya" };

	cout << ((f == g) ? "Esit" : "Esit degil") << endl;
	cout << ((f >= g) ? ">Esit" : ">Esit degil") << endl;
	cout << ((f <= g) ? "<Esit":"<Esit degil") << endl;

	cout << "1 ######################" << endl;
	f = g;
	cout << "2 ######################" << endl;
	f = move(g);
	cout << "3 ######################" << endl;
	callByReference(f);
	cout << "4 ######################" << endl;
	callByValue(f);
	cout << "5 ######################" << endl;
	moveTest(f);
	cout << "6 ######################" << endl;
	g = moveTest(f);
	cout << "7 ######################" << endl;


	return 0;
}