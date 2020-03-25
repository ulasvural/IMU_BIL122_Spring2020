#include <iostream>
#include <vector>
#include <iomanip>
#include <chrono>

using namespace std;

//aþaðýdaki satýrlarý yoruma alýp kodunuzu farklý þekillerde test edebilirsiniz.
#define _TEST_ITERATIVE_
//#define _TEST_RECURSIVE_

// Bu odevde global veya statik degisken tanimlanamaz!!!

/* Ozyinelemeli olarak zip zip kurbaganin kac farkli yoldan gittigini bulan fonksiyondur.
 * Bu fonksiyon icinde for ve while kullanamazsiniz ve en az bir kez recursiveFunction
 * fonksiyonu cagri yapilmalidir.
 */
long long recursiveFunction(int numberOfStones)
{
	if (numberOfStones <= 0) //unexpected case
		return 0;

	if (numberOfStones <= 3)  // base-cases
		return pow(2, numberOfStones - 1);

	return static_cast<long long>(recursiveFunction(numberOfStones - 1)) +
		recursiveFunction(numberOfStones - 2) +
		recursiveFunction(numberOfStones - 3);
}

/* Yinelemeli olarak zip zip kurbaganin kac farkli yoldan gittigini bulan fonksiyondur.
 * Bu fonksiyon icinde for ve while dongusu kullanilmalidir.
 * Bu fonksiyon icinde baska bir fonksiyona (kendisi dahil) cagri yapilamaz.
 */
long long iterativeFunction(int numberOfStones)
{
	if (numberOfStones <= 0)
		return 0;

	vector<long long> result(numberOfStones + 1, 0); //memoization

	if (numberOfStones >= 1) result[1] = 1;
	if (numberOfStones >= 2) result[2] = 2;
	if (numberOfStones >= 3) result[3] = 4;

	for (int i = 4; i <= numberOfStones; ++i)
		result[i] = result[i - 1] + result[i - 2] + result[i - 3];

	return result[numberOfStones];
}



int main()
{
	const int MAX_NUMBER_OF_STONES{ 72 };

	cout << setfill(' ');

	cout.imbue(locale(""));

	for (auto i = 1; i <= MAX_NUMBER_OF_STONES; ++i)
	{

#ifdef _TEST_ITERATIVE_
		{
			long long tempResult = { 0 };

			auto start = std::chrono::steady_clock::now();
			tempResult = iterativeFunction(i);
			auto stop = std::chrono::steady_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();


			cout << "iterative" << setw(4) << i << " -> " << tempResult << " ( " << duration << "us )\n";
		}
#endif

#ifdef _TEST_RECURSIVE_
		{
			long long tempResult = { 0 };

			auto start = std::chrono::steady_clock::now();
			tempResult = recursiveFunction(i);
			auto stop = std::chrono::steady_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();

			cout << "recursive" << setw(4) << i << " -> " << tempResult << " ( " << duration << "us )\n\n";
		}
#endif

	}

	return 0;
}