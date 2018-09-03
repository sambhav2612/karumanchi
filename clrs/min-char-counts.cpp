#include <bits/stdc++.h>
using namespace std;

int convert(string s, int k) {
    priority_queue<int> pq;
    int result = 0, hash_table[26] = {0};

    if (k >= s.size())
        return 0;

    for (int i = 0; i < s.size(); ++i)
        hash_table[s[i] - 'a']++;

    for (int i = 0; i < 26; ++i)
        pq.push(hash_table[i]);

    while (k--) {
        int temp = pq.top();
        pq.pop();
        temp -= 1;
        pq.push(temp);
    }

    while (!pq.empty()) {
        int temp = pq.top();
        result += pow(temp, 2);
    }

    return result;
}

int main(int argc, char *argv[]) {
    int k = atoi(argv[1]);
    string s = "";

    getline(cin, s);

    cout << "\n" << convert(s, k);

    return 0;
}