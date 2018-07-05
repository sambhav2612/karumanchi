#include "../headers.h"
#define BUCKETS 10

void bs(int array[], int size)
{
	int bucket[BUCKETS] = {0}, i;

	for (i = 0; i < size; ++i)
		++bucket[array[i]];

	for (int j = 0, i = 0; j < BUCKETS; ++j)
		for (int k = bucket[j]; k > 0; --k)
			array[i++] = j;
}

int main(int argc, char const *argv[])
{
	int size = atoi(argv[1]), i;
	int array[size] = {0};

	for (i = 0; i < size; ++i)
		cin >> array[i];

	for (i = 0; i < size; ++i)
		cout << array[i] << " ";

	bs(array, size);

	cout << endl;
	for (i = 0; i < size; ++i)
		cout << array[i] << " ";

	return 0;
}
