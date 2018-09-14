// spoj problem - games
#include <bits/stdc++.h>
using namespace std;

vector<int> solutions;

long gcd(long a, long b) {
    return (a == 0) ? b : gcd(b % a, a);
}

int check(string n) {
    int flag = 0, count = 0;
    for (int i = n.size()-1; i >= 0; i--)
        if (n[i] == '.') {
            flag = 1;
            break;
        } else 
            count++;

    long fraction = 1, number = 1;

    if (flag) { // floating point number
        fraction = pow(10, count);
        number = stof(n) * fraction;
    } else        // integer
        number = stoi(n) * fraction; 

    solutions.push_back(fraction / gcd(number, fraction));
}

int main(int argc, char *argv[]) {
    int t = 0;

    cin >> t;

    while (t--) {
        string n;
        cin >> n;

        check(n);
    }

    for (int i = 0; i < solutions.size(); ++i)
        cout << solutions[i] << "\n";
    
    return 0;
}