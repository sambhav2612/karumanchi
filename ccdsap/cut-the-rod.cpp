#include <bits/stdc++.h>

bool dp[10000] = {0};

bool calc(int *set, int n) {
	for (int i = 1; i <= n; ++i) {
		int max_val = INT_MIN;
		for (int j = 0; j < i; ++j)
			max_val = std::max(max_val, set[j] + dp[i-j-1]);
		dp[i] = max_val;
	}

	return dp[n];
}

int main(void) {
	int n = 0;
	std::cin >> n;
	int set[n] = {0};
	for (int i = 0; i < n; ++i)
		std::cin >> set[i];
	std::cout << "\n" << calc(set, n);
	return 0;
}