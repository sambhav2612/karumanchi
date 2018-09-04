#include<bits/stdc++.h>
using namespace std;

void my_substr_1(string str, int low, int high) {
    if (low <= high) {
        cout << str[low];
        my_substr_1(str, low+1, high);
    }
}

void my_substr_2(string str, int low, int high) {
    printf("%.*s", (high-low+1), str);
}

int move(string str) {
    int n = str.length();

    for (int i = 0; i < n; ++i)             // defines starting index of substring
        for (int j = 1; j <= n - i; ++j)    // defines length of substring
            cout << str.substr(i, j) << "\n";

    return (n * ((n-1)/2));  
}

int main(int argc, char *argv[]) {
    string str = "";
    getline(cin, str);
    cout << "\n" << move(str);
    return 0;
}