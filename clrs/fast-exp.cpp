#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

long long calc(int base, int exp) {
    long long res = 1;

    while (exp > 0) {
        if (exp % 2 == 1)
            res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }

    return res % MOD;
}

int main(int argc, char *argv[]) {
    int base = atoi(argv[1]), exp = atoi(argv[2]);

    cout << "\n" << calc(base, exp);

    return 0;
}