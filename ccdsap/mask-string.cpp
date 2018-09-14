#include <bits/stdc++.h>
using namespace std;

#define no_of_chars 256

string after_mask(string str, string mask) {
    int count[no_of_chars] = {0};
    
    for (int i = 0; mask[i] != '\0'; ++i)
        count[mask[i]]++;

    int ip = 0, res = 0;

    while (str[ip] != '\0') {
        if (count[str[ip]] == 0) {
            str[res] = str[ip];
            res++;
        }
        ip++;
    }

    while(str[res] != '\0')
        str[res++] = '\0';    // end the masked string

    return str;
}

int main() {
    string str = "", mask = "";
    getline(cin, str);
    getline(cin, mask);
    cout << "\n" << after_mask(str, mask);
    return 0;
}