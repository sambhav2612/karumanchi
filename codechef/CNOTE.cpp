#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	int result[10000] = {0};

	cin >> t;

	if (t >= 1 && t <= 10000)
	{
		for (int j = 0; j < t; ++j)
		{
			int x, y, k, n;
			cin >> x >> y >> k >> n;

			if (y >= 1 && y < x && x <= 1000)
				if ((k >= 1 && k <= 1000) && (n >= 1 && n <= 10000))
					for (int i = 0; i < n; ++i)
					{
						int pi, ci;
						cin >> pi >> ci;

						if ((pi >= 1 && pi <= 1000) && (ci >= 1 && ci <= 1000))
							if (y + pi >= x && ci <= k) // all requirements were covered
								result[j] = 1;
							else
								result[j] = 0;
					}
		}

		for (int j = 0; j < t; ++j)
		{
			if (result[j] == 1)
				cout << "LuckyChef";
			else
				cout << "UnluckyChef";
			cout << endl;
		}
	}
	return 0;
}
