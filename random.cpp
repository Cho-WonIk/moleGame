#include "random.h"

int random()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(1, 9);
	return dis(gen);
}
