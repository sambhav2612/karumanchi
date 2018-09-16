#include <bits/stdc++.h>

int calc(int n, int k) {
	int table[n+1][k+1] = {0};
	
	for (int i = 0; i <= n; ++i)
		for(int j = 0; j <= std::min(i,k); ++j) {
			if (j == 0 || j == i)
				table[i][j] = 1;
			else
				table[i][j] = table[i-1][j-1] + table[i-1][j];
		}

	return table[n][k];
} 

int main(void) {
	int n = 0, k = 0;
	std::cin >> n >> k;
	std::cout << "\n" << calc(n, k);
	return 0;
}