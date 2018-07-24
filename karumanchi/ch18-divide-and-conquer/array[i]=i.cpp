// In the book it is written that running binary search idrectly would not produce results as they're expected. I do not know why though as this seems to be working.

#include "../headers.hpp"
using namespace std;

int check_array_at_i_equals_i(int *array, int low, int high)
{
	int mid = low + (high - low) / 2;
	if (array[mid] == mid)
		return mid;
	else if (array[mid] > mid)
		return check_array_at_i_equals_i(array, mid + 1, high);
	else
		return check_array_at_i_equals_i(array, low, mid - 1);
	return -1;
}

int main(int argc, char const *argv[])
{
	int n = atoi(argv[1]), array[n] = {0};
	for (int i = 0; i < n; ++i)
		cin >> array[i];
	cout << endl
		 << check_array_at_i_equals_i(array, 0, n - 1);
	return 0;
}
