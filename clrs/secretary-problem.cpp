#include <bits/stdc++.h>
using namespace std;
#define e 2.71828

float round(float num) {
    return (num < 0) ? num - 0.5 : num + 0.5;
}

void calc(int *array, int n) {
    int sample = round(n/e);

    int i = 0;
    for (int j = 1; j < sample; ++j)
        if (array[j] > array[i])
            i = j;

    for (int j = sample; j < n; ++j)
        if (array[j] > array[i]) {
            i = j;
            break;
        }

    cout << "\nBest element is at " << i + 1 << " position with value " << array[i];
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]), array[n] = {0};
    srand(time(0));
    for (int i = 0; i < n; ++i)
        array[i] = 1 + rand() % 8;
    for (int i = 0; i < n; ++i)
        cout << "\nCandidate " << i+1 << " with value " << array[i];
    calc(array, n);
    return 0;
}