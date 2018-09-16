#include <bits/stdc++.h>

int calc(int n, int k) {
	int table[n+1][k+1] = {0};
	
	for (int i = 0; i <= n; ++i)
		table[i][0] = 0;
	for (int i = 0; i <= k; ++i)		
		table[0][i] = 0;
	
	for (int i = 1; i <= n; ++i)
		for(int j = 1; j <= i; ++j) {
			if (j == 1 || j == i)
				table[i][j] = 1;
			else
				table[i][j] = j * table[i-1][j] + table[i-1][j-1];
		}

	return table[n][k];
} 

int main(void) {
	int n = 0, k = 0;
	std::cin >> n >> k;
	std::cout << "\n" << calc(n, k);
	return 0;
}