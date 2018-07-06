#include "../headers.h"

// assuming m > n
void match(int a[], int b[], int n, int m, int k)
{
	int *max = max_element(a, a + n), i;
	int hash_table[*max + 1] = {0};

	for (i = 0; i < *max + 1; ++i)
		hash_table[a[i]] = a[i];

	cout << "Pair(s) are - " << endl
		 << "[" << endl;
	for (i = 0; i < *max + 1; ++i)
		for (int j = 0; j < m; ++j)
			if (hash_table[a[i]] + b[j] == k && (hash_table[a[i]] + b[j]) % k == 0)
				cout << "  {" << hash_table[a[i]] << ", " << b[j] << "}, "
					 << "{" << b[j] << ", " << hash_table[a[i]] << "}," << endl;
	cout << "]";
}

int main(int argc, char **argv)
{
	int n = atoi(argv[1]), m = atoi(argv[2]), k = atoi(argv[3]), i;
	int a[n] = {0}, b[m] = {0};

	for (i = 0; i < n; ++i)
		cin >> a[i];
	for (i = 0; i < m; ++i)
		cin >> b[i];

	cout << endl
		 << "Array 1 - ";
	for (i = 0; i < n; ++i)
		cout << a[i] << " ";
	cout << endl
		 << "Array 2 - ";
	for (i = 0; i < m; ++i)
		cout << b[i] << " ";

	cout << endl
		 << endl;
	match(a, b, n, m, k);

	return 0;
}
