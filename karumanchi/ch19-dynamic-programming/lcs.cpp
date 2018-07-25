#include "../headers.hpp"
using namespace std;

int LCS[1024][1024] = {
	{
		0,
	},
};
int calc(int *a, int *b, int n, int m)
{
	for (int i = 0; i <= n; ++i)
		LCS[m][i] = 0;
	for (int i = 0; i <= m; ++i)
		LCS[i][n] = 0;
	for (int i = m - 1; i >= 0; --i)
		for (int j = n - 1; j >= 0; --j)
		{
			LCS[i][j] = LCS[i + 1][j + 1];
			if (a[i] == b[j])
				LCS[i][j]++;
			if (LCS[i + 1][j] > LCS[i][j])
				LCS[i][j] = LCS[i + 1][j];
			if (LCS[i][j + 1] > LCS[i][j])
				LCS[i][j] = LCS[i][j + 1];
		}
	return LCS[0][0];
}

int main(int argc, char const *argv[])
{
	int n = atoi(argv[1]), m = atoi(argv[2]), a[n] = {0}, b[m] = {0}, i;
	for (i = 0; i < n; ++i)
		cin >> a[i];
	for (i = 0; i < m; ++i)
		cin >> b[i];
	cout << endl
		 << calc(a, b, n - 1, m - 1);
	return 0;
}
