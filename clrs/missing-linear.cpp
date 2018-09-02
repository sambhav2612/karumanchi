#include <bits/stdc++.h>
using namespace std;

int missing(vector<int> array, int n) {
    if (array.at(0) != 0)
        return 0;
    for (int i = 0; i < n; ++i)
        if (array.at(i+1)-array.at(i) > 1)
            return array.at(i)+1;
    return -1;
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]), n2 = n, val = 0;
    vector<int> array;

    while (n2-- > 0 && cin >> val)
        array.push_back(val);

    cout << endl << missing(array, n);
    
    return 0;
}