#include <bits/stdc++.h>

int table[10000] = {0};

unsigned long long calc(int n) {
	table[0] = 1;
	int i2 = 0, i3 = 0, i5 = 0;
	int next_multiple_2 = table[i2] * 2;
	int next_multiple_3 = table[i3] * 3;
	int next_multiple_5 = table[i5] * 5;
	int next_ugly_number = 1;

	for (int i = 1; i < n; ++i) {
		next_ugly_number = std::min(next_multiple_2, std::min(next_multiple_3, next_multiple_5));
		table[i] = next_ugly_number;

		if (next_ugly_number == next_multiple_2) {
			++i2;
			next_multiple_2 = table[i2] * 2;
		}
		
		if (next_ugly_number == next_multiple_3) {
			++i3;
			next_multiple_3 = table[i3] * 3;
		}
		
		if (next_ugly_number == next_multiple_5) {
			++i5;
			next_multiple_5 = table[i5] * 5;
		}
	}

	return next_ugly_number;
} 

int main(void) {
	int n = 0;
	std::cin >> n;
	std::cout << "\n" << calc(n);
	return 0;
}