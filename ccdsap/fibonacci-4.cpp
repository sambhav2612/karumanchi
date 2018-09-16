// Using 2 variables

#include <bits/stdc++.h>

int calc(int n) {
	int a = 0, b = 1;
	if (n >= 0)
		std::cout << a << " ";
	if (n >= 1)
		std::cout << b << " ";
	
	for (int i = 2; i < n; ++i) {
		std::cout << a + b << " ";
		b = a + b;
		a = b - a;
	}
}

int main(void) {
	int n = 0;
	clock_t begin, end;
	double time_spent;
	std::cin >> n;
	begin = clock();
	std::cout << "\n";
	calc(n);
	end = clock();
	time_spent = (double)(end - begin)/CLOCKS_PER_SEC;
	std::cout << "\n" << "Time Taken - " << time_spent;
	return 0;
}