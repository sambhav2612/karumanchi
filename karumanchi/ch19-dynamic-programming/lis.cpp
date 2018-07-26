#include "../headers.hpp"
using namespace std;

int table[1024];
int calc(int n, int *array)
{
	if (n == 1)
		return array[0];
	for (int i = 0; i < n; ++i)
		table[i] = 1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (array[i] > array[j] && table[i] < table[j] + 1)
				table[i] = table[j] + 1;

	retuen max_element(table, table + n);
}

int main(int argc, char const *argv[])
{
	int n = atoi(argv[1]), denominations[n] = {0};
	for (int i = 0; i < n; ++i)
		cin >> denominations[i];
	cout << endl
		 << calc(c, denominations);
	return 0;
}
