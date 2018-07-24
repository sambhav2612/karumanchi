#include "../ch10-sorting/sort.hpp"
using namespace std;

int dup_hash_table(int *array, int size)
{
    int *max_ele = max_element(array, array + size);
    int hash_table[*max_ele + 1] = {0};

    for (int i = 0; i < *max_ele + 1; ++i)
        hash_table[array[i]] = 1;
    for (int i = 0; i < *max_ele + 1; ++i)
        if (hash_table[i] != 1)
            return i;

    return -1;
}

int xy(int *array, int size)
{
    int x = 0, y = 0;
    for (int i = 0; i < size; ++i)
        x ^= array[i];
    for (int i = 1; i <= size; ++i)
        y ^= i;
    return x ^ y;
}

int main(int argc, char **argv)
{
    int n = atoi(argv[1]), array[n] = {0};
    for (int i = 0; i < n; ++i)
        cin >> array[i];
    bucketsort(array, n);
    cout << endl
         << xy(array, n) << endl
         << dup_hash_table(array, n);
    return 0;
}
