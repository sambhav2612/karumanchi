#include <bits/stdc++.h>
using namespace std;

int calc(string str) {
    int cur_max = 0, max = 0;
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == '(') {
            ++cur_max;
            if (cur_max > max)
                max = cur_max; 
        } 
        if (str[i] == ')') {
            if (cur_max > 0)
                --cur_max;
            else
                return -1;
        }
    }

    return (cur_max != 0) ? -1 : max;
}

int main() {
    string str = "";
    getline(cin, str);
    cout << "\n" << calc(str);
    return 0;
}