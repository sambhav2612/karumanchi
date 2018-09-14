#include <bits/stdc++.h>
using namespace std;

int check(string s) {
    int hash_table[26] = {0};

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] >= 'A' && s[i] <= 'Z')
            hash_table[s[i]-'A']++;
        if (s[i] >= 'a' && s[i] <= 'z')
            hash_table[s[i]-'a']++;
    }

    int count = 0;
    for (int i = 0; i < 26; ++i)
        if (hash_table[i] > 0)
            ++count;

    return (count == 26);
}

int main(int argc, char *argv[]) {
    string s;
    getline(cin, s);

    cout << "\n" << check(s);
    return 0;
}