#include <bits/stdc++.h>
using namespace std;

#define no_of_chars 256

string print(string str) {
    string fraand = "";
    int count[no_of_chars] = {0}, index[no_of_chars] = {str.length()};

    for(int i = 0; i < str.length(); ++i) {
        char x = str[i];
        count[x]++;

        if (count[x] == 1 && x !=' ')
            index[x] = i;
        if (count[x] > 1)
            index[x] = str.length();
    }

    sort(index, index + no_of_chars);

    for (int i = 0; i < str.length() && index[i] != str.length(); ++i)
        fraand.push_back(str[index[i]]);

    return fraand;
}

int main() {
    string str = "";
    getline(cin, str);
    cout << "\n" << print(str);
    return 0;
}