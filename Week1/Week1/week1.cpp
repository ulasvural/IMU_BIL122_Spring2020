/*
   Sayi tahmin oyunu

   Bu calismada temel olarak bir sinifin olusturulmasini gorduk.
   Ilk sinifimiz oldugu icin bazi eksik yerleri var, onlari da ilerleyen donemde duzenleyecegiz.
*/

#include <iostream>
#include <random>

using namespace std;

// Tahmin oyunu icin sinif tanimi. Sinif isimleri buyuk harfle baslatilmasi bir aliskanliktir.
// Siz de buna uyarsaniz deneyimli yazilimcilar kodunuzu daha rahat anlayabilirler
class TahminOyunu
{
	// struct'ta varsayilan public iken class'da bu private'dir. Bu sekilde verimizi saklayabiliriz (Information Hiding)
public:
	TahminOyunu(); // Constructor donus turu yoktur. Bu fonksiyon parametre almadigi icin ayni zamanda default constructor olarak tanimlanir.
	bool tahminEt(); // public member function. Nesne uzerinden dogrudan erisilebilir.
	int getTahminSayisi() const; // Sakladigimiz verilere erisimi saglamak icin public getter/setter fonksiyonlar yazariz.
private:
	int tahminSayisi; // private data member
	int tutulanSayi;
};

int main()
{
	TahminOyunu oyun;  // TahminOyunu sýnýf, oyun ise bu sinifin bir nesnesidir (obje).
	oyun.tahminEt(); // public member fonksiyonlara erisebiliriz

	cout << oyun.getTahminSayisi() <<
		" denemede bildiniz. Tebrikler!" << endl;

	return 0;
}

TahminOyunu::TahminOyunu()
{
	random_device rd;
	auto mt = mt19937(rd());
	auto dist = uniform_int<int>(1, 1000);
	tutulanSayi = dist(mt);

	tahminSayisi = 0;
}


int TahminOyunu::getTahminSayisi() const
{
	return tahminSayisi;
}


bool TahminOyunu::tahminEt()
{
	auto tahmin = 0;

	while (tutulanSayi != tahmin)
	{
		cout << "Tahmin:";
		cin >> tahmin;

		if (tahmin > tutulanSayi)
			cout << "Tahmininizi azaltin" << endl;
		else if (tahmin < tutulanSayi)
			cout << "Tahmininizi arttirin" << endl;

		++tahminSayisi;
	}
	return true;
}