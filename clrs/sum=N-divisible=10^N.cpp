#include <bits/stdc++.h>
using namespace std;

string smallest(int n) {
    string s;

    if (n == 0)
        s.append("0");
    if (n % 9 != 0)
        s.append(to_string(n % 9));
    for (int i = 0; i < (n / 9); ++i)
        s.append("9");
    for (int i = 0; i < n; ++i)
        s.append("0");

    return s;
}

int main() {
    int n = 0;
    cin >> n;

    cout << "\n" << smallest(n);

    return 0;
}