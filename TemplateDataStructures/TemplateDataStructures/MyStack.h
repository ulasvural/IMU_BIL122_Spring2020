#pragma once
#include "MyVector.h"

template<class T>
class MyStack : public MyVector<T>
{
public:
	MyStack();

	// constructor 
	MyStack(int numberOfItems, T defaultValue);

	// conversion constructor - initializer list
	MyStack(const std::initializer_list<T> & l);

	// conversion constructor - MyVector
	MyStack(const MyVector<T> & v);

	// copy constructor
	MyStack(const MyStack<T> &o);

	// move constructor
	MyStack(MyStack<T> &&o);

	T pop();
	void push(const T& newItem);

	T operator[](int idx) const = delete;
	T& operator[](int idx) = delete;

	T at(int idx) const = delete;
	T& at(int idx) = delete;
};

template<class T>
inline MyStack<T>::MyStack() :MyVector<T>()
{
}

// constructor 
template<class T>
inline MyStack<T>::MyStack(int numberOfItems, T defaultValue) :MyVector<T>(numberOfItems, defaultValue)
{}

// conversion constructor for initializer list
template<class T>
inline MyStack<T>::MyStack(const std::initializer_list<T> & l) : MyVector<T>(l)
{

}

// copy constructor
template<class T>
inline MyStack<T>::MyStack(const MyStack<T> &o) :MyVector<T>(o)
{}

// move constructor
template<class T>
inline MyStack<T>::MyStack(MyStack<T> &&o) : MyVector<T>(o)
{}

// conversion constructor
template<class T>
inline MyStack<T>::MyStack(const MyVector<T> &o) : MyVector<T>(o)
{}

// Last In First Out - Son eklenen elemani yigindan cikararak donderir
template<class T>
T MyStack<T>::pop()
{
	T temp = MyVector<T>::data[MyVector<T>::size-1];

	MyVector<T>::size--;
	T* tempData = new T[MyVector<T>::size];
	memcpy(tempData, &MyVector<T>::data[0], MyVector<T>::size * sizeof(T));

	delete[] MyVector<T>::data;
	MyVector<T>::data = tempData;

	return temp;
}

// Yigina yeni bir eleman ekler
template<class T>
void MyStack<T>::push(const T& newItem)
{
	MyVector<T>::size++;
	T* tempData = new T[MyVector<T>::size];
	memcpy(tempData, &MyVector<T>::data[0], (MyVector<T>::size - 1) * sizeof(T));
	tempData[MyVector<T>::size - 1] = newItem;

	delete[] MyVector<T>::data;
	MyVector<T>::data = tempData;
}
