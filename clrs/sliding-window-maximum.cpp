#include <bits/stdc++.h>
using namespace std;

vector<int> getMaxes(vector<int> array, int k) {
    int n = array.size();
    vector<int> maxes;
    
    for (int i = 0, j = k; i < j, j < n; ++i, ++j) {
        auto max = max_element(array.begin() + i, array.begin() + j);
        maxes.push_back(*max);
    }

    return maxes;
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]), k = atoi(argv[2]), n2= n, val = 0;
    vector<int> array;

    while (n2-- > 0 && cin >> val)
        array.push_back(val);

    vector<int> maxes = getMaxes(array, k);

    int i = 0;
    while(i++ < n)
        cout << array.at(i) << " ";
    return 0;
}