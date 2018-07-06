#include "../headers.h"

void symmetric(int m, int n, int **a)
{
	int max = max_element(a[m][0], a[m][0] + m), i;
	int hash_table[max + 1] = {0};

	for (i = 0; i < max + 1; ++i)
		hash_table[a[i][0]] = a[i][1];

	for (i = 0; i < max + 1; ++i)
		if (hash_table[a[i][1]] == a[i][0])
			cout << "Pair " << i + 1 << " {" << a[i][0] << ", " << a[i][1] << "}" << endl;
}

int main(int argc, char **argv)
{
	int m = atoi(argv[1]), i, j;
	int a[m][2] = {0};

	for (i = 0; i < m; ++i)
		for (j = 0; j < 2; ++j)
			cin >> a[i][j];

	cout << endl
		 << "Array - " << endl;
	for (i = 0; i < m; ++i)
		for (j = 0; j < 2; ++j)
			cout << a[i][j] << " ";

	cout << endl
		 << endl;

	symmetric(m, 2, (int **)a);

	return 0;
}
