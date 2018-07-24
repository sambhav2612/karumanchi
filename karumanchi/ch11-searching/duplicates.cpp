#include "../ch10-sorting/sort.hpp"
using namespace std;

bool duplicate(int *array, int size)
{
    for (int i = 0; i < size; ++i)
        if (array[i] == array[i + 1])
            return true;
    return false;
}

bool dup_hash_table(int *array, int size)
{
    int *max = max_element(array, array + size);
    int hash_table[*max + 1] = {0};

    for (int i = 0; i < *max + 1; ++i)
        //{
        // check if hash table entry has been already made for one of them
        if (hash_table[array[i]] == 1)
            return true;
        else
            hash_table[array[i]]++;

    //cout << hash_table[i];
    //}
    return false;
}

bool dup_by_index(int *array, int size)
{
    for (int i = 0; i < size; ++i)
        if (array[array[i]] != -array[array[i]])
            array[array[i]] = -array[array[i]];
        else
            return true;
    return false;
}

int main(int argc, char **argv)
{
    int n = atoi(argv[1]), array[n] = {0};
    for (int i = 0; i < n; ++i)
        cin >> array[i];
    cout << endl
         << dup_by_index(array, n);
    cout << endl
         << dup_hash_table(array, n);
    bucketsort(array, n);
    cout << endl
         << duplicate(array, n);
    return 0;
}
