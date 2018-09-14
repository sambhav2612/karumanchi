#include <bits/stdc++.h>
using namespace std;

int max(vector<int> array) {
    int maxDif = array.at(1) - array.at(0);         // -1;
    int min = array.at(0);                          // array.at(n-1)

    for (int i = 1; i < array.size(); ++i) {
        if (array.at(i) - min > maxDif)             
            maxDif = array.at(i) - min;
        if (min > array.at(i))
            min = array.at(i);
    }

    return maxDif;
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]), n2 = n, val = 0;
    vector<int> array;

    while (n2-- > 0 && cin >> val)
        array.push_back(val);
    
    cout << "\n" << max(array);

    return 0;
} 