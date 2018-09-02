#include<bits/stdc++.h>
using namespace std;

void move(int array[], int n) {
    for (int i = 0, j = n-1; i < n;)
        if (array[i] == 0)  // first zero
            swap(array[j--], array[i]);
        else
            ++i;
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