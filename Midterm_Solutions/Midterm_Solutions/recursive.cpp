//#include <iostream>
//
//using namespace std;
//
//
//void iteratif(char * str)
//{
//	while (*str++ != '\0')
//		if (*str >= 'a' && *str <= 'z')
//			*str += 'A' - 'a';
//}
//
//void recursiveToUpper(char * str)
//{
//	// Base case
//	if (str[0] == '\0')
//		return;
//	
//	if (*str >= 'a' && *str <= 'z')
//		*str += 'A' - 'a';
//
//	// recursion
//	recursiveToUpper(&str[1]);
//}
//
//void recursive(char * str)
//{
//	// base case
//	if (str[0] == '\0' || str[1] == '\0')
//		return;
//
//	if (str[1] >= 'a' && str[1] <= 'z')
//		str[1] += 'A' - 'a';
//
//	// recursion
//	return recursive(&str[1]);
//}
//
//int main()
//{
//	char str1[] = "bil122arasinav"; // "" "b"
//	iteratif(str1);
//	cout << "Iterative: " << str1 << endl;
//
//	char str2[] = "bil122arasinav";
//	recursive(str2);
//	cout << "Recursive: " << str2 << endl;
//
//	char str3[] = "bil122arasinav";
//	recursiveToUpper(str3);
//	cout << "ToUpper: " << str3 << endl;
//	
//	return 0;
//}
