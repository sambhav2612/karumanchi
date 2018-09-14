#include <bits/stdc++.h>
using namespace std;

int max(vector<int> array, int x, int y) {
    int min = INT_MAX, prev = 0, i;

    for (i = 0; i < array.size(); ++i)
        if (array.at(i) == x || array.at(i) == y) {
            prev = i;
            break;
        }
    
    for (; i < array.size(); ++i) {
        if (array.at(i) == x || array.at(i) == y)
            if (array.at(prev) != array.at(i) && (i-prev) < min) {
                min = i-prev;
                prev = i;
            }
            else 
                prev = i;
    }

    return min;
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]), x = atoi(argv[2]), y = atoi(argv[3]), n2 = n, val = 0;
    vector<int> array;

    while (n2-- > 0 && cin >> val)
        array.push_back(val);
    
    cout << "\n" << max(array, x, y);

    return 0;
} 