#include <bits/stdc++.h>
using namespace std;

int ret_pairs(int n) {
    vector<int> array;
    int n2 = n, val = 0;
    long long l = 0;

    while (n2-- > 0 && cin >> val)
        array.push_back(val);

    for (int i = 0; i < n; ++i)
        if (array.at(i) == 1)
            l++;

    return ((l)*(l+1))/2;
}

int main(int argc, char *argv[]) {
    int t = atoi(argv[1]), t2 = t, n = 0, pairs[t] = {0}, i = 0;
    
    while (t-- > 0) {
        cin >> n;
        pairs[i++] = ret_pairs(n);
    }

    i = 0;
    t = t2;

    while(i < t)
        cout << pairs[i++] << "\n";

    return 0;
}