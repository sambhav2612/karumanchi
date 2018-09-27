#include <bits/stdc++.h>

int dp[1000][1000] = {0};

int calc(std::string str1, std::string str2, int m = 0, int n = 0) {
	for (int i = 0; i <= m; ++i)
		for (int j = 0; j <= n; ++j) {
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (str1[i-1] == str2[j-1])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
		}
	int index = dp[m][n];
	char lcs[index+1];
	lcs[index] = '\0';
	int i = m, j = n;
	while ( i > 0 && j > 0) {
		if (str1[i-1] == str2[j-1]) {
			lcs[index-1] = str1[i-1];
			--i;	--j;	--index;
		} else if (dp[i-1][j] > dp[i][j-1])
			--i;
		else
			--j;
	}
	std::cout << lcs;
	return dp[m][n];
}

int main(void) {
	std::string str1 = "" , str2 = "";
	getline(std::cin, str1);
	getline(std::cin, str2);
	std::cout << "\n" << calc(str1, str2, str1.length(), str2.length()); 
	return 0;
}