#include "sort.h"

int main(int argc, char const *argv[])
{
	int size = atoi(argv[1]), i;
	int array[size] = {0};

	for (i = 0; i < size; ++i)
		cin >> array[i];

	for (i = 0; i < size; ++i)
		cout << array[i] << " ";

	quicksort(array, 0, size - 1);

	cout << endl;
	for (i = 0; i < size; ++i)
		cout << array[i] << " ";

	return 0;
}
