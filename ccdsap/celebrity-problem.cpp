#include <bits/stdc++.h>
using namespace std;

int *matrix[100];

bool knows(int a, int b) {
    return matrix[a][b];
}

int next(int n) {
    stack<int> stk;

    for (int i = 0; i < n; ++i)
        stk.push(i);

    int c = 0; 
    int a = stk.top();
    stk.pop();
    int b = stk.top();
    stk.pop();
    
    while(stk.size() > 1) {
        if (knows(a, b)) {
            a = stk.top();
            stk.pop();
        } else {
            b = stk.top();
            stk.pop();
        }
    }

    c = stk.top();
    stk.pop();

    if (knows(c, a)) 
        c = a;
    if (knows(c, b))
        c = b;

    for (int i = 0; i < n; ++i) 
        if(i != c && (knows(c, i) || knows(i, c)))
            return -1;

    return c; 
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]), *matrix[n] = {0};
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> matrix[i][j];
    cout << "\n" << next(n);
    return 0;
}