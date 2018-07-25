#include "../headers.hpp"
#define BUCKETS 10
using namespace std;

void bucketsort(int start[], int size, int finish[])
{
	int b1[BUCKETS] = {0}, b2[BUCKETS] = {0}, i;

	for (i = 0; i < size; ++i)
	{
		++b1[finish[i]];
		++b2[start[i]];
	}

	for (int j = 0, i = 0, p = 0; j < BUCKETS; ++j)
	{
		for (int k = b1[j]; k > 0; --k)
			finish[i++] = j;
		for (int k = b2[j]; k > 0; --k)
			start[p++] = j;
	}
}

int main(int argc, char const *argv[])
{
	int n = atoi(argv[1]), start[n] = {0}, finish[n] = {0}, i;
	for (int i = 0; i < n; ++i)
		cin >> start[i] >> finish[i];
	dddbucketsort(start, n, finish);
	int *x = 0, count = 0;
	x[count] = 1;
	for (i = 1; i < n; ++i)
		if (start[i] > finish[x[count]])
			x[++count] = 1;
	cout << endl
		 << "O/P - ";
	for (i = 0; i < count; ++i)
		cout << x[i] << " ";

	return 0;
}
