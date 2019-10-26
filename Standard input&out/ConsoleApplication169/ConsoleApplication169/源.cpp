#include<iostream>
int main()
{
	int sum = 0, va1 = 0;
	while (std::cin >> va1)
	{
		sum += va1;
	}
	std::cout << "sum is " << va1 << std::endl;
	system("pause");
	return 0;
}