#include <iostream>
#include <vector>
#include <cstdint>

int main()
{
	size_t size = 0;

	std::cin >> size;

	std::vector<int32_t> temp(size);

	int32_t sum = 0;

	for (auto& elem : temp)
	{
		std::cin >> elem;
		sum += elem;
	}

	int32_t avr = sum / static_cast<int32_t>(size);

	std::vector<int32_t> res;

	for (size_t i = 0; i < size; ++i)
	{
		if (temp[i] > avr)
		{
			res.push_back(static_cast<int32_t>(i));
		}
	}

	std::cout << res.size() << "\n";
	for (auto elem : res)
	{
		std::cout << elem << " ";
	}
	std::cout << "\n";

	return 0;
}