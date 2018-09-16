// Tabulation

#include <bits/stdc++.h>

int calc(int n) {
	unsigned long long table[n+1] = {0};

	table[0] = 0;
	table[1] = 1;

	for (int i = 2; i <= n; ++i)
		table[i] = table[i-1] + table[i-2];

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