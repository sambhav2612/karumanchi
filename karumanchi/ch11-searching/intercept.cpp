#include "../headers.hpp"
using namespace std;

int *intercept(int *array, int size)
{
    int n = size / 2;
    for (int i = 0, q = 1, k = n; i < n; ++i, ++q, ++k)
        for (int j = k; j > i + q; --j)
            swap(array[j - 1], array[j]);
    return array;
}

int main(int argc, char **argv)
{
    int n = atoi(argv[1]), array[n] = {0};
    for (int i = 0; i < n; ++i)
        cin >> array[i];
    cout << endl
         << "Original Array    - ";
    for (int i = 0; i < n; ++i)
        cout << array[i] << " ";
    int *arr = intercept(array, n);
    cout << endl
         << "Intercepted Array - ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    return 0;
}
