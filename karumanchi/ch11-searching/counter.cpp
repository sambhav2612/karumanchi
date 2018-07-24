#include "../ch10-sorting/sort.hpp"
using namespace std;

int duplicate(int *array, int size)
{
    int counter = 0, max = 0;
    for (int i = 0; i < size; ++i)
    {
        if (array[i] == array[i + 1])
            ++counter;
        if (max < counter)
            max = array[i];
    }
    return max;
}

int dup_hash_table(int *array, int size)
{
    int *max_ele = max_element(array, array + size), counter = 0, max = 0;
    int hash_table[*max_ele + 1] = {0};

    for (int i = 0; i < *max_ele + 1; ++i)
        hash_table[array[i]]++;
    for (int i = 0; i < *max_ele + 1; ++i)
        if (hash_table[i] > counter)
            counter = i;
    if (max < counter)
        max = counter;
    return max;
}

int dup_by_index(int *array, int size)
{
    int max = 0, index = 0;
    for (int i = 0; i < size; ++i)
        array[array[i] % size] += size;
    for (int i = 0; i < size; ++i)
        if (array[i] / size > max)
        {
            max = array[i] / size;
            index = i;
        }
    for (int i = 0; i < size; ++i)
        array[array[i] % size] -= size;
    return array[index];
}

int main(int argc, char **argv)
{
    int n = atoi(argv[1]), array[n] = {0};
    for (int i = 0; i < n; ++i)
        cin >> array[i];
    cout << endl
         << dup_hash_table(array, n);
    bucketsort(array, n);
    cout << endl
         << duplicate(array, n);
    cout << endl
         << dup_by_index(array, n);
    return 0;
}
