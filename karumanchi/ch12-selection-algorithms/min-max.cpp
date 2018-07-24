#include "../headers.hpp"
using namespace std;

void find_min_max(int *array, int n)
{
	int max = INT_MIN, min = INT_MAX;
	for (int i = 0; i < n; ++i)
		if (array[i] < array[i + 1]) // array[i] must be smaller one hence it should be compared for minimum element and vice versa
		{
			if (array[i] < min)
				min = array[i];
			if (array[i + 1] > max)
				max = array[i + 1];
		}
		else
		{
			if (array[i + 1] < min)
				min = array[i + 1];
			if (array[i] > max)
				max = array[i];
		}
	cout << endl
		 << "Smallest - " << min << "\nLargest - " << max;
}

int main(int argc, char **argv)
{
	int n = atoi(argv[1]), array[n] = {0};
	for (int i = 0; i < n; ++i)
		cin >> array[i];
	find_min_max(array, n);
	return 0;
}
