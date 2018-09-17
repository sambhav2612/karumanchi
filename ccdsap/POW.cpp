#include <bits/stdc++.h>

double calc(int x, int n) {
	double temp = 0.0;
	if (n == 0)
		return 1;
	temp = calc(x, n/2);
	if (n % 2 == 0)
		return temp*temp;
	else {
		if (n > 0)
			return x*temp*temp;
		else
			return (temp*temp)/x;
	}
}

int main(void) {
	int n = 0, x = 0;
	clock_t begin, end;
	double time_spent;
	std::cin >> x >> n;
	begin = clock();
	std::cout << "\n" << calc(x, n);
	end = clock();
	time_spent = (double)(end - begin)/CLOCKS_PER_SEC;
	std::cout << "\n" << "Time Taken - " << time_spent;
	return 0;
}