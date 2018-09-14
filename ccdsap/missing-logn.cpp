#include <bits/stdc++.h>
using namespace std;

int missing(vector<int> array, int low, int n) {
    if (array.at(0) != low)
        return low;
    
    int mid = (low+n)/2;
    
    if (array.at(mid) > mid)
        return missing(array, low, mid);
    else   
        return missing(array, mid+1, n);
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]), n2 = n, val = 0;
    vector<int> array;

    while (n2-- > 0 && cin >> val)
        array.push_back(val);

    cout << endl << missing(array, 0, n);
    
    return 0;
}