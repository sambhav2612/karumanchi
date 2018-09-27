#include <bits/stdc++.h>

int calc(int *values, int *weights, int n, int W) {
	int array[n+1][W+1];
	for (int i = 0; i < W; ++i) 
		array[0][i] = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= W; ++j) {
			if (weights[i] < j)
				array[i][j] = std::max(array[i-1][j], values[i] + array[i-1][j - weights[i]]);
			else
				array[i][j] = array[i-1][j];
		}
	std::cout << "\n";
	for (int i = 0; i <= n; ++i)	{
		for (int j = 0; j <= W; ++j)
			std::cout << array[i][j] << " ";
		std::cout << "\n";
	}
	return array[n][W];
}

int main(void) {
	int n = 0, W = 0;
	std::cin >> n >> W;
	int values[n] = {0}, weights[n] = {0};
	for (int i = 0; i < n; ++i)
		std::cin >> values[i] >> weights[i];
	std::cout << "\n" << calc(values, weights, n, W);
	return 0;
}