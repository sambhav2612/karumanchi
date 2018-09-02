#include <bits/stdc++.h>
using namespace std;

double median_x(vector<int> array) {
    if (array.size() <= 0)
        return INT_MIN;
    double median = 0;
    for (int i = 0; i < array.size(); ++i)
        median += array.at(i);

    return (median/array.size());
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]), n2 = n, val = 0;
    vector<int> array;

    while (n2-- > 0 && cin >> val) {
        array.push_back(val);
        cout << median_x(array) << " ";
    }
    
    return 0;
}