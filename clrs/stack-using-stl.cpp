#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

class myStack {
    private:
        int count;
        priority_queue<pair<int, int>> pq;

    public:
        void push(int x) {
            count++;
            pq.push(pi(count, x));
        }

        int pop() {
            if (pq.empty())
                return INT_MIN;
            count--;
            pi temp = pq.top();
            pq.pop();
            return temp.second;
        }

        int top() {
            pi temp = pq.top();
            return temp.second;
        }
};

int main() {
    myStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << "\n" << s.top();
    cout << "\n" << s.pop();
    cout << "\n" << s.top();
    return 0;
}