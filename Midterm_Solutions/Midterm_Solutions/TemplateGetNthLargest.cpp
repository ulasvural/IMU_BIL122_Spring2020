//#include <iostream>
//
//using namespace std;
//
//// Do not edit MyClass!!!
//// MyClass sýnýfý üzerinde herhangi bir deðiþlik yapmayýnýz!!!
//class MyClass {
//	friend ostream& operator<<(ostream& out, const MyClass& c) {
//		out << "a: " << c.a << " b: " << c.b << endl;
//		return out;
//	}
//public:
//	MyClass(int a, int b) :a{ a }, b{ b } {}
//
//	bool operator>(const MyClass& other) {
//		if ((a * a + b * b) > (other.a * other.a + other.b * other.b))
//			return true;
//
//		return false;
//	}
//
//private:
//	int a, b;
//};
//
//// Asagidaki fonksiyonu gercekleyiniz [30 puan]
//// Fonksiyon verilen sirasiz bir dizideki n. en buyuk degeri bulup dondurur
//// n parametresinin deðeri 1 ile sizeOfArr arasýnda olmalýdýr. 
//// Aksi durumda aykýrý durum oluþturulmalýdýr.
//
//// implement the function below [30 points]
//// it returns the n th largest element of a given unsorted arr 
//// Value of n must be between 1 and sizeOfArr otherwise the functions throws an exception
//template<class T>
//T getNthLargest(T * arr, int sizeOfArr, int n) 
//{
//
//	//cout << "Int array size [function]:" << (sizeof(arr) / sizeof(int)) << endl;
//	if (n<1 || n>sizeOfArr)
//		throw(out_of_range("n must be between 0 and sizeOfArr"));
//
//	for (int i{0}; i < sizeOfArr - 1; ++i)
//	{
//		int tempMaxIndex = i;
//		for (int j{ i + 1 }; j < sizeOfArr; ++j)
//		{
//			//if (arr[tempMaxIndex] <= arr[j]) // calismaz cunku <= operatoru tanimli degil
//			if (arr[j] > arr[tempMaxIndex])
//				tempMaxIndex = j;
//		}
//
//		T temp{ arr[i] };
//		arr[i] = arr[tempMaxIndex];
//		arr[tempMaxIndex] = temp;
//	}
//
//	return arr[n-1];
//}
//
//
//int main()
//{
//	int arrInt[] = { 45, 3, 65, 32, 8, 3, 9, 0, 12, 34, 768, 23 };
//	double arrDouble[] = { 4.5, -14.65, 3.0, 0.65, 32.3, 8.8, 9.3, 9., 0.334, 1.2, 3.4, 76.8, 23.456 };
//	MyClass arrMyClass[] = { {8, 4}, {2, 3}, {6, 5}, {56, 12}, {78, 59}, {2, 0}, 
//								{45, 5}, {68, 10}, {9, 9}, {12, 4} };
//
//	cout << "Int array size [main]:" << (sizeof(arrInt) / sizeof(int)) << endl;
//	cout << getNthLargest(arrInt, sizeof(arrInt) / sizeof(int), 4) << endl;
//	cout << getNthLargest(arrDouble, sizeof(arrDouble) / sizeof(double), 6) << endl;
//	cout << getNthLargest(arrMyClass, sizeof(arrMyClass) / sizeof(MyClass), 1) << endl;
//
//	// an exception must be occurred
//	try {
//		cout << getNthLargest(arrMyClass, sizeof(arrMyClass) / sizeof(MyClass), -2) << endl;
//	}
//	catch (out_of_range &e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}
