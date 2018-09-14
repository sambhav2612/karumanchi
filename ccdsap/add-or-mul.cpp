#include <bits/stdc++.h>
using namespace std;

long long int convert(string n) {
    long long int res = n[0] - '0';

    for (int i = 1; i < n.length(); ++i) {
        if (n[i] == '0' || n[i] == '1' || n[i-1] == '0' || n[i-1] == '1')
            res += (n[i] - '0');
        else
            res *= (n[i] - '0');
    }

    return res;
}

int main() {
    string n = "";
    getline(cin, n);
    cout << "\n" << convert(n);
    return 0;
}