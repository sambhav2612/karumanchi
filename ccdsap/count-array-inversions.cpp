#include <bits/stdc++.h>

int calc(int *array, int n) {
    std::set<int> mySet;
    mySet.insert(array[0]);
    std::set<int>::iterator mySet_it;

    int inversion_count = 0;

    for (int i = 1; i < n; ++i) {
        mySet.insert(array[i]);
        mySet_it = mySet.upper_bound(array[i]);
        inversion_count += std::distance(mySet_it, mySet.end());
    }

    return inversion_count;
}

int main() {
    int n = 0;
    std::cin >> n;
    int array[n] = {0};
    for (int i = 0; i < n; ++i)
        std::cin >> array[i];
    std::cout << "\n" << calc(array, n);
    return 0;
}