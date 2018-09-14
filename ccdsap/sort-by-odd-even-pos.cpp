#include <bits/stdc++.h>
using namespace std;

void rearrange(int array[], int n) {
    int aux[n] = {0};
    
    for (int i = 0; i < n; ++i)
        aux[i] = array[i];

    sort(aux, aux + n);

    for (int i = n-n/2-1, j = 0; i > 0; i--, j += 2)
        array[j] = aux[i];

    for (int i = n-n/2, j = 1; i < n; i++, j += 2)
        array[j] = aux[i];
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]), array[n] = {0};

    int i = 0;
    while (i++ < n)
        cin >> array[i];

    i = 0;
    while (i++ < n)
        cout << array[i] << " ";

    rearrange(array, n);
    
    i = 0;
    while (i++ < n)
        cout << array[i] << " ";

    return 0;
}