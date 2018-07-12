#include "../ch10-sorting/sort.hpp"

void symmetric(int m, int *a, int s)
{
    for (int i = 0, j = m - 1; j > i;)
    {
        if (a[i] + a[j] == s && (a[i] + a[j]) % s == 0)
            cout << "Pair " << i + 1 << " {" << a[i] << ", " << a[j] << "} at indexes " << i++ << " and " << j-- << endl;
        else if (a[i] + a[j] < s)
            ++i;
        else
            --j;
    }
}

int main(int argc, char **argv)
{
    int m = atoi(argv[1]), s = atoi(argv[2]), i;
    int a[m] = {0};

    for (i = 0; i < m; ++i)
        cin >> a[i];

    cout << endl
         << "Array - " << endl;
    for (i = 0; i < m; ++i)
        cout << a[i] << " ";

    cout << endl
         << endl;

    bucketsort(a, m);
    symmetric(m, (int *)a, s);

    return 0;
}
