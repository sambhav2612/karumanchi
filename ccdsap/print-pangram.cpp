// converting non-pangram string to pangram

#include <bits/stdc++.h>
using namespace std;

string check(string s) {
    int hash_table[26] = {0};
    string n;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] >= 'A' && s[i] <= 'Z')
            hash_table[s[i]-'A']++;
        if (s[i] >= 'a' && s[i] <= 'z')
            hash_table[s[i]-'a']++;
    }

    int count = 0;
    for (int i = 0; i < 26; ++i)
        if (hash_table[i] == 0) {
            char x = i + 'a';
            n.append(1, x); // append all non-apprearing elements
        }

    return n;
}

int main(int argc, char *argv[]) {
    string s = argv[1];
    cout << "\n" << check(s);
    return 0;
}