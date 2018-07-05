#include "../headers.h"

void bs(int array[], int n)
{
	int x, j;
	for (int i = 1; i < n; ++i)
	{
		x = array[i];
		j = i;

		while (array[j - 1] > x && j >= 0)
		{
			array[j] = array[j - 1];
			--j;
		}

		array[j] = x;
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

	bs(array, size);

	cout << endl;
	for (i = 0; i < size; ++i)
		cout << array[i] << " ";

	return 0;
}
