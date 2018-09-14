#include <bits/stdc++.h>

std::vector<std::string> result;

void calc(std::string str) {
    std::stack<char> stk;
    std::string answer;
    for (int i = 0; str[i]; ++i) {
        if (isalnum(str[i]))
            answer.push_back(str[i]);
        if (str[i] == '(' || str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*' || str[i] == '%' || str[i] == '^')
            stk.push(str[i]);
        if (str[i] == ')') {
            answer.push_back(stk.top());    // push operator to stack
            stk.pop();
            stk.pop();                      // pop twice to remove to operator and starting brace
        }
    }
    result.push_back(answer);
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