#include<iostream>
int main()
{
	int sum = 0, va1 = 1;
	while (va1 <= 10)
	{
		sum += va1;
		va1++;
	}
	std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;
	system("pause");
	return 0;
}