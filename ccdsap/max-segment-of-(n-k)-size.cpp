#include <bits/stdc++.h>

std::string calc(std::string str, int k) {
    int seg_len = str.length() - k, res = 0;
    for (int i = 0; i < seg_len; ++i)
        res = res * 10 + (str[i] - '0');

    int rem_sgements = pow(10, seg_len-1), current = res;
    for (int i = 1; i <= seg_len; ++i) {
        current = current - (str[i-1] - '0') * rem_sgements;    // remove first digit
        current = current*10 + (str[i + seg_len - 1] - '0');    // get next digit
        res = std::max(res, current);
    }
    return std::to_string(res);
}

int main() {
    std::string str = "";
    int k = 0;
    getline(std::cin, str);
    std::cin >> k;
    std::cout << "\n" << calc(str, k);
    return 0;
}