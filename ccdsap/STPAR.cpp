#include <bits/stdc++.h>

std::vector<std::string> result;

void calc(int *array, int size) {
    std::sort(array, array+size);
    const int diff = 1;
    int i;
    for (i = 0; i < size; ++i) {
        if (std::abs(array[i]-array[i+1] == diff))  // if absolute difference is 1, continue else break
            continue;   
        else
            break;
    }

    result.push_back((i == size) ? "yes" : "no");   // push yes if all are in order else push no   
}

int main() {
    int t, i = 0;
    while (std::cin >> t && t != 0) {
        ++i;
        int n = 0;
        std::cin >> n;
        int array[n] = {0};
        for (int i = 0; i < n; ++i)
            std::cin >> array[i];
        calc(array, n);
    }

    int j = 0;
    while (j++ < i) 
        std::cout << "\n" << result[i];
    return 0;
}