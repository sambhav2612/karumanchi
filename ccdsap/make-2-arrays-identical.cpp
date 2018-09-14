#include <bits/stdc++.h>

int calc(int *array1, int *array2, int n) {
    std::map<int, int> mp;
    for (int i = 0; i < n; ++i)
        mp[array2[i]] = i;
    for (int i = 0; i < n; ++i)
        array2[i] = mp[array1[i]];
    
    std::pair<int, int> arr[n];
    for (int i = 0; i < n; ++i) {
        arr[i].first = array2[i];
        arr[i].second = i;
    }

    sort(arr, arr + n);     // sort pair array by keys

    std::vector<bool> visited(n, false);
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        if (arr[i].second == i || visited[i])
            continue;
        int cycle_size = 0;
        int j = i;
        while (!visited[j]) {
            visited[j] = true;
            j = arr[i].second;
            cycle_size++;
        }
        ans += cycle_size-1;
    }

    return ans;
}

int main() {
    int n = 0;
    std::cin >> n;
    int array1[n] = {0}, array2[n] = {0};
    for (int i = 0; i < n; ++i)
        std::cin >> array1[i] >> array2[i];
    std::cout << "\n" << calc(array1, array2, n);
    return 0;
}