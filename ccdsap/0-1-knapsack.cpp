#include <bits/stdc++.h>

int calc(int *value, int *weights, int w, int n) {
	int table[n+1][w+1] = {0};
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= w; ++i) {
			if (i == 0 || j == 0)
				table[i][j] = 0;
			else if (weights[i-1] <= j)
				table[i][j] = std::max(value[i-1] + table[i-1][j-weights[i-1]], table[i-1][j]);
			else
				table[i][j] = table[i-1][j];
		}
	return table[n][w];
}

int main(void) {
	int n = 0, w = 0;
	std::cin >> n >> w;
	int value[n] = {0}, weights[n] = {0};
	for (int i = 0; i < n; ++i)
		std::cin >> value[i] >> weights[i];
	std::cout << "\n" << calc(value, weights, w, n);
	return 0;
}