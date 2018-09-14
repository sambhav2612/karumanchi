// working

#include <bits/stdc++.h>
using namespace std;

int kth_smallest(vector<int> array, int size, int k) {
    set<int> elements;
    for (int i = 0; i < size; ++i)
        elements.insert(array.at(i));

    auto it = elements.begin(); // move this iterator till it reaches k

    for (int i = 0; i < k-1; ++i)
        ++it;

    return *it;
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]), k = atoi(argv[2]), val = 0, n2 = n;
    vector<int> array;

    while (n2-- > 0 && cin >> val)
        array.push_back(val);

    cout << endl << kth_smallest(array, n, k);
    return 0;
}