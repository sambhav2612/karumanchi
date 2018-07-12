#include "../headers.hpp"

int match(int a[], int b[], int n)
{
    int i, count = 0, *max = max_element(a, a + n);
    int hash_table[*max + 1] = {0};

    for (i = 0; i < n; ++i)
        hash_table[a[i]]++;

    for (i = 0; i < n;)
        if (hash_table[b[i++]] == 1)
            ++count;

    return (count % n == 0 && count == n) ? 1 : 0;
}

int main(int argc, char **argv)
{
    int n = atoi(argv[1]), i;
    int a[n] = {0}, b[n] = {0};

    for (i = 0; i < n; ++i)
        cin >> a[i];
    for (i = 0; i < n; ++i)
        cin >> b[i];

    cout << endl
         << "Array 1 - ";
    for (i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << endl
         << "Array 2 - ";
    for (i = 0; i < n; ++i)
        cout << b[i] << " ";

    cout << endl
         << endl;
    if (match(a, b, n))
        cout << "Arrays match!";
    else
        cout << "Arrays do not match!";

    return 0;
}
