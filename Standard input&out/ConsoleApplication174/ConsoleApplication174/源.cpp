#include<iostream>
#include<string>
using std::cin;
using std::cout;
using std::endl;
using std::string;`
int main()
{
	const string str = "0123456789ABCDEF";
	cout << "Enter a series of number between 0 and 15" << endl;
	string dd;
	string::size_type n = 0;
	while (cin >> n)
		if (n < str.size())
			dd += str[n];
	cout << dd << endl;
	system("pause");
	return 0;
}