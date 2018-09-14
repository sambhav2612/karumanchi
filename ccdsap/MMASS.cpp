#include <bits/stdc++.h>

std::vector<int> result;

int getMass(char ch) {
    switch(ch) {
        case 'H' : return 1;
        case 'C' : return 12;
        case 'O' : return 16;
    }
}

void calc(std::string str) {
    std::stack<int> stk;
    int v;
    for (int i = 0; str[i]; ++i) {
        if (str[i] == '(')
            stk.push(-1);
        if (isalpha(str[i]))
            stk.push(getMass(str[i]));
        if (isdigit(str[i])) {
            int ele = stk.top();
            stk.pop();
            stk.push((str[i] - '0') * ele);
        }
        if (str[i] == ')') {
            v = 0;
            while (!stk.empty() && stk.top() != -1) {
                 v += stk.top();
                 stk.pop();
            }
            stk.pop();  // pop -1
            stk.push(v);
        }
    }
    v = 0;
    while (!stk.empty()) {
        v += stk.top();
        stk.pop();
    }
    result.push_back(v);
}

int main() {
    int t = 0;
    std::cin >> t;
    int i = 0, t2 = t;
    while (t) {
        std::string str;
        getline(std::cin, str);
        calc(str);
        t--;
    }
    while (i++ < t2)
        std::cout << "\n" << result[i];
    return 0;
}