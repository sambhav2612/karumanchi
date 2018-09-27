#include <bits/stdc++.h>

int dp[1000][1000] = {0};

int calc(std::string str1, std::string str2, int m = 0, int n = 0) {
	bool bi;
	for (int i = 0; i <= m; ++i) {
		bi = i & 1;
		for (int j = 0; j <= n; ++j) {
			if (i == 0 || j == 0)
				dp[bi][j] = 0;
			else if (str1[i-1] == str2[j-1])
				dp[bi][j] = dp[1-bi][j-1] + 1;
			else
				dp[bi][j] = std::max(dp[1-bi][j], dp[bi][j-1]);
		}
	}
	return dp[bi][n];
}

int main(void) {
	std::string str1 = "" , str2 = "";
	getline(std::cin, str1);
	getline(std::cin, str2);
	std::cout << "\n" << calc(str1, str2, str1.length(), str2.length()); 
	return 0;
}