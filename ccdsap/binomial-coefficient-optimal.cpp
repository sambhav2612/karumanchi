#include <bits/stdc++.h>

int calc(int n, int k) {
	int res = 1;

	if (k > n - k)
		k = n - k;

	for (int i = 0; i < k; ++i) {
		res *= (n - i);
		res /= (i + 1);
	}

	return res;
} 

int main(void) {
	int n = 0, k = 0;
	std::cin >> n >> k;
	std::cout << "\n" << calc(n, k);
	return 0;
}