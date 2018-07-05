#include "../headers.h"

int partition(int array[], int low, int high)
{
	int l, r, item = array[low];
	l = low;
	r = high;

	while (l < r)
	{
		while (array[l] <= item)
			++l;

		while (array[r] > item)
			--r;

		if (left < right)
			swap(array[l], array[r]);
	}

	array[low] = array[r];
	array[r] = item;

	return r;
}

void bs(int array[], int low, int high)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high);
		bs(array, low, pivot - 1);
		bs(array, pivot + 1, high);
	}
}

int main(int argc, char const *argv[])
{
	int size = atoi(argv[1]), i;
	int array[size] = {0};

	for (i = 0; i < size; ++i)
		cin >> array[i];

	for (i = 0; i < size; ++i)
		cout << array[i] << " ";

	bs(array, 0, size - 1);

	cout << endl;
	for (i = 0; i < size; ++i)
		cout << array[i] << " ";

	return 0;
}
