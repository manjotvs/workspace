#include <iostream>
#include <map>
#include <iterator>

using namespace std;
int main()
{
	map<int,int> quizz;
	quizz.insert(pair <int,int> (1,35));
	quizz.insert(pair <int,int> (2,36));
	quizz.insert(pair <int,int> (3,46));
	quizz.insert(pair <int,int> (4,56));
	quizz.insert(pair <int,int> (5,89));


	map<int,int> :: iterator itr;
	for(itr=quizz.begin(); itr != quizz.end(); itr++)
	{
		cout << "Key:" << itr->first << " Value:" << itr->second<< endl;
	}
	return 0;
}