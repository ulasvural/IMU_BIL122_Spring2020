#include "MyVector.h"


//template<class T>
//ostream & operator<<(ostream & out, const MyVector<T> & v)
//{
//	for (auto i{ 0 }; i < v.size; ++i)
//		out << v.at(i) << ", ";
//	out << endl;
//
//	return out;
//}
//
//template<class T>
//istream & operator>>(istream & in, MyVector<T> & v)
//{
//	int idx;
//
//	in >> idx;
//	in >> v.at(idx);
//
//	return in;
//}

template<class T>
ostream & operator<<(ostream & out, const MyVector<T>& v)
{
	for (auto i{ 0 }; i < v.size; ++i)
		out << v.at(i) << ", ";
	out << endl;
	return out;
}
