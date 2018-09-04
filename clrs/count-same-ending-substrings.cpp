#include <bits/stdc++.h>
using namespace std;

int print(string str) {
    int result = 0;
    
    for (int i = 0; i < str.length(); ++i)
        for (int j = i; j < str.length(); ++j)
            if (str[i] == str[j]) {
                result++;
                cout << str.substr(i, j) << "\n";
            }

    return result;
}

int main() {
    string str = "";
    getline(cin, str);
    cout << "\n" << print(str);
    return 0;
}