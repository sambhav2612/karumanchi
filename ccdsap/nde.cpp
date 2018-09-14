#include <bits/stdc++.h>
using namespace std;

int hash_table[1000];

void next(int *array, int n) {
    stack<int> stk;
    stk.push(0);

    for (int i = 0; i < n; ++i)
        hash_table[array[i]]++;

    for (int i = 1; i < n; ++i) {
        if (stk.empty()) {
            stk.push(i);
            continue;
        }

        if (hash_table[stk.top()] > hash_table[array[i]])
            stk.push(i);

        while (!stk.empty() && hash_table[stk.top()] < hash_table[array[i]]) {
            hash_table[stk.top()] = array[i];
            stk.pop();
        }

        stk.push(i);
    }

    while(!stk.empty()) {
        hash_table[stk.top()] = -1;
        stk.pop();
    }

    for (int i = 0; i < n; ++i)
        cout << "\n" << array[i] << " -> " << hash_table[array[i]];
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]), array[n] = {0};
    for (int i = 0; i < n; ++i)
        cin >> array[i];
    next(array, n);
    return 0;
}