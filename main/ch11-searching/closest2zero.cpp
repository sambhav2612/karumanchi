#include "../ch10-sorting/sort.hpp"
using namespace std;

int findk(int *array, int size)
{
    int p = INT_MAX, n = INT_MIN;
    for (int i = 0, j = size - 1; j > i;)
    {
        int temp = array[i] + array[j];
        if (temp > 0)
        {
            if (temp < p)
                p = temp;
            --j;
        }
        else if (temp < 0)
        {
            if (temp > n)
                n = temp;
            ++i;
        }
        else
            cout << "Closest sum - " << temp;
    }
    return (abs(n) > p) ? p : n;
}

int main(int argc, char **argv)
{
    int n = atoi(argv[1]), array[n] = {0};
    for (int i = 0; i < n; ++i)
        cin >> array[i];
    bucketsort(array, n);
    cout << endl
         << findk(array, n);
    return 0;
}
