#include <bits/stdc++.h>
using namespace std;

void calc(int *array, int n) {
    int max_so_far = INT_MIN, current_max = 0, start = 0, end = 0, s = 0;

    for (int i = 0; i < n; ++i) {
        current_max += array[i];
        if (max_so_far < current_max) {
            max_so_far = current_max;
            start = s;
            end = i;
        }
        if (current_max < 0) {
            current_max = 0;
            s = i + 1;
        }
    }

    cout << "\nSum - " << max_so_far << "\nSubarray - ";
    for (int i = start; i <= end; ++i)
        cout << array[i] << " ";
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]), array[n] = {0};
    for (int i = 0; i < n; ++i)
        cin >> array[i];
    calc(array, n);
    return 0;
}