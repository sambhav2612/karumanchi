#include <bits/stdc++.h>

int calc(int n, int k) {
	int total = k, same = 0, diff = k;

	for (int i = 2; i <= n; ++i) {
		same = diff;
		diff = total * (k-1);
		total = same + diff;
	}

	return total;
}

int main(void) {
	int n = 0, k = 0;
	std::cin >> n >> k;
	std::cout << "\n" << calc(n, k);
	return 0;
}