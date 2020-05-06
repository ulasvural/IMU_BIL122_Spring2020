#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

const int BELLEK_ALINAMADI{ -1 };

class Item
{
public:
	// Verilen parametrelere uygun �ekilde yeni bir item nesnesi olu�turur [5 Puan]
	// Constructs a new Item object accoring to the given parameters [5 points]
	Item(const string& name = "", int count = 1) :name{ name }, count{ count } {}
	int count;   // Kitaptan kac adet oldugunu tutar // Holds the number of the item
	string name; // Kitab�n ad�n� tutar // Holds the name of the book
};

class BookCollection
{
	/* Koleksiyonda bulunan tum ogeleri ekrana bastirin [5 Puan]
	   (iomanip, vb.) ek k�t�phaneler yard�m�yla tablo �eklinde bir g�r�n�m olu�turun [5 Ek Puan]*/

	   /* prints all the items in the collection [5 point]
		   use extra libraries (iomanip, etc.) to create a table view [5 points extra]	*/
	friend ostream& operator<<(ostream & out, const BookCollection & collection)
	{
		if (collection.numberOfUniqueItems <= 0)
		{
			out << "BOS KOLEKSIYON" << endl << endl;
			return out;
		}

		auto maxBookNameLen{ 0 };
		for (int i{ 0 }; i < collection.numberOfUniqueItems; ++i)
			if (maxBookNameLen < collection.items[i].name.length())
				maxBookNameLen = collection.items[i].name.length();

		out << setw(maxBookNameLen) << "KITAP ADI" << setw(6) << "ADET" << endl;

		for (int i{ 0 }; i < collection.numberOfUniqueItems; ++i)
			out << setw(maxBookNameLen) << collection.items[i].name
				<< setw(6) << collection.items[i].count << endl;

		cout << endl;
		return out;
	}
public:
	// empty collection/ bos koleksiyon -> [5 puan/points]
	BookCollection() :numberOfUniqueItems{ 0 }, items{ nullptr } {}

	// 1 item of bookname [5 points] 
	// verilen kitap isminden tek kitap iceren bir koleksiyon olusturur [5 puan]
	BookCollection(const string & bookname) :numberOfUniqueItems{ 1 }
	{
		items = new Item[1];
		if (!items)
			throw(std::bad_alloc());

		items[0].name = bookname;
		items[0].count = 1;
	}

	// creates a collection of 1 item given -> 5 points
	BookCollection(const Item& item):numberOfUniqueItems{ 1 }
	{
		items = new Item[1];
		if (!items)
			throw(std::bad_alloc());

		items[0] = item;
	}
	/* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		A�A�I EKS�K OLAN PROTOT�PLER� TAMAMLAYINIZ!!!
		COMPLETE THE MISSING FUNCTION PROTOTYPES BELOW!!!
		!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/


	//  Write a destructor [5 points]
	//  Y�k�c� fonksiyon [5 Puan]
	~BookCollection()
	{
		if (items)
			delete[]items;
	}

	// Write a copy constructor -> 10 points
	// Kopya Yap�c� [10 Puan]
	BookCollection(const BookCollection & o):numberOfUniqueItems{o.numberOfUniqueItems}, items{nullptr}
	{
		if (numberOfUniqueItems>0)
		{
			items = new Item[numberOfUniqueItems];
			if (!items)
				throw(std::bad_alloc());

			for (int i{ 0 }; i < numberOfUniqueItems; ++i)
				items[i] = o.items[i];
		}
	}

	// Write a move constructor -> 10 points
	// Ta��y�c� Yap�c� [10 puan]
	BookCollection( BookCollection && o) :numberOfUniqueItems{ o.numberOfUniqueItems }, items{o.items}
	{
		o.items = nullptr;
		o.numberOfUniqueItems = 0;
	}

	// Overload copy assignment operator -> 10 points
	// Kopyalay�c� Atama Operat�r�n� a��r� y�kleyin [10 Puan]
	BookCollection& operator=(const BookCollection &other)
	{
		if (this == &other) // self assignment
			return *this;

		if (items)
			delete[] items;

		numberOfUniqueItems = other.numberOfUniqueItems;

		items = new Item[numberOfUniqueItems];
		if (!items)
			throw(std::bad_alloc());

		for (int i{ 0 }; i < numberOfUniqueItems; ++i)
			items[i] = other.items[i];

		return *this;
	}

	// Overload move assignment operator -> 10 points
	// Ta��y�c� Atama Operat�r�n� a��r� y�kleyin [10 Puan]
	BookCollection& operator=(BookCollection &&other)
	{
		if (this == &other)  // self assignment
			return *this;

		if (items)
			delete[] items;

		numberOfUniqueItems = other.numberOfUniqueItems;
		items = other.items;

		other.items = nullptr;
		other.numberOfUniqueItems = 0;

		return *this;
	}

	// Koleksiyon bo�sa true, de�ilse false d�nd�r�r
	// ! operator returns true if the collection is empty and it results false otherwise.
	bool operator!() const // [3 puan/points]
	{
		if (numberOfUniqueItems > 0)
			return true;

		return false;
	}

	/* ==, != , >, <, >= ve <= operatorlerini a��r� y�kleyin
	   Bu operat�rler Koleksiyon i�indeki TOPLAM ��E say�s�na g�re kar��la�t�rma yaparlar.
	   T�m operat�rleri do�ru yapanlar [22 Puan], di�er durumda operat�r ba��na [3 Puan]  */
	   /* Overload ==, != , >, <, >= and <= operators
		  These operators compare the TOTAL NUMBER OF ITEMS (counts of all items) in the collections
		  Total points of comparison operators
		  (6 operators = 22 points, less than 6 operators each operator is 3 points)*/

	bool operator==(const BookCollection & other) const
	{
		if (getTotalNumberOfItems() == other.getTotalNumberOfItems())
			return true;

		return false;
	}

	bool operator!=(const BookCollection & other) const
	{
		if (getTotalNumberOfItems() != other.getTotalNumberOfItems())
			return true;

		return false;
		
		//return !(*this == other);
	}

	bool operator>(const BookCollection & other) const
	{
		if (getTotalNumberOfItems() > other.getTotalNumberOfItems())
			return true;

		return false;
	}

	bool operator<(const BookCollection & other) const
	{
		if (getTotalNumberOfItems() < other.getTotalNumberOfItems())
			return true;

		return false;
	}

	bool operator>=(const BookCollection & other) const
	{
		if (getTotalNumberOfItems() >= other.getTotalNumberOfItems())
			return true;

		return false;
	}

	bool operator<=(const BookCollection & other) const
	{
		if (getTotalNumberOfItems() <= other.getTotalNumberOfItems())
			return true;

		return false;
	}
	   	
	/* �ki koleksiyonu birle�tiren += operator�n� a��r� y�kleyiniz [25 Puan]
		E�er bir ��e mevcut koleksiyonda yoksa o ��eyi ekleyin,
		e�er ��e zaten mevcutsa adedini g�ncelleyin.*/
	/*	Overload += operator which merges two collections [25 points]
		if an item in the otherCollection is already in the collection than only increase the item count
		otherwise add the item as a new item*/
	BookCollection& operator+=(const BookCollection& otherCollection)
	{
		for (auto i{ 0 }; i < otherCollection.numberOfUniqueItems; ++i)
		{
			auto isAllreadyInTheCollection{ false };
			for (auto j{ 0 }; j < numberOfUniqueItems; ++j)
			{
				if (otherCollection.items[i].name == items[j].name) {
					items[j].count += otherCollection.items[i].count;
					isAllreadyInTheCollection = true;
					break;
				}
			}

			if (!isAllreadyInTheCollection)
			{
				Item * tempPtr{ nullptr };

				try {
					tempPtr = new Item[numberOfUniqueItems + 1];
				}
				catch (bad_alloc &e)
				{
					cerr << "Hata: Bellek Alinamadi!!! " << e.what() << endl;
					exit(BELLEK_ALINAMADI);
				}

				for (auto j{ 0 }; j < numberOfUniqueItems; ++j)
				{
					tempPtr[j] = items[j];
				}
				tempPtr[numberOfUniqueItems] = otherCollection.items[i];

				if (items)
					delete[] items;

				items = tempPtr;
				numberOfUniqueItems++;
			}
		}

		return *this;
	}

	/* Koleksiyondan bir di�er koleksiyonu ��kartan -= operat�r�n� a��r� y�kleyin [30 Puan]
	  E�er ��kart�lacak ��e koleksiyonda yoksa bir �ey yap�lmaz,
	  ��kart�lacak ��enin adedi mevcuttan fazlaysa/mevcuda e�itse ��e koleksiyondan ��kart�l�r,
	  ��kart�lacak ��enin adedi mevcuttan azsa sadece adet g�ncellenir.
	  */
	  /* Overload -= operator which removes an item from the collection
	   if an item that you need to remove is not a member of the collection than ignore that item
	   if given item has equal or more number of instances than the collection has
	   then you must completly remove the item from the collection otherwise only update the item count*/
	BookCollection& operator-=(const Item& item)
	{
		for (int i{ 0 }; i < numberOfUniqueItems; ++i)
		{
			if (items[i].name == item.name)
			{
				if (items[i].count > item.count)
					items[i].count -= item.count;
				else
				{
					Item * temp = new Item[numberOfUniqueItems - 1];
					if (!temp)
						throw(std::bad_alloc());

					for (int j{ 0 }; j < i; ++j)
						temp[j] = items[j];
					for (int j{ i + 1 }; j < numberOfUniqueItems; ++j)
						temp[j-1] = items[j];

					if (items)
						delete[]items;
					items = temp;
					numberOfUniqueItems--;
				}
				break;
			}
		}

		return *this;
	}


private:
	// numberOfUniqueItems koleksiyondaki Item say�s�n� tutar, TOPLAM ��E SAYISINI de�il
	// numberOfUniqueItems holds unique items not the total number of items in the collection
	int numberOfUniqueItems;
	Item * items;

	// Isterseniz buraya yard�mc� fonksiyonlar yazabilirsiniz.
	// If you want you can write helper functions here.
	
	int getTotalNumberOfItems() const
	{
		int total{ 0 };
		for (int i{ 0 }; i < numberOfUniqueItems; ++i)
			total += items[i].count;

		return total;
	}

};


int main()
{
	auto item1 = Item("Kitap-1", 10);
	auto item2 = Item("Kitap-2", 20);
	auto item3 = Item("Kitap-3", 13);
	auto item4 = Item("Kitap-4", 20);

	auto bc1 = BookCollection();
	auto bc2 = BookCollection(item1);
	auto bc3 = BookCollection(item2);
	auto bc4 = BookCollection(bc2);

	cout << "Koleksiyon-1\n" << bc1
		<< "Koleksiyon-2\n" << bc2
		<< "Koleksiyon-3\n" << bc3
		<< "Koleksiyon-4\n" << bc4 << endl;

	/*cout << boolalpha << "(bc1 == bc2):" << (bc1 == bc2) << endl
		<< "(bc1 < bc2):" << (bc1 < bc2) << endl
		<< "(bc1 >= bc2):" << (bc1 >= bc2) << endl
		<< "(bc1 != bc2):" << (bc1 != bc2) << endl << endl;

	cout << boolalpha << "(bc4 == bc2):" << (bc4 == bc2) << endl
		<< "(bc4 < bc2):" << (bc4 < bc2) << endl
		<< "(bc4 >= bc2):" << (bc4 >= bc2) << endl
		<< "(bc4 != bc2):" << (bc4 != bc2) << endl << endl;*/

	cout << bc4 << endl;
	cout << "bc4 += bc3" << endl;
	bc4 += bc3;
	cout << bc4 << endl;


	cout << boolalpha << "(bc4 == bc2):" << (bc4 == bc2) << endl
		<< "(bc4 < bc2):" << (bc4 < bc2) << endl
		<< "(bc4 >= bc2):" << (bc4 >= bc2) << endl
		<< "(bc4 != bc2):" << (bc4 != bc2) << endl << endl;
	
	cout << bc4 << endl;
	cout << "bc4 + item2" << endl;
	bc4 += item2;

	cout << bc4 << endl;
	cout << "bc4 + item3" << endl;
	bc4 += item3;
	
	cout << bc4 << endl;
	cout << "bc4 + item4" << endl;
	bc4 += item4;
	
	cout << bc4 << endl;
	cout << "bc4 - item1" << endl;
	bc4 -= item1;
	
	cout << bc4 << endl;
	cout << "bc4 - item2" << endl;
	bc4 -= item2;

	cout << bc4 << endl;
	cout << "bc4 - item2" << endl;
	bc4 -= item2;
	cout << bc4 << endl;



	return 0;
}
