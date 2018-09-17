#include<bits/stdc++.h>
using namespace std;

void move(int array[], int n) {
    srand(time(NULL));
    for (int i = n-1; i > 0; --i) {
        int j = rand() % (i+1);
        swap(array[i], array[j]);
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