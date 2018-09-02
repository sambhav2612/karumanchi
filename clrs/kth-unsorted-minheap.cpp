// working

#include <bits/stdc++.h>
using namespace std;

class min_heap {
    private:
        vector<int> array;
        int capacity;
        int size;
    public:
        min_heap(vector<int> ar, int array_size) {
            size = array_size;
            array = ar;
            int i = (size-1)/2;
            // analougous to build-min-heap
            while (i-- > 0) 
                min_heapify(i);
        }
        int extract_min();
        void min_heapify(int index);
};

int min_heap::extract_min() {
    if (size <= 0)
        return INT_MAX;
    int root = array.at(0);
    if (size > 1) {
        array.at(0) = array.at(size-1);
        min_heapify(0);
    }
    size--;

    return root;
}

void min_heap::min_heapify(int index) {
    int smallest = index, left = 2*index+1, right = 2*index+2;
    if (left < size && array.at(left) < array.at(smallest))
        smallest = left;
    if (right < size && array.at(right) < array.at(smallest))
        smallest = right;
    if (smallest != index) {
        swap(array.at(smallest), array.at(index));
        min_heapify(smallest);
    }    
}

int kth_smallest(vector<int> array, int size, int k) {
    min_heap mh(array, size);

    for (int i = 0; i < k-1; ++i)
        mh.extract_min();

    // after removing k-1 element from min-heap, kth smallest would be at root
    return mh.extract_min();
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]), k = atoi(argv[2]), n2 = n, val = 0;
    vector<int> array;

    while (n2-- > 0 && cin >> val)
        array.push_back(val);
    
    cout << endl << kth_smallest(array, n, k);
    return 0;
}