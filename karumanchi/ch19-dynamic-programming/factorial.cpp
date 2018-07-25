// factorial using dp
#include "../headers.hpp"
#define MAX 100000
using namespace std;

unsigned long long fact[MAX] = {0};
int calc(int n)
{
	if (n == 0 || n == 1)
		return 1;
	else if (fact[n] != 0)
		return fact[n];
	else
		return fact[n] = n * calc(n - 1);
}

int main(int argc, char const *argv[])
{
	int n = atoi(argv[1]);
	cout << endl
		 << calc(n);
	return 0;
}
