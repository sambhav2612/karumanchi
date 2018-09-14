#include<bits/stdc++.h>
using namespace std;

void move(int array[], int n) {
    for (int i = 0; i < n-1; ++i) {
        if (i%2 == 0 && array[i] < 0 && array[i+1] >= 0)
            swap(array[i], array[i+1]);
        if (i%2 != 0 && array[i] >= 0 && array[i+1] < 0)
            swap(array[i], array[i+1]);
    }
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]), array[n] = {0};

    for (int i =-0; i < n; ++i)
        cin >> array[i];
    
    for (int i =-0; i < n; ++i)
        cout << array[i] << " ";

    move(array, n);
    
    for (int i =-0; i < n; ++i)
        cout << array[i] << " ";
    return 0;
}