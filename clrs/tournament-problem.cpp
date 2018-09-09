#include <bits/stdc++.h>
using namespace std;

struct str {
    public: 
        int max;
        int min;
};

struct str getMaxMin(int *array, int low, int high) {
    struct str minmax, mml, mmr;
    if (low == high)    {   // only one element
        minmax.max = array[low];
        minmax.min = array[low];
        return minmax;
    }

    if (low == high - 1) {
        if (array[low] < array[high]) {
            minmax.max = array[high];
            minmax.min = array[low];
        } else {
            minmax.max = array[low];
            minmax.min = array[high];
        }
        return minmax;
    }

    int mid = (low + high) / 2;
    mml = getMaxMin(array, 0, mid);
    mmr = getMaxMin(array, mid+1, high);

    if (mml.max > mmr.max) {
        minmax.max = mml.max;
    } else 
        minmax.max = mmr.max;
        
    if (mml.min < mmr.min) {
        minmax.min = mml.min;
    } else 
        minmax.min = mmr.min;

    return minmax;
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]), array[n] = {0};
    for (int i = 0; i < n; ++i)
        cin >> array[i];
    struct str minmax = getMaxMin(array, 0, n-1);
    cout << "\nMaximum - " << minmax.max << "\nMinimum - " << minmax.min;
    return 0;
}