#include <bits/stdc++.h>

bool subset[10000][10000] = {0};

bool calc(int *set, int n, int sum) {
	for (int i = 0; i <= n; ++i)
		subset[i][0] = true;
	for (int i = 1; i <= sum; ++i)
		subset[0][i] = false;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= sum; ++j) {
			if (j < set[i-1])
				subset[i][j] = subset[i-1][j];
			else
				subset[i][j] = subset[i-1][j] || subset[i-1][j - set[i-1]];
		}
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= sum; ++j)
			std::cout << subset[i][j] << " ";
		std::cout << "\n";
	}

	return subset[n][sum];
}

int main(void) {
	int sum = 0, n = 0;
	std::cin >> sum >> n;
	int set[n] = {0};
	for (int i = 0; i < n; ++i)
		std::cin >> set[i];
	std::cout << "\n" << calc(set, n, sum);
	return 0;
}