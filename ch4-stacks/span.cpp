#include "../headers.h"

int main()
{
	int n = 0;
	cin >> n;

	int array[n] = {0};
	for (int i = 0; i < n; ++i)
	{
		cin >> array[i];
	}

	int span[n] = {1};

	for (int i = 0; i < n; ++i)
	{
		int j = 1;

		while (j <= i && array[i] > array[i - j])
		{
			++j;
		}

		span[i] = j;
	}

	cout << endl
		 << "index"
		 << "\t"
		 << "array"
		 << "\t"
		 << "span"
		 << "\n";
		 
	for (int i = 0; i < n; ++i)
	{
		cout << i << "\t" << array[i] << "\t" << span[i] << "\n";
	}

	return 0;
}
