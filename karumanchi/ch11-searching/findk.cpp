#include "../ch10-sorting/sort.hpp"
using namespace std;

bool findk(int *array, int size, int k)
{
    for (int i = 0, j = size - 1; j > i;)
    {
        if (array[i] + array[j] == k)
            return true;
        else if (array[i] + array[j] < k)
            ++i;
        else
            --j;
    }
    return false;
}

bool findk_hash_table(int *array, int size, int k)
{
    int *max = max_element(array, array + size);
    int hash_table[*max + 1] = {0};

    for (int i = 0; i < *max + 1; ++i)
    {
        hash_table[array[i]]++;
        if (hash_table[k - array[i]] != 0)
            return true;
    }
    return false;
}

int main(int argc, char **argv)
{
    int n = atoi(argv[1]), k = atoi(argv[2]), array[n] = {0};
    for (int i = 0; i < n; ++i)
        cin >> array[i];
    //bucketsort(array, n);
    cout << endl
         << findk(array, n, k)
         << endl
         << findk_hash_table(array, n, k);
    return 0;
}
