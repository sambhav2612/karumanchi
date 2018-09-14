#include <bits/stdc++.h>
using namespace std;

bool isVowel(char ch) {
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int count(string str, int n) {
    if (n == 1)
        return isVowel(str[0]);
    return (count(str, n-1) + isVowel(str[n-1]));
}

int main() {
    string str = "";
    getline(cin, str);
    cout << "\n" << count(str, str.length());
    return 0;
}