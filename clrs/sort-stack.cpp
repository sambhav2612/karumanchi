#include <bits/stdc++.h>
using namespace std;

stack<int> temp;

void calc(int *array, int n) {
    stack<int> stk;

    for (int i = n-1; i >= 0; --i)
        stk.push(array[i]);

    while (!stk.empty()) {
        int val = stk.top();
        stk.pop();

        while (!temp.empty() && (temp.top() > val)) {
            stk.push(temp.top());
            temp.pop();
        }

        temp.push(val); 
    }
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]), array[n] = {0};
    for (int i = 0; i < n; ++i)
        cin >> array[i];
    calc(array, n);
    cout << "\n";
    while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
    }
    return 0;
}