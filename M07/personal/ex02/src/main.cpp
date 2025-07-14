#include "Array.hpp"
#include <iostream>

int main(void)
{
	const int size = 5;
	Array<int> arr(size);

	std::cout << "size: " << arr.size() << std::endl;
	for (int i = 0; i < size; i++)
		arr[i] = i + 1;
	std::cout << "contents:";
	for (int i = 0; i < size; i++)
		std::cout << " " << arr[i];
	std::cout << std::endl;

	try
	{
		arr[-1] = 42;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}