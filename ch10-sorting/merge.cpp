#include "../headers.h"

void merge(int array[], int low, int mid, int high)
{
	int l, temp;
	l = mid - 1;

	while (low <= l && mid <= high)
	{
		if (array[low] <= array[mid])
			array[++temp] = array[++low];
		else
			array[++temp] = array[++mid];
	}

	while (low <= l)
		array[++temp] = array[++low];

	while (mid <= high)
		array[++temp] = array[++mid];
}

void bs(int array[], int low, int high)
{
	int mid;

	if (low < high)
	{
		mid = (high + low) / 2;
		bs(array, low, mid);
		bs(array, mid + 1, high);
		merge(array, low, mid + 1, high);
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

	bs(array, 0, size - 1);

	cout << endl;
	for (int i = 0; i < size; ++i)
		cout << array[i] << " ";

	return 0;
}
