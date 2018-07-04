#include "../headers.h"

void bs(int array[], int n)
{
	int x, j, h;
	for (h = 0; h < n / 4; h = 2 * h + 1)
		;

	for (; h > 0; h = h / 2)
	{
		for (int i = h + 1; i < n; ++i)
		{
			x = array[i];
			j = i;

			while (j > h && array[j - h] > x)
			{
				array[j] = array[j - h];
				j -= h;
			}

			array[j] = x;
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
