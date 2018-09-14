#include<bits/stdc++.h>
using namespace std;

#define limit 26

string count (string a[]) {
    string fraand = "";

    bool hash_a[limit] = {true};

    for (int i = 0; i < sizeof(a)/sizeof(a[0]); ++i) {

        bool hash_b[limit] = {false};
        
        for (int j = 0; a[i][j]; ++j)
            if (hash_a[a[i][j] - 'a'])
                hash_b[a[i][j] - 'a'] = true;

        memcpy(hash_a, hash_b, limit);
    }

    for (int i = 0; i < limit; ++i)
        if (hash_a[i])
            fraand.push_back(i + 'a');

    if (fraand.size() > 0)
        return fraand;
    else
        return "NULL";
}

int main(int argc, char *argv[]) {
    string a[100] = {""};
    int i = 0;
    while (i < 4)
        getline(cin, a[i++]);
    cout << "\n" << count(a);
    return 0;
}