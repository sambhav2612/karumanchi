#include <bits/stdc++.h>
using namespace std;

string min_max(string num1, string num2) {
    // num1 length should be more than num2
    if (num1.length() < num2.length())
        swap(num1, num2);
    
    int diff = num1.length() - num2.length(), carry = 0;
    string str;

    for (int i = num2.length()-1; i >= 0; --i) {
        int sub = (num1[i + diff] - '0') - (num2[i] - '0') - carry;
        if (sub < 0) {
            carry = 1;
            sub += 10;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }

    for (int i = diff-1; i >= 0; --i) {
        if (num1[i] == '0' || carry) {
            str.push_back('9');
            continue;
        }
        int sub = (num1[i] - '0') - carry;
        if (i > 0 || sub > 0)
            str.push_back(sub + '0');
        carry = 0;
    }

    reverse(str.begin(), str.end());

    return str;
}

int main(int argc, char *argv[]) {
    string num1 = "", num2 = "";
    
    getline(cin, num1);
    getline(cin, num2);

    cout << "\n" << min_max(num1, num2);

    return 0;
}