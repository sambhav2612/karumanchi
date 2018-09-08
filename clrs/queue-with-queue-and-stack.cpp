#include <bits/stdc++.h>
using namespace std;

queue<int> temp;

bool calc(int n) {
    stack<int> stk;
    int exp = 1;

    while(!temp.empty()) {
        int fnt = temp.front();
        temp.pop();

        if (fnt == exp) 
            exp++;
        else {
            if (stk.empty())
                stk.push(fnt);

            if (!stk.empty() && stk.top() < fnt)    // current element is bigger than stack element
                return false;

            else
                stk.push(fnt);
        }
    
        while (!stk.empty() && stk.top() == exp) {
            stk.pop();
            exp++;
        }
    }

    return (exp - 1 == n && stk.empty());
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]), array[n] = {0};
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
        temp.push(array[i]);
    }
    cout << "\n";
    calc(n) ? cout << "YES" : cout << "NO";
    return 0;
}