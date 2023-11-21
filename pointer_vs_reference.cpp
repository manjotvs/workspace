#include <iostream>
#inclcude <conio>


void main()
{
	int x = 2;
	int &y=x;
	cout<<y<<" "<<x<<endl;
	x = 3;
	cout<<y<<" "<<x<<endl;
	y = 4;
	cout<<y<<" "<<x<<endl;
}