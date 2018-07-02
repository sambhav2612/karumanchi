#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;

	int result[t] = {0};

	if (t >= 1 && t <= 100)
	{
		for (int i = 0; i < t; ++i)
		{
			int n;
			cin >> n;

			if (n >= 7 && n <= 100)
			{
				int array[n] = {0};
				for (int j = 0; j < n; ++j)
				{
					cin >> array[i];
				}

				int flag;

				for (int j = 0, k = n - 1; j < k; ++j, --k)
				{
					if (array[j] != array[k] || array[i] < 1 || array[i] > 7)
					{
						flag = 0;
						break;
					}
					else
					{
						flag = 1;
						continue;
					}
				}

				if (flag)
					result[i] = 1;
				else
					result[i] = 0;
			}
		}

		for (int i = 0; i < t; ++i)
		{
			if (result[i])
				cout << "yes";
			else
				cout << "no";
			cout << endl;
		}
	}

	return 0;
}
