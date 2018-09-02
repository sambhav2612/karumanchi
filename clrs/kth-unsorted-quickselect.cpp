// NOT working

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> array, int low, int high) {
    int x = array.at(high-1), i = 0;
    for (int j = 1; j < high; ++j)
        if (array.at(j) <= x) {
            i++;
            swap(array.at(i), array.at(j));
        }
    swap(array.at(i), array.at(high-1));
    return i;
}

int kth_smallest(vector<int> array, int low, int high, int k) {
    if (k > 0 && k <= high-low+1) {    // k is within bounds
        int pivot = partition(array, low, high);
        if (pivot-1 == k-1) // pivot is equal to k
            return array.at(pivot);
        if (pivot-1 < k-1)  // pivot is smaller than k
            return kth_smallest(array, pivot+1, high, k-pivot+low-1);
        return kth_smallest(array, low, pivot-1, k);    // pivot is on left of k
    }
    return INT_MAX;
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]), k = atoi(argv[2]), n2 = n, val = 0;
    vector<int> array;

    while (n2-- > 0 && cin >> val)
        array.push_back(val);
    
    cout << endl << kth_smallest(array, 0, n, k);
    return 0;
}