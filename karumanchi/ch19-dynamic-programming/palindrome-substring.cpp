#include "../headers.hpp"
using namespace std;

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
			if (array[i] == array[j] && table[i + 1][j - 1])
			{
				table[i][j] = 1;
				max = k;
			}
			else
				table[i][j] = 0;
		}

	return max;
}