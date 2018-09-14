#include <bits/stdc++.h>
using namespace std;

bool ret_laps(string array) {
    int mid1 = array.size()/2, mid2 = (array.size()+1)/2;
    sort(array.begin(), array.begin() + mid1);
    sort(array.begin() + mid2, array.end());
    return (array.substr(0, mid1) == array.substr(mid2));
}

int main(int argc, char *argv[]) {
    int t = atoi(argv[1]), t2 = t;
    string val;
    vector<string> array;

    while (t-- > 0 && cin >> val) 
        array.push_back(val);

    int i = 0;
    while (i < t2) {
        if(ret_laps(array.at(i)))
            cout << "YES";
        else 
            cout << "NO";
        cout << "\n";
        i++;
    }
    return 0;
}