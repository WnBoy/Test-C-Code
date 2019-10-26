#include<iostream>
int main()
{
	int currval = 0, val = 0;
	if (std::cin >> currval)
	{
		int n = 1;
		while (std::cin >> val)
		{
			if (currval == val)
				++n;
			else
			{
				std::cout << currval <<"times is " << n << std::endl;
				currval = val;
				n = 1;
			}
		}
		std::cout << currval << "times is " << n << std::endl;
	}
	system("pause");
	return 0;
}