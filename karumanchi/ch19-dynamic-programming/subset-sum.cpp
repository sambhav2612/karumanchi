#include "../headers.hpp"
using namespace std;

int calc(int n, int sum, int *array)
{
	int table[n + 1][sum + 1];
	table[0][0] = 0;
	for (int i = 1; i <= n; ++i)
		table[0][i] = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= sum; ++j)
			table[i][j] = table[i - 1][j] || table[i - 1][j] - array[i];

	return table[n][sum];
}

int main(int argc, char const *argv[])
{

	return 0;
}
