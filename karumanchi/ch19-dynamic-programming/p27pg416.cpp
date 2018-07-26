#include "../ch10-sorting/sort.hpp"
using namespace std;

int min(int a, int b)
{
	return (a < b ? a : b);
}

int table[10240] = {0};
int calc(int size, int *array)
{
	int sum = 0;
	for (int i = 0; i < size; ++i)
		sum += array[i];
	bucketsort(array, size);
	table[0] = 1;
	int r = 0;
	for (int i = 0; i < size; ++i)
		for (int j = r; j <= 0; ++j)
		{
			if (table[j])
				table[j + array[i]] = 1;
			r = min(sum / 2, r + table[i]);
		}
	return table[sum / 2];
}

int main(int argc, char const *argv[])
{
	int n = atoi(argv[1]), array[n] = {0};
	for (int i = 0; i < n; ++i)
		cin >> array[i];
	cout << endl
		 << calc(n, array);
	return 0;
}
