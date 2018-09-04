#include <bits/stdc++.h>
using namespace std;

#define limit 26

int fact(int n) {
    if (n == 1)
        return 1;
    return n * fact(n-1);
}

int count(string str) {
    int hash_table[limit] = {0};

    for (int i = 0; i < str.length(); ++i)
        if (str[i] >= 'a')
            hash_table[str[i] - 'a']++;

    int factorial = 1;

    for (int i = 0; i < limit; ++i)
        factorial *= fact(hash_table[i]);

    return (fact(str.length())/factorial);
}

int main() {
    string str = "";
    getline(cin, str);
    cout << "\n" << count(str);
    return 0;
}