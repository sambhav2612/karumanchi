#include <bits/stdc++.h>
using namespace std;

int dp[1000];

void next(int *array, int n) {
    stack<int> stk;
    stk.push(0);

    for (int i = 1; i < n; ++i) {
        while (!stk.empty()) {
            int cur = stk.top();
            if (array[cur] < array[i]) {
                dp[cur] = i;
                stk.pop(); 
            } else
                break;
        }
        stk.push(i);
    }
    
    while(!stk.empty()) {
        int cur = stk.top();
        dp[cur] = -1;
        stk.pop();
    }
}

int answer(int array[], int index) {
    int pos = dp[index]; 
    if (pos == -1)
        return -1;
    else
        return array[pos];
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]), array[n] = {0};
    for (int i = 0; i < n; ++i)
        cin >> array[i];
    next(array, n);
    cout << "\n" << answer(array, 3);
    cout << "\n" << answer(array, 6);
    cout << "\n" << answer(array, 1);
    return 0;
}