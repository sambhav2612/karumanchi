#include <bits/stdc++.h>
using namespace std;

int max_element(int a, int b) {
    return (a >= b ? a : b);  
}

int extract_max(string s) {
    int max = 0, num = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] >= '0' && s[i] <= '9')
            num = num * 10 + (s[i] - '0');
        else {
            max = max_element(max, num);
            num = 0;
        }
    }

    return max_element(max, num);
}

int main() {
    string s = "";
    getline(cin, s);
    cout << "\n" << extract_max(s);
    return 0;
}