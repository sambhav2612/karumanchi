#include <bits/stdc++.h>
using namespace std;

bool check(string s) {
    int len = s.length();

    int rem = 0, num;

    for (int i = 0; i < len; ++i) {
        num = rem * 10 + (s[i] - '0');
        if (num < 11)
            continue;
        else
            rem = num % 11;
    }

    return rem;
}

int main() {
    string s = "";
    getline(cin, s);
    cout << "\n" << check(s);
    return 0;
}