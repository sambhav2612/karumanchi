#include "../ch10-sorting/sort.hpp"
using namespace std;
int main(int argc, char const *argv[])
{
	int size = atoi(argv[1]), total_weight = atoi(argv[2]), weights[size] = {0}, value[size] = {0}, i;
	srand(time(NULL));
	for (i = 0; i < size; ++i)
	{
		weights[i] = rand() % size;
		value[i] = rand() % size;
	}
	int value_density[size] = {0};
	for (i = 0; i < size; ++i)
		value_density[i] = value[i] / weights[i];
	bucketsort(value_density, size);
	return 0;
}
