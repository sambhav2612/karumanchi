#include <bits/stdc++.h>
using namespace std;

int stocks[1000];

void span(int *array, int n) {
    stack<int> stk;
    stk.push(0);
    stocks[0] = 1;

    for (int i = 1; i < n; ++i) {
        stocks[i] = 1;

        while(!stk.empty() && (array[stk.top()] <= array[i]))
            stk.pop();

        // check if stack become empty after comparing with array[i], if it does all elements before array[i] 
        // were smaller than it, therefore the number of elements smaller than it becomes i + 1. Else, it is
        // i - element at top of the stack
        stocks[i] = (stk.empty() ? (i + 1) : (i - stk.top()));
       
        stk.push(i); 
    }
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]), array[n] = {0};
    for (int i = 0; i < n; ++i)
        cin >> array[i];
    span(array, n);
    for (int i = 0; i < n; ++i)
        cout << "\n" << array[i] << " -> " << stocks[i];
    return 0;
}