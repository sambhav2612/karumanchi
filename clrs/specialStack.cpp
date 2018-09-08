#include <bits/stdc++.h>
using namespace std;

class specialStack {
    private:
        stack<int> s1, s2;

    public:
        void push(int x) {
            s1.push(x);
            if (s2.empty())
                s2.push(s1.top());
            else if (s1.top() >= s2.top()) 
                s2.push(s2.top());      // keep minimum elements in s2
            else
                s2.push(s1.top());      // keep maximum elements in s3
        }

        int pop() {
            int ele = s1.top();
            s1.pop();
            s2.pop();
            return ele;
        }

        int getMin() {
            int ele = s2.top();
            s2.pop();
            return ele; 
        }
};

int main() {

    specialStack ptr;
    ptr.push(1);
    ptr.push(2);
    ptr.push(3);
    cout << "\n" << ptr.getMin();
    cout << "\n" << ptr.pop();
    cout << "\n" << ptr.getMin();
    return 0;
}