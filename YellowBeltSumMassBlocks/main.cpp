#include <iostream>
#include <vector>

int main()
{
	uint32_t numBlocks = 0;

	std::cin >> numBlocks;

	uint64_t p = 0;

	std::cin >> p;

	uint64_t sum = 0;

	for (uint32_t i = 0; i < numBlocks; ++i)
	{
		uint64_t w = 0, h = 0, d = 0;
		std::cin >> w >> h >> d;
		sum += w * h * d * p;
	}
	
	std::cout << sum << "\n";

	return 0;
}
/* данные
2 14
1 2 3
30 40 50

ответ 
840084
*/