#include<bits/stdc++.h>
using namespace std;

void move(int array[], int n) {
    int count = n-1;
    for (int i = n-1; i >= 0 ; --i)
        if (array[i] != 0)
            swap(array[count--], array[i]);
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]), array[n] = {0};

    for (int i = 0; i < n; ++i)
        cin >> array[i];

    for (int i = 0; i < n; ++i)
        cout << array[i] << " ";

    move(array, n);

    cout << "\n";

    for (int i = 0; i < n; ++i)
        cout << array[i] << " ";
    return 0;
}