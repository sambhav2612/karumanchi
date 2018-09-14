#include <bits/stdc++.h>
using namespace std;

bool check(string s) {
    if (s.length() == 0 || s.length() == 1)
        return false;
    if (s.length() == 2)
        return (((s[0] - '0') * 10 + (s[1] - '0')) % 11 == 0);
    int sum_odd = 0, sum_even = 0;
    for (int i = 0; i < s.length(); ++i)
        if (i % 2 == 0)
            sum_even += (s[i] = '0');
        else
            sum_odd += (s[i] = '0');

    return (abs(sum_odd - sum_even) % 11 == 0);
}

int main() {
    string s = "";
    getline(cin, s);
    check(s) ? cout << "\nNo" : cout << "\nYes";
    return 0;
}