#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> Available_Workshops;
Available_Workshops* initialize(vector<int> & start_time, vector<int> & duration, int n) {
	auto r = new Available_Workshops(n);
	for (int i = 0; i < n; i++) r->at(i).first = start_time[i], r->at(i).second = start_time[i] + duration[i];
	return r;
}
int CalculateMaxWorkshops(Available_Workshops* data) {
	sort(data->begin(), data->end(), [](const pii &a, const pii &b) {return a.second < b.second; });
	int f = 0, r = 0;
	for (int i = 0; i < data->size(); i++) {
		if (data->at(i).first >= f) {
			r++;
			f = data->at(i).second;
		}
	}
	return r;
}

int main()
{
	int n;
	cin >> n;
	vector<int> start_time(n), duration(n);
	for (int i = 0; i < n; i++)
	{
		cin >> start_time[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> duration[i];
	}

	Available_Workshops * ptr;
	ptr = initialize(start_time, duration, n);
	cout << CalculateMaxWorkshops(ptr) << endl;
	return 0;
}

//#include <iostream>
//
//using namespace std;
//
////Define the structs Workshops and Available_Workshops.
////Implement the functions initialize and CalculateMaxWorkshops
//typedef struct _Workshop {
//	_Workshop(int start_time = 0, int duration = 0) :
//		start_time{ start_time }, end_time{ start_time + duration }, available{ true },
//		numberOfConflicts{ 0 } {}
//
//	// if other is a non-conflict workshop it returns true otherwise returns false
//	bool operator/(const _Workshop & other) const
//	{
//		if (start_time > other.end_time)
//			return true;
//		if (end_time < other.start_time)
//			return true;
//
//		return false;
//	}
//
//	// checks if not available 
//	bool operator!() const
//	{
//		return !available;
//	}
//
//	int start_time;
//	int end_time;
//	bool available;
//	bool selected, discarded;
//	int numberOfConflicts;
//} Workshop;
//
//typedef struct _Available_Workshops {
//	_Available_Workshops(int n) : n{ n } {
//		if (n > 0)
//			workshops = new Workshop[n];
//	}
//
//	~_Available_Workshops()
//	{
//		if (workshops != nullptr)
//			delete[] workshops;
//	}
//
//	// Assignment operator and copy constructor should be overwritten
//
//	int n;
//	Workshop * workshops;
//} Available_Workshops;
//
//Available_Workshops * initialize(const int * start, const int * duration, int n)
//{
//	Available_Workshops * result = new Available_Workshops(n);
//
//	for (int i = 0; i < n; ++i)
//		result->workshops[i] = Workshop(start[i], duration[i]);
//
//	return result;
//}
//
//int CalculateMaxWorkshops(const Available_Workshops * ptr)
//{
//	int maxNumberOfWorkshops{ 0 };
//	int numberOfAvailableWorkShops{ ptr->n };
//
//
//	while (numberOfAvailableWorkShops > 0)
//	{
//		
//		// init conflict counters
//		numberOfAvailableWorkShops = 0;
//		for (int i = 0; i < ptr->n; ++i) {
//			if (ptr->workshops[i].available) {
//				++numberOfAvailableWorkShops;
//				ptr->workshops[i].numberOfConflicts = 0;
//				ptr->workshops[i].selected = ptr->workshops[i].discarded = false;
//			}
//		}
//		cout << "NumberOfAvailable: " << numberOfAvailableWorkShops << endl;
//		if (numberOfAvailableWorkShops <= 0)
//			break;
//
//		// compute conflicts
//		for (int i = 0; i < ptr->n - 1; ++i) {
//			if (ptr->workshops[i].available)
//			{
//				for (int j = i + 1; j < ptr->n; ++j)
//				{
//					if (ptr->workshops[j].available)
//					if (!(ptr->workshops[i] / ptr->workshops[j]))
//					{
//						++ptr->workshops[i].numberOfConflicts;
//						++ptr->workshops[j].numberOfConflicts;
//					}
//				}
//			}
//		}
//		
//		// add workshops wihout any conflicts and remove max conflict
//		int maxConflict = 0;
//		int maxConflictId = 0;
//		for (int i = 0; i < ptr->n; ++i)
//		{
//			if (ptr->workshops[i].available)
//			if (ptr->workshops[i].numberOfConflicts == 0)
//			{
//				ptr->workshops[i].available = false;
//				ptr->workshops[i].selected = true;
//				++maxNumberOfWorkshops;
//			}
//			else if (ptr->workshops[i].numberOfConflicts > maxConflict)
//			{
//				maxConflict = ptr->workshops[i].numberOfConflicts;
//				maxConflictId = i;
//			}
//		}
//
//		ptr->workshops[maxConflictId].available = false;
//		ptr->workshops[maxConflictId].discarded = true;
//
//		for (int i = 0; i < ptr->n; ++i) {
//			cout << i; 
//			if (ptr->workshops[i].available) cout << " A "; 
//			else if (ptr->workshops[i].selected) cout << " S ";
//			else if (ptr->workshops[i].discarded) cout << " D ";
//			cout << ptr->workshops[i].numberOfConflicts << endl;
//		}
//		cout << endl << endl;
//	}
//
//	return maxNumberOfWorkshops;
//}
//
//
//int main(int argc, char *argv[]) {
//	int n; // number of workshops
//	cin >> n;
//	// create arrays of unknown size n
//	int* start_time = new int[n];
//	int* duration = new int[n];
//
//	for (int i = 0; i < n; i++) {
//		cin >> start_time[i];
//	}
//	for (int i = 0; i < n; i++) {
//		cin >> duration[i];
//	}
//
//	Available_Workshops * ptr;
//	ptr = initialize(start_time, duration, n);
//	cout << CalculateMaxWorkshops(ptr) << endl;
//	return 0;
//}
//
//
//
//
////#include <iostream>
////#include <vector>
////#include <iomanip>
////#include <array>
////
////using namespace std;
////
////template <class T>
////void print(const T& c)
////{
////	for (auto i : c)
////		cout << i << "  ";
////	cout << endl;
////}
////
////int main()
////{
////	constexpr int SIZE = 3;
////	int size = 10;
////
////
////	int arr[SIZE]{1,2,3};
////	array<int, SIZE> arrClass{4,5,6};
////	vector<int> v{ 4,5,6 };
////
////	//auto a1 = int[] {1, 2, 3};
////	auto a2 = array<int, SIZE>{4, 5, 6};
////	auto v1 = vector<int>{ 4,5,6 };
////	//int arr1[size]{};
////
////	print(arr);
////	print(arrClass);
////	print(v);
////	print(a2);
////	print(v1);
////
////	return 0;
////}