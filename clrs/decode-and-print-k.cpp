#include <bits/stdc++.h>
using namespace std;

char decode(string str, string k) {
    string expanded = "";
    string temp = "";
    int freq = 0;

    for (int i = 0; str[i] != '\0';) {
        temp = "";
        freq = 0;
        
        while (str[i] >= 'a' && str[i] <= 'z') 
            temp.push_back(str[i++]);           // get substring
        while (str[i] >= '0' && str[i] <= '9')
            freq = freq*10 + (str[i++] - '0');    // get frequency
        while (freq--)
            expanded.append(temp);
    }

    if (freq == 0)
        expanded.append(temp);

    return expanded[stoi(k)-1];
}

int main() {
    string str = "", k = "";
    
    getline(cin, str);
    getline(cin, k);

    cout << "\n" << decode(str, k);

    return 0;
}