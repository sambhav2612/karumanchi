#include <bits/stdc++.h>
using namespace std;

bool check(string s) {

    int n = s.length();

    if (n == 0 && s[0] == '0')
        return true;

    if (n % 3 == 1)
        s = '0' + s;
    if (n % 3 == 2)
        s = "00" + s;

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int group = 0;
        group += (s[i++] - '0') * 100;
        group += (s[i++] - '0') * 10;
        group += (s[i] - '0');
        sum += group;
    } 

    if (sum > 1000) { // convert to 3 digits
        n = to_string(sum).length();
        sum = check(to_string(sum));
    }

    return (sum % 999 == 0);
}


int main() {
    string s = "";
    getline(cin, s);
    check(s) ? cout << "\nNo" : cout << "\nYes";
    return 0;
}