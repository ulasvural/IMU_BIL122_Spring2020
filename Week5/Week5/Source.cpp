#include <iostream>

using namespace std;

int square(int num)
{
	return num * num;
}


int main()
{
	int x = 10;
	const int ARR_SIZE = 10;
	const int ARR_SIZE1 = x;

	constexpr int ARR_SIZE2 = 10;
	//constexpr int arr_size3 = x; // x degeri derleme zamanýnda bilinmiyor

	x = 20;
	//arr_size = 20;  // const deger degistirilemez

	int arr[ARR_SIZE];
	//int arr[ARR_SIZE1]; // arr_size1 sabit fakat ilk degeri derleme zamanýnda bilinmiyor!!!

	int arr1[ARR_SIZE2];

	// diziyi ilklendir
	for (int i = 0; i < ARR_SIZE2; ++i)
		arr1[i] = i;

	// diziyi yazdir
	for (int i = 0; i < ARR_SIZE2; ++i)
		cout << arr1[i] << endl;
	cout << endl;

	// dizideki elemanlarin karelerini hesapla ve ata
	for (int i = 0; i < ARR_SIZE2; ++i)
		arr1[i] = square(arr1[i]);

	// diziyi yazdir
	for (int i = 0; i < ARR_SIZE2; ++i)
		cout << arr1[i] << endl;
	cout << endl;

	return 0;
}