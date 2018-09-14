#include<bits/stdc++.h>
using namespace std;

#define limit 26

int min (int a, int b) {
    return ((a < b) ? a : b);
}

string count (string a, string b) {
    string fraand = "";

    int hash_a[limit] = {0}, hash_b[limit] = {0};

    for (int i = 0; i < a.length(); ++i)
        hash_a[a[i]-'a']++;
    for (int i = 0; i < b.length(); ++i)
        hash_b[b[i]-'a']++;

    for (int i = 0; i < limit; ++i)
        for (int j = 0; j < min(hash_a[i], hash_b[i]); ++j)
            fraand.push_back(i + 'a');

    return fraand;
}

int main(int argc, char *argv[]) {
    string a = "", b = "";
    getline(cin, a);
    getline(cin, b);
    cout << "\n" << count(a, b);
    return 0;
}