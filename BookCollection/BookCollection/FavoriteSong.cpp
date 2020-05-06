//#include <vector>
//#include <string>
//#include <iostream>
//
//using namespace std;
//
//class MyFavoriteSong
//{
//public:
//	
//	MyFavoriteSong() {} // empty song
//
//	// nesnenize sarkinin bir misrasini ekler [10 puan]
//	// adda a new verse to your object [10 points]
//	void addNewVerse(const string & verse) 
//	{
//		song.push_back(verse);
//	}
//
//	// nesne icindeki sarkinin tum sozlerini ekrana bastirir [7 puan]
//	// print each verse in a new line [7 points]
//	void printLyric() const  
//	{	
//		// Bu basit hali de kabul edilir
//		/*for (auto v : song)
//			cout << v << endl;*/
//
//		string str;
//		for (auto v : song)
//			cout << (str += " ") << v << endl;
//	}
//
//private:
//	vector<string> song;
//};
//
//int main()
//{
//	MyFavoriteSong song;
//
//	/*
//		Asagidaki fonksiyonlarin parametrelerini duzenleyerek en sevdiginiz sarkinin sozlerinin
//		nesnenize eklenmesini saglayin [3 PUAN]*/ 
//
//	// edit these lines so when I run the code I can see your favorite song [3 points]
//	song.addNewVerse("Bil122"); 
//	song.addNewVerse("Ara Sinav");
//	// isterseniz bu aralýða daha fazla song.addNewVerse(""); satýrý ekleyip düzenleyebilirsiniz
//	// ... if you desire you can add and edit more lines of song.addNewVerse(""); here
//
//	song.addNewVerse("Ornek Cozum");
//
//	song.printLyric();
//
//	return 0;
//}