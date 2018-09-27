#include <bits/stdc++.h>

int calc(int n) {
	__asm__ ("movl	%eax, n;"
		 	 "addl 	%eax, 20;"
		 	 "movl 	n, %eax;");
	return n;
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