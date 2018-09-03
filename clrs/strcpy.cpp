#include <bits/stdc++.h>
using namespace std;

void strcpy(string s1, string s2, int index = 0) {
    s2[index] = s1[index];
    if (s1[index] == '\0')
        return;
    return strcpy(s1, s2, index+1);
}

int main(int argc, char *argv[]) {
    string s1 , s2;
    getline(cin, s1);
    getline(cin, s2);

    strcpy(s1, s2);

    cout << s2;

    return 0;
}