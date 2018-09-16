// Memoization

#include <bits/stdc++.h>
#define MAXN 1000

unsigned long long table[MAXN] = {0};

int calc2(int n) {
	
	if (n == 0)
		return (table[0] = 0);
	else if (n == 1)
		return (table[1] = 1);
	else if (table[n])
		return table[n];
	else
		return (table[n] = calc2(n-1) + calc2(n-2));

}

int main(void) {
	int n = 0;
	clock_t begin, end;
	double time_spent;
	std::cin >> n;
	begin = clock();
	std::cout << "\n" << calc2(n);
	end = clock();
	time_spent = (double)(end - begin)/CLOCKS_PER_SEC;
	std::cout << "\nTime Taken - " << time_spent;
	return 0;
}