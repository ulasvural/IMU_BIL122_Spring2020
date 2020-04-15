#pragma once
#include <iostream>

using namespace std;

template<class T>
class MyVector
{
	friend ostream& operator<<(ostream& out, const MyVector<T> & v)
	{
		for (auto i{ 0 }; i < v.size; ++i)
			out << v.at(i) << ", ";
		out << endl;
		return out;
	}

	friend istream& operator>>(istream& in, MyVector<T> &v)
	{
		int idx;

		in >> idx;
		in >> v.at(idx);

		return in;
	}

public:
	MyVector();
	explicit MyVector(int numberOfItems);
	MyVector(int numberOfItems, T defaultValue );
	MyVector(const MyVector<T> &o);
	~MyVector();

	MyVector<T> & operator=(const MyVector<T> & o);

	bool operator==(const MyVector<T> &o) const;
	bool operator!=(const MyVector<T> &o) const;
	bool operator>=(const MyVector<T> &o) const;
	bool operator<=(const MyVector<T> &o) const;
	bool operator<(const MyVector<T> &o) const;
	bool operator>(const MyVector<T> &o) const;

	MyVector<T> & operator+=(const MyVector<T> & o); 

	int getSize() const;
	T at(int idx) const;
	T& at(int idx);
	bool clear();

private:
	T *data;
	int size;
};


template<class T>
MyVector<T>::MyVector():size{0}, data{nullptr}
{
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
	if (numberOfItems > 0)
	{
		size = numberOfItems;
		data = new T[numberOfItems];	

		for (auto i{0};i<size;++i)
			data[i] = defaultValue;
	}
	else MyVector();
}

template<class T>
MyVector<T>::MyVector(const MyVector<T> & o):size{o.size}
{
	data = new T[size];

	memcpy(data, o.data, size * sizeof(T));

	/*for (auto i{ 0 }; i < size; ++i)
		data[i] = o.data[i];*/
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
inline bool MyVector<T>::operator==(const MyVector<T>& o) const
{
	if (size != o.size)
		return false;

	for (auto i{0};i<size;++i)
		if (data[i] != o.data[i])
			return false;

	return true;
}

template<class T>
inline bool MyVector<T>::operator!=(const MyVector<T>& o) const
{
	return !(*this==o);
}

template<class T>
inline bool MyVector<T>::operator>=(const MyVector<T>& o) const
{
	return ((*this>o) || (*this==o));
}

template<class T>
inline bool MyVector<T>::operator<=(const MyVector<T>& o) const
{
	return !(*this>o);
}

template<class T>
inline bool MyVector<T>::operator<(const MyVector<T>& o) const
{
	return !(*this>o) && (*this!=o);
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