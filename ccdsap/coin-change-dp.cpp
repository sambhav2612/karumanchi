#include <bits/stdc++.h>

int calc(int *array, int n, int m) {
	int table[m+1] = {0};
	table[0] = 1;

	for (int i = 0; i < n; ++i)
		for (int j = array[i]; j <= m; ++j)
			table[j] += table[j - array[i]];

	return table[n];
}

int main(void) {
	int n = 0, m = 0;
	clock_t begin, end;
	double time_spent;
	std::cin >> n >> m;
	int array[n] = {0};
	for (int i = 0; i < n; ++i)
		std::cin >> array[i];
	begin = clock();
	std::cout << "\n" << calc(array, n, m);
	end = clock();
	time_spent = (double)(end - begin)/CLOCKS_PER_SEC;
	std::cout << "\n" << "Time Taken - " << time_spent;
	return 0;
}