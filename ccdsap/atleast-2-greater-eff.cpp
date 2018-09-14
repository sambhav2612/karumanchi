// working

#include <bits/stdc++.h>
using namespace std;

void greaterFX(int array[], int n) {
    int first = INT_MIN, second = INT_MIN;
    for (int i = 0; i < n; ++i) {
        if (array[i] > first) {
            second = first;
            first = array[i];
        }
        else if (array[i] > second)
            second = array[i];
    }

    for (int i = 0; i < n; ++i)
        if (array[i] < second)
            cout << array[i] << " ";
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    int array[n] = {0};

    for(int i = 0; i < n; ++i)
        cin >> array[i];

    cout << endl;
    greaterFX(array, n);

    return 0;
}