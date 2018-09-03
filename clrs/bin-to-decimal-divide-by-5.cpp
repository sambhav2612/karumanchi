#include <bits/stdc++.h>
using namespace std;

int convert_to_base4(string s) {
    if (s.compare("00") == 0)
        return 0;
    if (s.compare("01") == 0)
        return 1;
    if (s.compare("10") == 0)
        return 2;
    return 0;
        
}

int check(string s) {
    if (s.length() % 2 != 1)
        s = '0' + s;

    int is_odd = 1, odd_sum = 0, even_sum = 0;

    for (int i = 0; i < s.length(); ++i) {
        if (is_odd)
            odd_sum += convert_to_base4(s.substr(i, 2));
        else
            even_sum += convert_to_base4(s.substr(i, 2));

        is_odd ^= 1;
    }

    return (abs(odd_sum - even_sum) % 5 == 0);
}

int main() {
    string s = "";
    getline(cin, s);
    check(s) ? cout << "\nNo" : cout << "\nYes";
    return 0;
}