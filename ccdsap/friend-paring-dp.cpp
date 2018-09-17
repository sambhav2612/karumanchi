#include <bits/stdc++.h>

int calc(int n) {
	int table[n+1];

	for (int i = 0; i <= n; ++i) {
		if (i <= 2) 	// base cases
			table[i] = i;
		else
			table[i] = table[i-1] + (i-1) * table[i-2];
	}

	return table[n];
}

int main(void) {
	int n = 0;
	clock_t begin, end;
	double time_spent;
	std::cin >> n;
	begin = clock();
	std::cout << "\n" << calc(n);
	end = clock();
	time_spent = (double)(end - begin)/CLOCKS_PER_SEC;
	std::cout << "\n" << "Time Taken - " << time_spent;
	return 0;
}