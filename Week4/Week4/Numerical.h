#pragma once
#include <string>

using namespace std;

class Numerical
{
public:
	// Bu hem int bir degeri Numerical nesnesine donusturebilen bir donusturucu yapici (conversion constructor) hem de varsayilan yapicidir
	/* Eger fonksiyon parametrelerinden birine varsayýlan deger atarsaniz onun sag el tarafinda kalan
	tum diger parametrelere de varsayilan deger vermelisiniz. */
	Numerical(int newVal = 0);

	// Bu bir double degeri Numerical nesnesine donusturur
	explicit Numerical(double newVal); /* Donusturucu yapicilar otomatik olarak cagrilabilir.
									   Bunu istemiyorsanýz bu fonksiyonun basina explicit anahtar kelimesi eklenir */

									   /* Uye fonksiyonlar eger veri uyelerini degistirmiyorsa bunlari const olarak tanimlariz. Bu tanimlama bize su avantajlarý getirir:
										   1. Hatali bir sekilde veri uyelerinin degerlerinin degistirilmesi zorlasir [Principle of least priviledges],
										   2. Sabit nesneler sadece const olarak tanimlanmis uye fonksiyonlari kullanabilir.

										   const anahtar kelimesi fonksiyonun imzasinda yer alir. Bu sayede const nesnelerde ve non-const nesnelerde farklý sekilde calisacak sekilde
										   fonksiyonlari asiri yukleyebilirsiniz [function overloading].
										   */
	string getMyType() const;
	string getMyType();

	/* public getter/setter fonksiyonlar ile sakladigimiz veri uyelerine bizim belirledigimiz kurallar cervesinde erisim saglanir. [Information hiding] */
	int getMyIntVal() const;
	double getMyDoubleVal() const;

	bool setMyIntVal(int newVal);
	bool setMyDoubleVal(double newVal);
	bool setMyType(const string & newType); /* Temel tip disindaki verileri & ile gondermek verimlidir.
											Bu durumda verinin fonksiyon icinde bozulmasý\degistirilmesi istenilmiyorsa const & tercih edilmelidir. */

private:
	string myType;
	double valDouble;
	int valInt;
};

