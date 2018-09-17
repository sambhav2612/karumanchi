#include <bits/stdc++.h>

int calc(int x, int n) {
	int catalan[n+1] = {0};
	catalan[0] = catalan[1] = 1;

	for (int i = 2; i <= n; ++i) {
		catalan[i] = 0;
		for (int j = 0; j < i; ++i)
			catalan[i] += catalan[j] * catalan[i-j-1];
	}
}

int main(void) {
	int n = 0;
	clock_t begin, end;
	double time_spent;
	std::cin >> n;
	begin = clock();
	for (int i = 0; i < n; ++i)
		std::cout << "\n" << calc(i);
	end = clock();
	time_spent = (double)(end - begin)/CLOCKS_PER_SEC;
	std::cout << "\n" << "Time Taken - " << time_spent;
	return 0;
}