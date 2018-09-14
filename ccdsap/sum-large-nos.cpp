#include <bits/stdc++.h>
using namespace std;

string min_max(string num1, string num2) {
    if (num1.length() > num2.length())
        swap(num1, num2);
    
    int diff = num2.length() - num1.length(), carry = 0;
    string str;

    for (int i = num1.length()-1; i >= 0; --i) {
        int sum = (num1[i] - '0') + (num2[i + diff] - '0') + carry;
        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    for (int i = num2.length()-num1.length()-1; i >= 0; --i) {
        int sum = (num2[i] - '0') + carry;
        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    if (carry)
        str.push_back(carry + '0');

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