#include "../headers.h"

void bs(int array[], int array2[], int size, int k)
{
	int array3[k] = {0}, i;

	for (i = 0; i < size; ++i)
		array3[array[i]] += 1;

	for (i = 1; i < k; ++i)
		array3[i] += array3[i - 1];

	/*
	cout << endl;
	for (i = 0; i < k; ++i)
		cout << array3[i] << " ";
	*/

	for (i = size - 1; i >= 0; --i)
	{
		array2[array3[array[i]] - 1] = array[i];
		array3[array[i]] -= 1;
	}
}

int main(int argc, char const *argv[])
{
	int size = atoi(argv[1]), i, k = atoi(argv[2]);
	int array[size] = {0}, array2[size] = {0};

	for (i = 0; i < size; ++i)
		cin >> array[i];

	for (i = 0; i < size; ++i)
		cout << array[i] << " ";

	bs(array, array2, size, k);

	cout << endl;
	for (i = 0; i < size; ++i)
		cout << array2[i] << " ";

	return 0;
}
