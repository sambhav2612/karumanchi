#include <bits/stdc++.h>
using namespace std;

void rearrange(vector<int> array) {
    for (int i = 0; i < array.size(); ++i) {

        if (array[i] != i && array[i] != -1) {
            int x = array[i];

            // do not change value if value is already present at x or -1
            while (array[x] != i && array[x] != -1) {
                int y = array[x];
                array[x] = x;
                x = y;
            }

            array[x] = x;

            // if still not same, make it -1 
            // ignored next time
            if (array[i] != i)
                array[i] = -1;
        }
    }
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]), n2 = n, val = 0;
    vector<int> array;

    while (n2-- > 0 && cin >> val)
        array.push_back(val);

    int i = 0;
    while (i++ < n)
        cout << array[i] << " ";

    rearrange(array);
    
    i = 0;
    while (i++ < n)
        cout << array[i] << " ";

    return 0;
}