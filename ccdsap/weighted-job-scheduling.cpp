#include <bits/stdc++.h>

int table[100] = {0};

struct Job {
	int start;
	int finish;
	int profit;
};

bool compare(Job s1, Job s2) {
	return (s1.finish < s2.finish);
}

int latestCompatible(Job *arr, int n) {
	for (int j = n - 1; j >= 0; --j)
		if (arr[j].finish <= arr[n-1].start)
			return j;
	return -1;
}

int findMaxProfit(Job *arr, int n) {
	std::sort(arr, arr + n, compare);

	table[0] = arr[0].profit;

	for (int i = 1; i < n; ++i) {
		int inclProfit = arr[i].profit;
		int l = latestCompatible(arr, i);

		if (l != -1)
			inclProfit += table[l];

		table[i] = std::max(inclProfit, table[i-1]);
	}

	return table[n-1];;
}

int main(void) {
	Job arr[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
	int n = sizeof(arr)/sizeof(arr[0]);
	std::cout << "\n" << findMaxProfit(arr, n);
	return 0;
}