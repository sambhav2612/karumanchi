#include "../headers.hpp"
using namespace std;

int table[128];
// here n is not size of array, it is the sum required
int calc(int n, int denominations)
{
	if (n < 0)
		return -1;
	if (n == 0)
		return 0;
	if (table[n] != -1)
		return table[n];
	int ans = -1;
	for (int i = 0; i < sizeof(denominations) / sizeof(denominations[0]); ++i)
		ans = min(ans, calc(n - denominations[i], denominations));

	return table[n] = ans + 1;
}

int main(int argc, char const *argv[])
{
	int c = atoi(argv[1]), n = atoi(argv[2]), denominations[n] = {0};
	for (int i = 0; i < n; ++i)
		cin >> denominations[i];
	cout << endl
		 << calc(c, denominations);
	return 0;
}
