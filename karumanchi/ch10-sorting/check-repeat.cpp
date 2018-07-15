#include "sort.hpp"

bool check(int array[], int size)
{
    bucketsort(array, size);
    for (int i = 0; i < size; ++i)
        if (array[i] == array[i + 1])
            return true;
    return false;
}

int main(int argc, char const *argv[])
{
    int size = atoi(argv[1]);
    int array[size] = {0};
    for (int i = 0; i < size; ++i)
        cin >> array[i];

    if (check(array, size))
        cout << "Repeatitions Found!";
    else
        cout << "No repeatitions found!";

    return 0;
}
