#include "../headers.hpp"
using namespace std;

int merge(int *a, int *b, int low, int high)
{
	int c[2 * (high + 1)] = {0}, temp = 0, i = 0, j = 0;
	while (i <= high && j <= high)
	{
		if (a[i] <= b[j])
			c[temp++] = a[i++];
		else
			c[temp++] = b[j++];
	}

	while (i <= high)
		c[temp++] = a[i++];

	while (j <= high)
		c[temp++] = b[j++];

	return (c[high] + c[high + 1]) / 2;
}

int main(int argc, char const *argv[])
{
	int i, n = atoi(argv[1]), a[n] = {0}, b[n] = {0};
	for (i = 0; i < n; ++i)
		cin >> a[i] >> b[i];
	cout << endl
		 << merge(a, b, 0, n - 1);
	return 0;
}
