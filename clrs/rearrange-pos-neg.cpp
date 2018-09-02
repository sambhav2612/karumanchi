#include <bits/stdc++.h>
using namespace std;

void rearrange(int array[], int n) {
    int i = -1;

    for (int j = 0; j < n; ++j)
        if (array[j] < 0)
            swap(array[++i], array[j]);
    
    int pos = i+1, neg = 0;

    while (neg < pos && pos < n && array[neg] < 0) {
        swap(array[neg], array[pos++]);
        neg += 2;
    }
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