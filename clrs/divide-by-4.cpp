#include <bits/stdc++.h>
using namespace std;

bool check(string s) {
    if (s.length() == 0)
        return false;
    if (s.length() == 1)
        return ((s[0] - '0')% 4 == 0);
    return (((s[s.length()-1] - '0') * 10 + (s[s.length()-2] - '0')) % 4 == 0);
}

int main() {
    string s = "";
    getline(cin, s);
    check(s) ? cout << "\nNo" : cout << "\nYes";
    return 0;
}