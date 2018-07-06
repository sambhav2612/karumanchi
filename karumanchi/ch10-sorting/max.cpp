#include "sort.h"

void candidate(int result[], int n)
{
	int count = 1, Number = result[0];
	int j = 0;

	for (int i = 1; i <= n; ++i)
	{
		if (result[i] == result[j])
		{
			++count;
			Number = result[i];
		}
		j = i;
	}

	cout << endl
		 << Number << " was found " << count << " times!";
}

int main(int argc, char const *argv[])
{
	int n = atoi(argv[1]);
	int votes[n] = {0};

	for (int i = 0; i < n; ++i)
		cin >> votes[i];

	bucketsort(votes, n);
	candidate(votes, n);

	return 0;
}
