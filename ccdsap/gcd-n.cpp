#include <bits/stdc++.h>
using namespace std;

int calc_gcd(int a, int b) {
    if (a == 0)
        return b;
    return calc_gcd(b % a, a);
}

int calc(int array[], int n) {
    int res = array[0];
    
    for (int i = 1; i < n; ++i)
        res = calc_gcd(array[i], res);

    return res;
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]), array[n] = {0};
    for(int i =0; i < n; ++i)
        cin >> array[i];
    cout << "\n" << calc(array, n);
    return 0;
}