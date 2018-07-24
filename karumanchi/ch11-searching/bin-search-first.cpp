#include "../ch10-sorting/sort.hpp"
using namespace std;

int bin_search(int *array, int low, int high, int x)
{
    int mid = low + (high - low) / 2;
    if ((array[mid] == x && mid == low) || (array[mid] == x && array[mid - 1] < x))
        return mid;
    else if (array[mid] > x)
        return bin_search(array, low, mid - 1, x);
    else
        return bin_search(array, mid + 1, high, x);
    return -1;
}

int main(int argc, char **argv)
{
    int n = atoi(argv[1]), x = atoi(argv[2]), array[n] = {0};
    for (int i = 0; i < n; ++i)
        cin >> array[i];
    bucketsort(array, n);
    cout << bin_search(array, 0, n - 1, x);
    return 0;
}
