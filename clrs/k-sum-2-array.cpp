#include <bits/stdc++.h>
using namespace std;

void sumation(vector<int> array1, vector<int> array2, int size, int k) {
    priority_queue<int> max_heap;

    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            max_heap.push(array1.at(i) + array2.at(j));

    for (int i = 0; i < k; ++i) {
        cout << max_heap.top() << " ";
        max_heap.pop(); 
    }
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]), k = atoi(argv[2]), n2 = n, val1 = 0, val2 = 0;
    vector<int> array1, array2;

    while (n2-- > 0 && cin >> val1 && cin >> val2) {
        array1.push_back(val1);
        array2.push_back(val2);
    }

    cout << endl;
    sumation(array1, array2, n, k);

    return 0;
} 