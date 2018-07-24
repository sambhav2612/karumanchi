#include "../headers.hpp"
using namespace std;

void calc(int *array, int low, int high)
{
	int mid = low + (high - low) / 2, q = 2 + (mid - 1) / 2;
	if (low == high)
		return;
	for (int k = 1, i = q; i <= mid; ++i, ++k)
		swap(array[i], array[mid + k]);
	calc(array, 0, mid - 1);
	calc(array, mid + 1, high);
}

int main(int argc, char const *argv[])
{
	int n = atoi(argv[1]), array[n] = {0};
	for (int i = 0; i < n; ++i)
		cin >> array[i];
	cout << endl
		 << "Before - ";
	for (int i = 0; i < n; ++i)
		cout << array[i] << " ";
	calc(array, 0, n - 1);
	cout << endl
		 << "After - ";
	for (int i = 0; i < n; ++i)
		cout << array[i] << " ";

	return 0;
}
