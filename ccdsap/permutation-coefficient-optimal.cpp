#include <bits/stdc++.h>

int calc(int n, int k) {
	int fn = 1, fk = 0;

	for (int  i = 1; i <= n; ++i) {
		fn *= i;
		if (i == n - k)
			fk = fn;
	}

	return (fn / fk);
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