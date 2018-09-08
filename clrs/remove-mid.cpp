#include <bits/stdc++.h>
using namespace std;

stack<int> temp;

void calc(int n, int index = 0) {
    if (temp.empty() || index == n)
        return;

    int x = temp.top();
    temp.pop();

    calc(n, index+1);

    if (index != n/2)
        temp.push(x);
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]), array[n] = {0};
    for (int i = 0; i < n; ++i)
        cin >> array[i];
    for (int i = n-1; i >= 0; --i)
        temp.push(array[i]);
    calc(n);
    cout << "\n";
    while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
    }
    return 0;
}