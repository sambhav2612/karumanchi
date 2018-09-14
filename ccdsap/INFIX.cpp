#include <bits/stdc++.h>

std::vector<long> result;

long abcd(char ch) {
    switch(ch) {
        case 'a' : return 10;
        case 'b' : return 20;
        case 'c' : return 15;
        case 'd' : return 25;
    }
}

long op(char ch, int a, int b) {
    switch(ch) {
        case '+' : return (b + a);
        case '-' : return (b - a);
        case '/' : return (b / a);
        case '*' : return (b * a);
        case '%' : return (b % a);
        case '^' : return (b ^ a);
    }
}

void calc(std::string str) {
    std::stack<long> stk;
    for (int i = 0; str[i]; ++i) {
        if (isalpha(str[i]))
            stk.push(abcd(str[i]));     // push value corresponding to the character
        if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*' || str[i] == '%' || str[i] == '^') {
            int val = stk.top();
            stk.pop();
            int val2 = stk.top(); 
            stk.pop();
            stk.push(op(str[i], val, val2));    // push back the result
        }
    }
    if (stk.size() == 1) {
        result.push_back(stk.top());
        stk.pop();
    } else
        return;
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