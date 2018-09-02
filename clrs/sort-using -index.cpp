#include<bits/stdc++.h>
using namespace std;

void move(int array[], int n, int index[]) {
    for (int i = 0; i < n; ++i)
        while (index[i] != i) {
            int oldI = index[index[i]];
            int oldE = array[index[i]];

            array[index[i]] = array[i];
            index[index[i]] = index[i];

            array[i] = oldE;
            index[i] = oldI;
        }
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]), array[n] = {0}, index[n] = {0};

    for (int i =-0; i < n; ++i)
        cin >> array[i];

    for (int i =-0; i < n; ++i)
        cin >> index[i];
    
    for (int i =-0; i < n; ++i)
        cout << array[i] << " ";

    move(array, n, index);
    
    for (int i =-0; i < n; ++i)
        cout << array[i] << " ";
    return 0;
}