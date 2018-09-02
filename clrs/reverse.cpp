#include <bits/stdc++.h>
using namespace std;

void rearrange(int array[], int low, int high) {
    if (low >= high)
        return;
    swap(array[low], array[high]);
    return rearrange(array, low+1, high-1);
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]), array[n] = {0};

    int i = 0;
    while (i++ < n)
        cin >> array[i];

    i = 0;
    while (i++ < n)
        cout << array[i] << " ";

    rearrange(array, 0, n-1);
    
    i = 0;
    while (i++ < n)
        cout << array[i] << " ";

    return 0;
}