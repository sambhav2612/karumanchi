#include "adt.hpp"

int main(int argc, char const *argv[])
{
    int n = atoi(argv[1]), arr[n] = {0}, i;
    for (i = 0; i < n; i++)
        cin >> arr[i];

    make_set(arr, n);

    return 0;
}
