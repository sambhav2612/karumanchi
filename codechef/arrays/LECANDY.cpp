#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	int array[100] = {0}, result[100] = {0};

	cin >> t;

	for (int j = 0; j < t; ++j)
	{
		int n, c, sum = 0;
		cin >> n >> c;

		for (int i = 0; i < n; ++i)
		{
			cin >> array[i];
			sum += array[i];
		}

		if (sum > c)
		{
			result[j] = 0;
		}
		else
		{
			result[j] = 1;
		}

		sum = 0;
		array[n] = {0};
	}

	for (int i = 0; i < t; ++i)
	{
		if (result[i] == 0)
			cout << "No";
		else
			cout << "Yes";
		cout << endl;
	}

	return 0;
}
