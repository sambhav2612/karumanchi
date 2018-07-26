#include "../headers.hpp"
using namespace std;

int max(int a, int b)
{
	return (a > b ? a : b);
}

int calc(int *array, int size)
{
	int max = 1, table[size][size];
	for (int i = 0; i < size; ++i)
	{
		table[i][i] = 1;
		if (array[i] == array[i + 1])
		{
			table[i][i + 1] = 1;
			max = 2;
		}
		else
			table[i][i + 1] = 0;
	}

	for (int k = 2; k < size; ++k)
		for (int i = 0; i < size - k + 1; ++i)
		{
			int j = i + k - 1;
			if (array[i] == array[j])
			{
				table[i][j] = table[i + 1][j - 1] + 2;
				max = k;
			}
			else
				table[i][j] = max(table[i][j - 1], table[i + 1][j - 1]);
		}

	return max;
}