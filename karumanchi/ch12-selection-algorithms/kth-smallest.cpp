#include "../headers.hpp"

int partition(int array[], int low, int high)
{
    int i, j = low, item = array[low];

    for (i = low + 1; i <= high; i++)
        if (array[i] < item)
        {
            j++;
            swap(array[i], array[j]);
        }

    int pivot = j;
    swap(array[low], array[pivot]);

    return pivot;
}

int select(int array[], int low, int high, int k)
{
    int pivot;
    if (low == high)
        return array[low];
    pivot = partition(array, low, high);
    if (k == pivot)
    {
        cout << endl
             << "returning";
        return array[pivot];
    }
    if (k < pivot)
    {
        cout << endl
             << pivot
             << " going to left";
        return select(array, low, pivot - 1, k);
    }
    if (k > pivot)
    {
        cout << endl
             << pivot
             << " going to right";
        return select(array, pivot + 1, high, k);
    }
}

int main(int argc, char const *argv[])
{
    int n = atoi(argv[1]), k = atoi(argv[2]), array[n] = {0}, i;

    for (i = 0; i < n; ++i)
        cin >> array[i];

    cout << endl
         << select(array, 0, n - 1, k);
    return 0;
}
