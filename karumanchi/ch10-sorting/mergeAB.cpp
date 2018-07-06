#include "sort.h"

void candidate(int a[], int b[], int m, int n)
{
	int count = m;
	int i = n - 1, j = count - 1, k = m + n - 1;

	for (; k >= 0; --k)
	{
		if (b[i] > a[j] || j < 0)
		{
			a[k] = b[i];
			--i;

			if (i < 0)
				break;
		}
		else
		{
			a[k] = a[j];
			--j;
		}
	}
}

int main(int argc, char const *argv[])
{
	int m = atoi(argv[1]), n = atoi(argv[2]), i;
	int a[m + n] = {0}, b[n] = {0};

	for (i = 0; i < m; ++i)
		cin >> a[i];

	for (i = 0; i < n; ++i)
		cin >> b[i];

	bucketsort(a, m);
	bucketsort(b, n);

	candidate(a, b, m, n);

	cout << endl
		 << "Merged array is - ";
	for (i = 0; i < (m + n); ++i)
		cout << a[i] << " ";

	return 0;
}
