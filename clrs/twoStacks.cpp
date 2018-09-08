#include <bits/stdc++.h>
using namespace std;

class twoStacks {
    private:
        int *array;
        int size;
        int top1, top2;

    public:
        twoStacks(int n) {
            size = n;
            array = new int[size];
            top1 = 0;
            top2 = size-1;
        }

        void push1(int x) {
            if (top1 < top2 - 1)
                array[++top1] = x;
            else 
                return;
        }
        
        void push2(int x) {
            if (top1 < top2 - 1)
                array[--top2] = x;
            else 
                return;
        }

        int pop1() {
            if (top1 >= 0)
                return array[top1--];
            else
                return INT_MIN;
        }

        int pop2() {
            if (top2 <= size-1)
                return array[top2++];
            else
                return INT_MIN;
        }

        int topE1() {
            return array[top1-1];
        }

        int topE2() {
            return array[top2+1];
        }
};

int main() {
    twoStacks ts(5);
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7);
    cout << "\n" << ts.pop1();
    ts.push2(40);
    cout << "\n" << ts.pop2();
    return 0;
}