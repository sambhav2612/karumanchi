#include <bits/stdc++.h>

void calc(std::string str, int n) {
	if (n <= 0)
		return;		
	std::cout << str << "\t";
	return calc(str, n-1);
}

int main(void) {
	int n = 0;
	clock_t begin, end;
	double time_spent;
	std::cin >> n;
	begin = clock();
	std::cout << "\n";
	calc("Sambhav Jain", n);
	end = clock();
	time_spent = (double)(end - begin)/CLOCKS_PER_SEC;
	std::cout << "\n" << "Time Taken - " << time_spent;
	return 0;
}