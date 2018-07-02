#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int t, count = 0;

	cin >> t;

	if (t >= 1 && t <= 100)
	{
		for (int j = 0; j < t; ++j)
		{
			int k, n;
			cin >> n >> k;

			int array[100] = {0};

			if ((k >= 1 && k <= 100) && (n >= 1 && n <= 100))
				for (int i = 0; i < n; ++i)
				{
					cin >> array[i];
					array[i] += k;

					if (array[i] % 7 == 0) // all requirements were covered
						++count;
				}
		}

		cout << count;
	}

	return 0;
}
