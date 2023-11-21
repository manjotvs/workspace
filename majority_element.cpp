#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//class solution
int find_majority_element(vector<int> &arr)
{
	unordered_map<int, int> table;
	int i=0;
	// while(i < arr.size())
	// {
	// 	cout<<arr[i]<<endl;
	// 	i++;
	// }
	char n = arr.size();
	while(i < n)
	{
		if(++table[arr[i]] >= n/2)
		{
			//cout<<"found it"<<arr[i];
			return arr[i];
		}
		i++;
	}
	// unordered_map<int, int>:: iterator itr;
	// for(itr=table.begin(); itr!= table.end(); itr++)
	// {
	// 	cout<<itr->first<<" "<<itr->second<<endl;
	// }
	// for(auto i=arr->begin(); i!= arr->end(); i++)
	// {
	// 	cout<<*i<<endl;
	// }
	return 0;
}

int main()
{
	cout<<"Hello\n";
	char arr[] = {3,2,2,2,3,3};
	vector<int> v(begin(arr),end(arr));
	int major_element = find_majority_element(v);
	cout<<"Major Element: "<<major_element<<endl;
	return 0;
}