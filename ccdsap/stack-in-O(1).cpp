#include <bits/stdc++.h>

class myStack {
    private:
        int minEle;
        std::stack<int> stk;
    public:
        void push(int x) {
            if (stk.empty()) {
                minEle = x;
                stk.push(x);
                std::cout << "\n" << x << " pushed to stack!";
                return;
            }
            if (x >= minEle) {
                stk.push(x);
                std::cout << "\n" << x << " pushed to stack!";
            }
            else {
                stk.push(2 * x - minEle);
                minEle = x; 
                std::cout << "\n" << (2 * x - minEle) << " pushed to stack!";
            }
        }
        int pop() {
            if (stk.empty())
                return INT_MIN;
            int y = stk.top();
            if (y < minEle)
                minEle = 2 * minEle - y;
            stk.pop();
            return y;
        }
        int getMin() {
            if (!stk.empty())
                return minEle;
            return INT_MIN;
        }
};

int main() {
    myStack s;
    s.push(3);
    s.push(5);
    std::cout << "\n Minimum - " << s.getMin();
    s.push(2);
    s.push(1);
    std::cout << "\n Minimum - " << s.getMin();
    std::cout << "\n Removed - " << s.pop();
    std::cout << "\n Minimum - " << s.getMin();
    std::cout << "\n Removed - " << s.pop();
    return 0;
}