#include "../headers.hpp"
using namespace std;

void calc(int n)
{
	unsigned long long a = 0, b = 1, sum = 0;
	cout << a << " " << b << " ";
	for (int i = 0; i < n; ++i)
	{
		sum = a + b;
		cout << sum << " ";
		a = b;
		b = sum;
	}
}

int main(int argc, char const *argv[])
{
	int n = atoi(argv[1]);
	cout << endl;
	calc(n);
	return 0;
}
