#include <bits/stdc++.h>

std::vector<int> result;

void calc(int *array, int n) {
    int max = INT_MIN, max_top = 0, tp = 0, i = 0;
    std::stack<int> stk;
    for (;i < n;) {
        if (stk.empty() || array[stk.top()] <= array[i])
            stk.push(i++);
        else {
            tp = stk.top();
            stk.pop();

            max_top = array[tp] * (stk.empty() ? i : i - stk.top() + 1);

            if (max_top > max)
                max = max_top;
        }
    }

    while (!stk.empty()) {
        tp = stk.top();
        stk.pop();

        max_top = array[tp] * (stk.empty() ? i : i - stk.top() + 1);

        if (max_top > max)
            max = max_top;
    }
    result.push_back(max);
}

int main() {
    int t = 0;
    std::cin >> t;
    int i = 0, t2 = t;
    while (t) {
        int n = 0;
        std::cin >> n;
        int array[n] = {0};
        for (int i = 0; i < n; ++i)
            std::cin >> array[i];
        calc(array, n);
        t--;
    }
    while (i++ < t2)
        std::cout << "\n" << result[i];
    return 0;
}