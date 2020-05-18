#pragma once
#include "MyVector.h"

template<class T>
class MyQueue : public MyVector<T>
{
public:
	MyQueue();

	// constructor 
	MyQueue(int numberOfItems, T defaultValue);

	// conversion constructor - initializer list
	MyQueue(const std::initializer_list<T> & l);

	// conversion constructor - MyVector
	MyQueue(const MyVector<T> & v);

	// copy constructor
	MyQueue(const MyQueue<T> &o);

	// move constructor
	MyQueue(MyQueue<T> &&o);

	T pop();
	void push(const T& newItem);

	T operator[](int idx) const = delete;
	T& operator[](int idx) = delete;

	T at(int idx) const = delete;
	T& at(int idx) = delete;
};

template<class T>
inline MyQueue<T>::MyQueue():MyVector<T>()
{
}

// constructor 
template<class T>
inline MyQueue<T>::MyQueue(int numberOfItems, T defaultValue):
	MyVector<T>(numberOfItems, defaultValue)
{}

// conversion constructor for initializer list
template<class T>
inline MyQueue<T>::MyQueue(const std::initializer_list<T> & l):
	MyVector<T>(l)
{

}

// copy constructor
template<class T>
inline MyQueue<T>::MyQueue(const MyQueue<T> &o):
	MyVector<T>(o)
{}

// move constructor
template<class T>
inline MyQueue<T>::MyQueue(MyQueue<T> &&o) : 
	MyVector<T>(o)
{}

// conversion constructor
template<class T>
inline MyQueue<T>::MyQueue(const MyVector<T> &o): MyVector<T>(o)
{}

// First In First Out - Kuyruga ilk giren eleman ilk once cikar
template<class T>
T MyQueue<T>::pop()
{
	T temp = MyVector<T>::data[0];

	MyVector<T>::size--;
	T* tempData = new T[MyVector<T>::size];
	memcpy(tempData, &MyVector<T>::data[1], MyVector<T>::size * sizeof(T));

	delete[] MyVector<T>::data;
	MyVector<T>::data = tempData;

	return temp;
}

// Kuyrugun sonuna yeni bir eleman ekler
template<class T>
void MyQueue<T>::push(const T& newItem)
{
	MyVector<T>::size++;
	T* tempData = new T[MyVector<T>::size];
	memcpy(tempData, &MyVector<T>::data[0], (MyVector<T>::size - 1) * sizeof(T));
	tempData[MyVector<T>::size - 1] = newItem;

	delete[] MyVector<T>::data;
	MyVector<T>::data = tempData;
}