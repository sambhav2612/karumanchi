#include <bits/stdc++.h>
using namespace std;

string convert(string newCharSet, string inputStr) {
    int hash_table[26] = {0};

    for (int i = 0; i < 27; ++i)
        hash_table[inputStr[i] - 'a'] = i + 'a';

    for (int i = 0; i < inputStr.length(); ++i)
        inputStr[i] = hash_table[inputStr[i] - 'a'];

    return inputStr;
}

int main(int argc, char *argv[]) {
    string newCharSet, inputStr;

    getline(cin, newCharSet);
    getline(cin, inputStr);

    cout << "\n" << convert(newCharSet, inputStr);

    return 0;
}