#include "../headers.hpp"

int find(int a[], int alo, int ahi, int b[], int blo, int bhi, int x)
{
    int amid = alo + (ahi - alo) / 2, bmid = blo + (bhi - blo) / 2;
    int amed = a[x], bmed = b[x];

    if (ahi - alo + bhi - blo < 4)
        return amed;
    else if (amed < bmed)
        find(a, amid, ahi, b, blo, bmid + 1, x);
    else
        find(a, alo, amid + 1, b, bmid + 1, bhi, x);
}

int main(int argc, char const *argv[])
{
    int n = atoi(argv[1]), k = atoi(argv[2]), x = atoi(argv[3]);
    int a[n] = {0}, b[k] = {0}, i;

    for (i = 0; i < n; ++i)
        cin >> a[i];

    for (i = 0; i < k; ++i)
        cin >> b[i];

    cout << endl
         << find(a, 0, n - 1, b, 0, k - 1, x);

    return 0;
}
