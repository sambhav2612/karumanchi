// working

#include <bits/stdc++.h>
using namespace std;

class max_heap {
    private:
        vector<int> array;
        int size;
    public:
        max_heap(vector<int> ar, int n) {
            array = ar;
            size = n;
            int i = (size-1)/2;
            while(i-- > 0) 
                max_heapify(i);
        }
        void max_heapify(int index);
        int extract_max();

};

int max_heap::extract_max() {
    if (size <= 0)
        return INT_MIN;
    int root = array.at(0);
    if (size > 1) {
        array.at(0) = array.at(size-1);
        max_heapify(0);
    }
    size--;

    return root;
}

void max_heap::max_heapify(int index) {
    int largest = index;
    int left = 2*index+1;
    int right = 2*index+2;

    if (left < size && array.at(left) > array.at(largest))
        largest = left;
    if (right < size && array.at(right) > array.at(largest))
        largest = right;
    if (largest != index) {
        swap(array.at(largest), array.at(index));
        max_heapify(largest);
    }
}

void kth_largest (vector<int> array, int size, int k) {
    max_heap mh(array, size);
    
    for (int i = 0; i < k ; ++i)
        cout << mh.extract_max() << " ";
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]), k = atoi(argv[2]), val = 0, n2 = n;
    vector<int> array;

    while (n2-- > 0 && cin >> val) 
        array.push_back(val);
    
    cout << endl;
    kth_largest(array, n, k);

    return 0;
}