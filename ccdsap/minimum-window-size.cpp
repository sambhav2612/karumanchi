#include <bits/stdc++.h>
using namespace std;

#define chars 256

string count(string str, string pat) {
    int hash_str[chars] = {0}, hash_pat[chars] = {0};
    int start = 0, count = 0, start_index = -1, min_index = INT_MAX;

    if (str.length() < pat.length())
        return "";

    for (int i = 0; i < pat.length(); ++i)
        hash_pat[pat[i]]++;

    for (int i = 0; i < str.length(); ++i) {
        hash_str[str[i]]++;

        if (hash_pat[str[i]] != 0 && hash_str[str[i]] <= hash_pat[str[i]])
            count++;

        // if a window is found
        if (count == pat.length()) {
            while(hash_str[str[start]] > hash_pat[str[start]] || hash_pat[str[start]] == 0) {
                if (hash_str[str[start]] >= hash_pat[str[start]])
                    hash_str[str[start]]--;
                start++;
            }
        }

        int window = i - start + 1;

        if (min_index > window) {
            min_index = window;
            start_index = start; 
        }
    }

    if (start_index == -1)
        return "";

    return str.substr(start_index, min_index);
}

int main() {
    string str = "", pat = "";
    
    getline(cin, str);
    getline(cin, pat);

    cout << "\n" << count(str, pat);

    return 0;
}