#include<iostream>
#include<vector>
#include<string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main()
{
	int grade;
	const vector<string>scores = { "F","D","C","B","A","A++" };
	string lettergrade;
	cin >> grade;
	if (grade < 60)
		lettergrade = scores[0];
	else
		lettergrade = scores[(grade - 50) / 10];
	cout << lettergrade << endl;
	getchar();
	getchar();
	return 0;
}