#pragma once
#include <iostream>

using namespace std;

template<class T>
class MyVector
{
	friend ostream& operator<<(ostream& out, const MyVector<T> & v)
	{
		for (auto i{ 0 }; i < v.size-1; ++i)
			out << v[i] << ", ";

		if (v.size > 0)
			out << v[v.size - 1];
		out << endl;
		return out;
	}
public:
	// default constructor
	MyVector();

	// constructor 
	MyVector(int numberOfItems, T defaultValue);

	// conversion constructor for initializer list
	MyVector(const std::initializer_list<T> & l);

	// expilicit conversion constructor - int degeri MyVector nesnesine donusturmez!!!
	explicit MyVector(int numberOfItems);
		
	// copy constructor
	MyVector(const MyVector<T> &o);

	// move constructor
	MyVector(MyVector<T> &&o);

	// destructor
	~MyVector();

	// copy assignment operator
	MyVector<T> & operator=(const MyVector<T> & o);

	// move assignment operator
	MyVector<T> & operator=(MyVector<T> && o);

	// comparison operators
	bool operator==(const MyVector<T> &o) const;
	bool operator!=(const MyVector<T> &o) const;
	bool operator>=(const MyVector<T> &o) const;
	bool operator<=(const MyVector<T> &o) const;
	bool operator<(const MyVector<T> &o) const;
	bool operator>(const MyVector<T> &o) const;

	// += operator
	MyVector<T> & operator+=(const MyVector<T> & o);

	// subscript operators for const and non-const objects
	T operator[](int idx) const;
	T& operator[](int idx);

	// other functions
	int getSize() const;
	T at(int idx) const;
	T& at(int idx);
	bool clear();
protected:
	T *data;
	int size;
};

template<class T>
MyVector<T>::MyVector() :size{ 0 }, data{ nullptr }
{
}

template<class T>
inline MyVector<T>::MyVector(const std::initializer_list<T> & l):size(l.size())
{
	data = new T[size];
	uninitialized_copy(l.begin(), l.end(), data);
}


template<class T>
MyVector<T>::MyVector(int numberOfItems)
{
	if (numberOfItems > 0)
	{
		size = numberOfItems;
		data = new T[numberOfItems];
	}
	else MyVector();
}

template<class T>
MyVector<T>::MyVector(int numberOfItems, T defaultValue)
{
	cout << "other constructor" << endl;

	if (numberOfItems > 0)
	{
		size = numberOfItems;
		data = new T[numberOfItems];

		for (auto i{ 0 }; i < size; ++i)
			data[i] = defaultValue;
	}
	else MyVector();
}

/* Template specialization 
 * Sablon Ozellestirme ile belli turler icin farkli calisan fonksiyonlar yazabilirsiniz
 */
template<>
MyVector<char>::MyVector(int numberOfItems, char defaultValue)
{
	cout << "char constructor" << endl;
	if (numberOfItems > 0)
	{
		size = numberOfItems;
		data = new char[numberOfItems];

		memset(data, defaultValue, size * sizeof(char));
	}
	else MyVector();
}

template<class T>
MyVector<T>::MyVector(const MyVector<T> & o) :size{ o.size }
{
	data = new T[size];

	memcpy(data, o.data, size * sizeof(T));

	/*for (auto i{ 0 }; i < size; ++i)
		data[i] = o.data[i];*/
}

template<class T>
inline MyVector<T>::MyVector(MyVector<T>&& o):size(o.size), data(o.data)
{
	o.size = 0;
	o.data = nullptr;
}

template<class T>
MyVector<T>::~MyVector()
{
	if (data != nullptr) // if (data)
		delete[] data;
}

template<class T>
MyVector<T> & MyVector<T>::operator=(const MyVector<T> & o)
{
	if (this == &o)  // kendisine atanmasina izin verilmez -- self-assignment check
		return *this;

	if (size != o.size)
	{
		size = o.size;
		if (data)
			delete[] data;

		data = new T[size];
	}

	memcpy(data, o.data, size * sizeof(T));

	/*for (auto i{ 0 }; i < size; ++i)
		data[i] = o.data[i];*/

	return *this;
}

template<class T>
inline MyVector<T>& MyVector<T>::operator=(MyVector<T>&& o)
{
	if (&o != this)
	{ 
		if (data)
			delete[]data;
		size = o.size;
		data = o.data;

		o.size = 0;
		o.data = nullptr;
	}

	return *this;
}

template<class T>
inline bool MyVector<T>::operator==(const MyVector<T>& o) const
{
	if (size != o.size)
		return false;

	for (auto i{ 0 }; i < size; ++i)
		if (data[i] != o.data[i])
			return false;

	return true;
}

template<class T>
inline bool MyVector<T>::operator!=(const MyVector<T>& o) const
{
	return !(*this == o);
}

template<class T>
inline bool MyVector<T>::operator>=(const MyVector<T>& o) const
{
	return ((*this > o) || (*this == o));
}

template<class T>
inline bool MyVector<T>::operator<=(const MyVector<T>& o) const
{
	return !(*this > o);
}

template<class T>
inline bool MyVector<T>::operator<(const MyVector<T>& o) const
{
	return !(*this > o) && (*this != o);
}

template<class T>
inline bool MyVector<T>::operator>(const MyVector<T>& o) const
{
	auto minSize = (size >= o.size) ? o.size : size;

	for (auto i{ 0 }; i < minSize; ++i)
		if (data[i] <= o.data[i])
			return false;

	if (size < o.size)
		return false;

	return true;
}

template<class T>
inline MyVector<T>& MyVector<T>::operator+=(const MyVector<T>& o)  // v1 = {3, 4, 5} v2 = {1, 2} v1 += v2 -> v1 = {3, 4, 5, 1, 2}
{
	int newSize = size + o.size;

	if (newSize <= 0)
		return *this;

	T * ptr = new T[newSize];
	if (!ptr)
		exit(-1);

	if (size > 0)
		memcpy(ptr, data, size * sizeof(T));

	if (o.size > 0)
		memcpy(ptr + size, o.data, o.size * sizeof(T));

	size = newSize;
	if (data)
		delete[]data;

	data = ptr;

	return *this;
}

template<class T>
T MyVector<T>::operator[](int idx) const
{
	return data[idx];
}

template<class T>
T & MyVector<T>::operator[](int idx)
{
	return data[idx];
}

template<class T>
int MyVector<T>::getSize() const
{
	return size;
}

template<class T>
T MyVector<T>::at(int idx) const
{
	if (idx < 0 && idx >= size)
		throw("Out-of-range");

	return data[idx];
}

template<class T>
T & MyVector<T>::at(int idx)
{
	if (idx < 0 && idx >= size)
		throw("Out-of-range");

	return data[idx];
}

template<class T>
bool MyVector<T>::clear()
{
	size = 0;
	delete[] data;
	return true;
}