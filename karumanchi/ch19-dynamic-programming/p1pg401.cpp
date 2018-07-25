#include "../headers.hpp"
#define MAX 10000
using namespace std;

int t[MAX] = {0};
int calc1(int n)
{
	t[0] = t[1] = 2;
	for (int i = 2; i <= n; ++i)
		t[i] = 2 * t[i - 1] * t[i - 2];
	return t[n];
}

int calc2(int n)
{
	t[0] = t[1] = 2;
	t[2] = 2 * t[0] * t[1];
	for (int i = 3; i <= n; ++i)
		t[i] = t[i - 1] + 2 * t[i - 1] * t[i - 2];
	return t[n];
}

int main(int argc, char const *argv[])
{
	int n = atoi(argv[1]);
	cout << endl
		 << calc1(n) << endl
		 << calc2(n);
	return 0;
}
