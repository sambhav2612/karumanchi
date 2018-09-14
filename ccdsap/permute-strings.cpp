#include <bits/stdc++.h>
using namespace std;

void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *str, int low, int high) {
    if (low == high)
        cout << str << "\n";
    else {
        for (int i = low; i <= high; ++i) {
            swap((str+low), (str+i));
            permute(str, low+1, high);
            swap((str+low), (str+i));
        }
    }
}

int main() {
    string str = "";
    getline(cin, str);
    cout << "\n";
    char *cstr = new char[str.length() + 1];
    strcpy(cstr, str.c_str());
    permute(cstr, 0, str.length()-1);
    return 0;
}