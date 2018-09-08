#include <bits/stdc++.h>
using namespace std;

stack<char> stk;

string rev(string str) {
    string my = "";

    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] != ' ')
            stk.push(str[i]);
        else {
            while (!stk.empty()) {
                my.push_back(stk.top());
                stk.pop();
            }
            my.append(" ");
        }
    }

    while (!stk.empty()) {
        my.push_back(stk.top());
        stk.pop();
    }

    return my;
}

int main() {
    string str = ""; 
    getline(cin, str);
    cout << "\n" << rev(str);
    return 0;
}