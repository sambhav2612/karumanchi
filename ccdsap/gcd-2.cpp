#include <bits/stdc++.h>
using namespace std;

int calc(int a, int b) {
    if (a == 0)
        return b;
    return calc(b % a, a);
}

int main(int argc, char *argv[]) {
    int a = atoi(argv[1]), b = atoi(argv[2]);
    cout << "\n" << calc(a, b);
    return 0;
}