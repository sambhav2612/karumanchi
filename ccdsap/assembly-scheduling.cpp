// Refer: https://www.geeksforgeeks.org/assembly-line-scheduling-dp-34/

#include <bits/stdc++.h>

int a[1000][1000] = {0};
int t[1000][1000] = {0};

int calc(int *e, int *x, int n) {
	int t1[n] = {0}, t2[n] = {0};
	t1[0] = e[0] + a[0][0];		// first job time on line 1
	t2[0] = e[1] + a[1][0];		// first job time on line 2
	for (int i = 1; i < n; ++i) {
		t1[i] = std::min(t1[i-1] + a[0][i], t2[i-1] + t[1][i] + a[0][i]);
		t1[i] = std::min(t2[i-1] + a[1][i], t1[i-1] + t[0][i] + a[1][i]);
	}
	std::cout << "\n";
	for (int i = 0; i < n; ++i)
		std::cout << t1[i] << "\t" << t2[i] << "\n";
	return std::min(t1[n-1] + x[0], t2[n-1] + x[1]);
}
	
int main(void) {
	int n = 0;
	std::cin >> n;
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < n; ++j)
			std::cin >> a[i][j] >> t[i][j];
	int e[2] = {0}, x[2] = {0};
	for (int i = 0; i < 2; ++i)
		std::cin >> e[i] >> x[i];
	std::cout << "\n" << calc(e, x, n);
	return 0;
}