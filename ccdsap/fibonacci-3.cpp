// Space-efficient memoization based on the odd-even—ness of the number n

#include <bits/stdc++.h>
#define MAXN 1000

unsigned long long table[MAXN] = {0};

int calc3(int n) {

	if (n == 0)
		return 0;
	if (n == 1 || n == 2)
		return (table[n] = 1);

	if (table[n])
		return table[n];

	int k = (n & 1) ? (n+1)/2 : n/2;

	table[n] = (n & 1) ? (pow(calc3(k),2) + pow(calc3(k-1), 2)) : ((2 * calc3(k-1) + calc3(k)) * calc3(k));

	return table[n];
}

int main(void) {
	int n = 0;
	clock_t begin, end;
	double time_spent;
	std::cin >> n;
	begin = clock();
	std::cout << "\n" << calc3(n);
	end = clock();
	time_spent = (double)(end - begin)/CLOCKS_PER_SEC;
	std::cout << "\n" << "Time Taken - " << time_spent;
	return 0;
}