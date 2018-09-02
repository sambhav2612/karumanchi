#include <bits/stdc++.h>
using namespace std;

void max(vector<int> array) {
    set<int> mySet;
    vector<int> countSmaller;

    for (int i = array.size()-1; i >= 0; --i) {
        mySet.insert(array.at(i));
        auto it = mySet.lower_bound(array.at(i));
        countSmaller.at(i) = distance(mySet.begin(), it);
    }

    for (int i = 0; i < array.size(); ++i)
        cout << countSmaller.at(i) << " ";
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]), n2 = n, val = 0;
    vector<int> array;

    while (n2-- > 0 && cin >> val)
        array.push_back(val);

    cout << "\n";
    max(array);
    
    return 0;
}