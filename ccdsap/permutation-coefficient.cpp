#include <bits/stdc++.h>

int calc(int n, int k) {
	int fact[n+1] = {0};
	fact[0] = 1;

	for (int  i = 1; i <= n; ++i)
		fact[i] = fact[i-1] * i;

	return (fact[n]/fact[n-k]);
}

int main(void) {
	int n = 0, k = 0;
	clock_t begin, end;
	double time_spent;
	std::cin >> n >> k;
	begin = clock();
	std::cout << "\n" << calc(n, k);
	end = clock();
	time_spent = (double)(end - begin)/CLOCKS_PER_SEC;
	std::cout << "\n" << "Time Taken - " << time_spent;
	return 0;
}