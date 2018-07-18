#include "../headers.hpp"
using namespace std;

int index(int *array, int size, int x)
{
    for (int i = 0; i < size; ++i)
        if (array[i] == x)
            return i;
    return -1;
}

int dup_hash_table(int *array, int size)
{
    int *max_ele = max_element(array, array + size), counter = 0, max = 0;
    int hash_table[*max_ele + 1] = {0};

    for (int i = 0; i < *max_ele + 1; ++i)
    {
        if (-hash_table[array[i]])
            continue;
        else if (hash_table[array[i]] != index(array, size, array[i]) + 1)
            hash_table[array[i]] = index(array, size, array[i]) + 1;
        else
            hash_table[array[i]] = -hash_table[array[i]];
    }
    return max;
}

int main(int argc, char **argv)
{
    int n = atoi(argv[1]), array[n] = {0};
    for (int i = 0; i < n; ++i)
        cin >> array[i];
    cout << endl
         << dup_hash_table(array, n);
    return 0;
}
