#include "sort.hpp"

int main(int argc, char const *argv[])
{
    int size = atoi(argv[1]), i, k = atoi(argv[2]);
    int array[size] = {0}, array2[size] = {0};

    for (i = 0; i < size; ++i)
        cin >> array[i];

    for (i = 0; i < size; ++i)
        cout << array[i] << " ";

    countingsort(array, array2, size, k);

    cout << endl;
    for (i = 0; i < size; ++i)
        cout << array2[i] << " ";

    return 0;
}
