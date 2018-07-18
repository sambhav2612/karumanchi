#include "../headers.hpp"
using namespace std;

int *bin_search(int *array, int low, int high)
{
    int mid = 0;
    while (mid <= high)
    {
        switch (array[mid])
        {
        case 0:
            swap(array[low], array[mid]);
            ++low;
            ++mid;
            break;
        case 1:
            ++mid;
            break;
        case 2:
            swap(array[mid], array[high]);
            --high;
            break;
        }
    }
    return array;
}

int main(int argc, char **argv)
{
    int n = atoi(argv[1]), array[n] = {0};
    for (int i = 0; i < n; ++i)
        cin >> array[i];
    cout << endl
         << "Original Array - ";
    for (int i = 0; i < n; ++i)
        cout << array[i] << " ";
    int *arr = bin_search(array, 0, n - 1);
    cout << endl
         << "Sorted Array  - ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    return 0;
}
