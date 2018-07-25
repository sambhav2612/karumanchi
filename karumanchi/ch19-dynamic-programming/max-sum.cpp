#include "../headers.hpp"
using namespace std;

int calc(int *array, int n)
{
	int m[n], max = 0;
	if (array[0] > 0)
		m[0] = array[0];
	else
		m[0] = 0;
	for (int i = 1; i < n; ++i)
	{
		if (m[i + 1] + array[i] > 0)
			m[i] = m[i - 1] + array[i];
		else
			m[i] = 0;
	}
	for (int i = 0; i < n; ++i)
		if (m[i] > max)
			max = m[i];
	return max;
}

int main(int argc, char const *argv[])
{
	int n = atoi(argv[1]), array[n] = {0}, i;
	for (i = 0; i < n; ++i)
		cin >> array[i];
	cout << endl
		 << calc(array, n);
	return 0;
}
