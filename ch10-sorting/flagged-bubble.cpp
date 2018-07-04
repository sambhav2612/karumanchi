/**
 *
 * Best case is O(n) as ooposed to O(n^2) 
 * 
 **/

#include "../headers.h"

void bs(int array[], int n)
{
	int swapped = 1;
	for (int i = n - 1; i >= 0 && swapped; --i)
	{
		swapped = 0;
		for (int j = 0; j < i; ++j)
			if (array[j] > array[j + 1])
			{
				swap(array[j], array[j + 1]);
				swapped = 1;
			}
	}
}

int main(int argc, char const *argv[])
{
	int size = atoi(argv[1]);
	int array[size] = {0};

	for (int i = 0; i < size; ++i)
		cin >> array[i];

	for (int i = 0; i < size; ++i)
		cout << array[i] << " ";

	bs(array, size);

	cout << endl;
	for (int i = 0; i < size; ++i)
		cout << array[i] << " ";

	return 0;
}
