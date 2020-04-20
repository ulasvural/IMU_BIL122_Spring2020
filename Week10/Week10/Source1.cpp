//#include<iostream>
//#include<memory>
//
//using namespace std;
//
//int main()
//{
//	auto rawPtr = new int{ 5 };
//
//	auto xPtr = unique_ptr<int>{ rawPtr };
//	unique_ptr<int> xPtr1 = move(xPtr);
//
//	auto rawPtr1 = new int{ 99 };
//	auto xSPtr = shared_ptr<int>{ rawPtr1 };
//	auto xSPtr1 = xSPtr;
//
//	std::cout << *rawPtr << " " << "*xPtr1" << " " << *xPtr1 << endl;
//	*xPtr1 = 10;
//	std::cout << *rawPtr << " " << "*xPtr1" << " " << *xPtr1 << endl;
//	//*xPtr1 = 11;
//	std::cout << *rawPtr << " " << "*xPtr1" << " " << *xPtr1 << endl;
//
//	return 0;
//}