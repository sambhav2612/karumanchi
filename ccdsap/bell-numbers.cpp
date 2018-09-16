#include <bits/stdc++.h>

int calc(int n) {
	int table[n+1][n+1] = {0};
	table[0][0] = 1;
	
	for (int i = 1; i <= n; ++i) {
		table[i][0] = table[i-1][i-1];
		for(int j = 1; j <= n; ++j)
			table[i][j] = table[i-1][j-1] + table[i][j-1];
	}
	
	return table[n][0];
} 

int main(void) {
	int n = 0;
	std::cin >> n;
	std::cout << "\n" << calc(n);
	return 0;
}