// uses modified binary search to find max element in a increasing then decreasing array
#include <bits/stdc++.h>
using namespace std;

int max(vector<int> array, int low, int high) {
    if (low == high)
        return array.at(low);

    if (low+1 == high)  // two elements
        return (array.at(low) > array.at(high) ? array.at(low) : array.at(high));

    int mid = (low+high)/2;
    if (array.at(mid) > array.at(mid-1) && array.at(mid) > array.at(mid+1))
        return array.at(mid);
    if (array.at(mid) > array.at(mid-1) && array.at(mid) < array.at(mid+1)) // right
        return max(array, mid+1, high);
    if (array.at(mid-1) > array.at(mid) && array.at(mid) > array.at(mid+1))  // left
        return max(array, low, mid-1);
    
    return -1;
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]), n2 = n, val = 0;
    vector<int> array;

    while (n2-- > 0 && cin >> val)
        array.push_back(val);

    cout << "\n" << max(array, 0, n-1);
    return 0;
}