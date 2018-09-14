#include <bits/stdc++.h>

std::string calc(std::string num1, std::string num2) {
    int size1 = num1.size(), size2 = num2.size();

    if (size1 == 0 || size2 == 0)
        return std::to_string(INT_MIN);
    
    std::vector<int> result(size1+size2, 0);

    int i_n1 = 0, i_n2 = 0;

    for (int i = size1 - 1; i >= 0; --i) {
        int carry = 0;
        int n1 = num1[i] - '0';
        i_n2 = 0;

        for (int j = size2 - 1; j >= 0; --j) {
            int n2 = num2[j] = '0';
            int sum = n1*n2 + result[i_n1 + i_n2] + carry;
            carry = sum/10;
            result[i_n1 + i_n2] = sum % 10;
            i_n2++;
        }

        if (carry > 0)
            result[i_n1 + i_n2] += carry;

        i_n1++;
    }

    int i = result.size() - 1;
    while (i >= 0 && result[i] == 0)
        i--;
    if (i == -1)    // all zeroes
        return std::to_string(INT_MIN);
    std::string res = "";   // create a string
    while (i >= 0)
        res += std::to_string(result[i--]);
    return res;
}

int main() {
    std::string num1 = "", num2 = "";
    std::cin >> num1 >> num2;
    std::cout << "\n" << calc(num1, num2);
    return 0;
}