#include <bits/stdc++.h>
using namespace std;

class myQueue {
    stack<int> s1, s2;

    public:
        void enqueue(int x) {
            s1.push(x);
        }

        int dequeue() {
            if (s1.empty() && s2.empty())
                return INT_MIN;
            if (s2.empty())
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
            int ele = s2.top();
            s2.pop();

            return ele;
        }

        int top() {
            if (s2.empty())
                return INT_MIN;
            return s2.top();
        }
};

int main() {
    myQueue q;
    q.enqueue(1);    
    q.enqueue(2);
    q.enqueue(3);
    cout << "\n" << q.dequeue();
    cout << "\n" << q.top();
    cout << "\n" << q.dequeue();
    cout << "\n" << q.top();
    return 0;
}