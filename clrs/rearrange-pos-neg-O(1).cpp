#include <bits/stdc++.h>
using namespace std;

void right_rotate(int array[], int n, int cur, int out_of_place) {
    int temp = array[out_of_place];
    for (int i = cur; i > 0; i--)
        array[i] = array[i-1];
    array[out_of_place] = temp;
}

void rearrange(int array[], int n) {
    for (int i = 0; i < n; ++i) {
        if (array[i] < 0 && i%2 != 0) {
            int j = i+1;
            for (; j < n; ++j)
                if (array[j] > 0)
                    break;
            right_rotate(array, n, j, i);
        }
        if (array[i] > 0 && i%2 == 0) {
            int j = i+1;
            for (; j < n; ++j)
                if (array[j] < 0)
                    break;
            right_rotate(array, n, j, i);
        }
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