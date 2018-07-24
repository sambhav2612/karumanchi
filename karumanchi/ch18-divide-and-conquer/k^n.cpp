#include "../headers.hpp"
using namespace std;

int calc(int k, int n)
{
	if (k == 0)
		return 1;
	else if (n == 0)
		return 1;
	else
	{
		if (n % 2 == 1)
		{
			int a = calc(k, n - 1);
			return a * k;
		}
		else
		{
			int a = calc(k, n / 2);
			return a * a;
		}
	}
}

int main(int argc, char const *argv[])
{
	int k = atoi(argv[1]), n = atoi(argv[2]);
	cout << endl
		 << calc(k, n);
	return 0;
}
