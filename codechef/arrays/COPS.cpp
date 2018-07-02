#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;

	while (t-- > 0)
	{
		int m, x, y;
		cin >> m >> x >> y;

		int array[m] = {0};

		for (int i = 0; i < m; ++i)
			cin >> array[i];

		int sum = 0, flag = 0;

		for (int i = 0; i < m; ++i)
		{
			if (sum >= 100)
				break;

			if ((sum + x * y) > 100)
			{
				flag = 1;
				break;
			}

			if (x * y > array[i])
				sum += array[i];
			else
				sum += x * y;

			sum += 1; // for this ith house itself
			if (array[i + 1] - array[i] > x * y)
				sum += x * y;
		}

		if (!flag)
			cout << 100 - sum;
		else
			cout << "0";
		cout << endl;
	}

	return 0;
}
