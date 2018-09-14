// working

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]), n2 = n, val = 0;
    vector<int> array;

    while (n2-- > 0 && cin >> val)
        array.push_back(val);

    int first = 0, second = 0, third = 0;

    for (int i = 0; i < n; ++i) {
        if (array.at(i) > first) {
            third = second;
            second = first;
            first = array.at(i);
        }
        else if (array.at(i) > second) {
            third = second;
            second = array.at(i);
        }
        else if (array.at(i) > third) {
            third = array.at(i);
        }
    }

    cout << endl << first << second << third;

    return 0;
}