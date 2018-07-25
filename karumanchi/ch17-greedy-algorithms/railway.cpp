#include "../ch10-sorting/sort.hpp"
using namespace std;

int **merge(int *a, int *b, int low, int high)
{
	int c[2][2 * (high + 1)] = {
		{
			0,
		},
	},
						 temp = 0, i = 0, j = 0;

	// associating arrival and departsure tags suign a and d in second row of each column
	while (i <= high && j <= high)
	{
		if (a[i] < b[j])
		{
			c[0][temp] = a[i++];
			c[1][temp++] = 'a';
		}
		else
		{
			c[0][temp] = b[j++];
			c[1][temp++] = 'd';
		}
	}

	while (i <= high)
	{
		c[0][temp] = a[i++];
		c[1][temp++] = 'a';
	}

	while (j <= high)
	{
		c[0][temp] = b[j++];
		c[1][temp++] = 'd';
	}

	return (int **)c;
}

int main(int argc, char const *argv[])
{
	int n = atoi(argv[1]), arrival[n] = {0}, departure[n] = {0}, i;
	for (i = 0; i < n; ++i)
		cin >> arrival[i] >> departure[i];
	int **c = merge((int *)arrival, (int *)departure, 0, n - 1);
	int *x = 0;
	for (i = 0; i < 2 * n; ++i)
	{
		if (c[1][i] == 'a')
			x[i] = 1;
		if (c[1][i] == 'd')
			x[i] = -1;
	}

	// calculate cumulative sum
	for (i = 0; i < 2 * n; ++i)
		x[i + 1] += x[i];

	cout << endl
		 << max_element(x, x + (2 * n));
	return 0;
}
