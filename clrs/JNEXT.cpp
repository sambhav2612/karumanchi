// permutation not next bigger element, so use any element but replace with it still keepign it the smallest biggest element

#include <bits/stdc++.h>

std::vector<unsigned long long> returns;

void calc(std::vector<int> array) {
    unsigned long long number = 0;
    for (int i = array.size() - 1, j = 0; i >= 0; --i, ++j)
        number += array[i] * pow(10, j);    // calculate the number
    unsigned long long max = INT_MAX, current_max = 0;
    for (int i = 0; i < array.size(); ++i) {
        current_max = number + array[i];
        if (max > current_max)
            max = current_max;
    }
    returns.push_back(max);
}

void calc2(std::vector<int> array) {
    int numbers[array.size()] = {0};
    for (int i = 0; i < array.size(); ++i)
        numbers[i] = array[i];
    std::next_permutation(numbers, numbers + array.size());
    unsigned long long number = 0;
    for (int i = array.size() - 1, j = 0; i >= 0; --i, ++j)
        number += numbers[i] * pow(10, j);    // calculate the number
    returns.push_back(number);
}

int main(int argc, char *argv[]) {
    int t = 0;
    std::cin >> t;

    int t2 = t, i = 0;

    while (t--) {
        int n = 0, val = 0;
        std::cin >> n;
        std::vector<int> array;

        while(n-- > 0 && std::cin >> val)
            array.push_back(val);

        calc2(array);
    }

    while (i++ < t2)
        std::cout << "\n" << returns[i];

    return 0;
}