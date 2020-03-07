#include "Numerical.h"

/* Baslik dosyasinda tanimlanan varsayilan deger burada tekrar yazilmaz! Yazilirse derleyici hatasý alýnýr */
Numerical::Numerical(int newVal) // Denemek isterseniz int newVal = 0 
	:valInt{ newVal }, valDouble{ 0.0 }, myType{ "Int" }
{
	// BIR SORU: {} uniform ilklendirmenin avantajlari nelerdir????
}

Numerical::Numerical(double newVal)
	: valInt{ 0 }, valDouble{ newVal }, myType{ "Double" } /* Eger fonksiyona gelen degeri bir kontrolden gecirmeden dorgudan atayacaksaniz
														   parametre listesi kapandýktan sonra : operatörü ve sonrasýnda üye ilklendirme söz dizimini kullanabilirsiniz.
														   Bu atamadan daha verimli calismaktadir ama deger kontrolu gerektiginde kullanamazsiniz. */
{
}


// Getter/Setter fonksiyonlar
string Numerical::getMyType() const
{
	return "Const" + myType;
}

string Numerical::getMyType()
{
	return "Non-const" + string();
}

int Numerical::getMyIntVal() const
{
	return valInt;
}

double Numerical::getMyDoubleVal() const
{
	return valDouble;
}

bool Numerical::setMyIntVal(int newVal)
{
	valInt = newVal;
	valDouble = 0;
	myType = "int";
	return true;
}

bool Numerical::setMyDoubleVal(double newVal)
{
	valInt = 0;
	valDouble = newVal;
	myType = "double";
	return true;
}

bool Numerical::setMyType(const string & newType)
{
	if (myType == "int" && newType == "double")
	{
		valDouble = valInt;
		valInt = 0;
		myType = newType;
		return true;
	}

	return false;
}
