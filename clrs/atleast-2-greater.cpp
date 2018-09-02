// working

#include <bits/stdc++.h>
using namespace std;

void greaterFX(int array[], int size) {
    int it = *max_element(array, array + size);
    int aux[it] = {0};
    for (int i = 0; i < it; ++i)
        aux[i] = 0;
    for (int i = 0; i < size; ++i) 
        aux[array[i]] += 1;
    for (int i = 1; i < size; ++i)
        aux[i] += aux[i-1]; // all elements greater than equal to current
    for (int i = 0; i < it; ++i)
        if (aux[i] <= 2)
            cout << array[aux[i]] << " ";
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