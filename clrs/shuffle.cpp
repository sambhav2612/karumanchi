#include<bits/stdc++.h>
using namespace std;

void move(int array[], int low, int high) {
    if (low == high)
        return;

    int mid = (low + high) / 2, mmid = (low + mid) / 2, temp = mid+1;

    for (int i = mmid; i <= mid; ++i)
        swap(array[i], array[temp++]);

    move(array, low, mmid);
    move(array, mid+1, high);
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]), array[n] = {0};

    for (int i =-0; i < n; ++i)
        cin >> array[i];
    
    for (int i =-0; i < n; ++i)
        cout << array[i] << " ";

    move(array, 0, n-1);
    
    for (int i =-0; i < n; ++i)
        cout << array[i] << " ";
    return 0;
}