#include "../headers.h"

int checkSorting(int array[], int n)
{

	// single element
	if (n == 1)
	{
		return 1;
	}

	return (array[n - 1] <= array[n - 2]) ? 0 : checkSorting(array, n - 1);
}

int main()
{
	int n = 0;
	char yes = 'y';

	do
	{

		cout << "Enter # elements: ";
		cin >> n;

		int array[n] = {0};

		cout << "Enter elements: ";
		for (int i = 0; i < n; ++i)
		{
			cin >> array[i];
		}

		if (checkSorting(array, n))
		{
			cout << "SORTED" << endl;
		}
		else
		{
			cout << "UNSORTED" << endl;
		}

		cout << "\n\nRun again?";
		cin >> yes;

	} while (yes == 'y' || yes == 'Y');
	return 0;
}
