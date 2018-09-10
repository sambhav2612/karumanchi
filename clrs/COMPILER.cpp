#include <bits/stdc++.h>

std::vector<int> result;

void calc(std::string str) {
    std::stack<char> stk;
    int prefix_count = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))   // ignore for alphabet
            continue;
        if (str[i] == '<')                                                          // push for < 
            stk.push(str[i]);
        if (str[i] == '>' && !stk.empty()) {                                                        // pop for >
            stk.pop();
            prefix_count += 2;
        }
    }
    result.push_back(prefix_count);
}

int main() {
    int t = 0;
    std::cin >> t;
    int i = 0;
    while(i++ < t) {
        std::string str;
        getline(std::cin, str);
        calc(str);
    }
    i = 0;
    while(i++ < t)
        std::cout << "\n" << result[i];
    return 0;
}