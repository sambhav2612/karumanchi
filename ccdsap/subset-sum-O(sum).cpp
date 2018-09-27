#include <bits/stdc++.h>

bool subset[2][10000] = {0};

bool calc(int *set, int n, int sum) {
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= sum; ++j) {
			if (j == 0)
				subset[i%2][j] = true;
			else if (i == 0)
				subset[i%2][j] = false;
			else if (j >= set[i-1])
				subset[i%2][j] = subset[(i+1)%2][j-set[i-1]] || subset[(i+1)%2][j];
			else
				subset[i%2][j] = subset[(i+1)%2][j];
		}
	return subset[n%2][sum];
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