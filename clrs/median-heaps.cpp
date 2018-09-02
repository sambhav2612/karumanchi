#include <bits/stdc++.h>
using namespace std;

void ret_median(vector<int> array, int size) {
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;

    int median = array.at(0);
    max_heap.push(median);

    cout << median;

    for (int i = 1; i < size; ++i) {
        int element = array.at(i);

        if (max_heap.size() > min_heap.size()) {
            if (element < median)   {
                min_heap.push(max_heap.top());
                max_heap.pop(); //flush the top
                max_heap.push(element);
            }
            else 
                min_heap.push(element);

            median = (max_heap.top() + min_heap.top())/2;
        }
        else if (max_heap.size() < min_heap.size()) {
            if (element < median)   {
                max_heap.push(min_heap.top());
                min_heap.pop(); //flush the top
                min_heap.push(element);
            }
            else 
                max_heap.push(element);

            median = (max_heap.top() + min_heap.top())/2;
        }
        else if (max_heap.size() == min_heap.size()) {
            if (element < median) {
                max_heap.push(element);
                median = max_heap.top();
            }
            else {
                min_heap.push(element);
                median = min_heap.top();
            }
        }
        
        cout << median << " ";
    }
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]), n2= n, val = 0;
    vector<int> array;

    while (n2-- > 0 && cin >> val)
        array.push_back(val);

    cout << endl;
    ret_median(array, n);

    return 0;
}