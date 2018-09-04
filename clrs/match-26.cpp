#include <bits/stdc++.h>
using namespace std;

int print(string str) {
    int result = 0;
    
    for (int i = 0; i < str.length(); ++i)
        if ((i == str[i]-'a') || (i == str[i]-'A'))
            result++;

    return result;
}

int main() {
    string str = "";
    getline(cin, str);
    cout << "\n" << print(str);
    return 0;
}