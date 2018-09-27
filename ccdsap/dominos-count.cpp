#include <bits/stdc++.h>

int calc(int n) {
	int a[n+1] = {0}, b[n+1] = {0};
	a[0] = 1, a[1] = 0;
	b[0] = 0, b[1] = 1;
	for (int i = 2; i <= n; ++i) {
		a[i] = a[i-2] + 2 * b[i-1];
		b[i] = a[i-1] + b[i-2];
	}
	return a[n];
}

int main(void) {
	int n = 0;
	std::cin >> n;
	std::cout << "\n" << calc(n);
	return 0;
}