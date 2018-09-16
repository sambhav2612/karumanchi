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
	int low = 0, high = n - 1;

	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid].finish <= arr[n].start) {		// check if current element at n index is compatible with element at mid
			if (arr[mid+1].finish <= arr[n].start)	// if yes, check if current element at n index is also compatible with element at mid + 1
				low = mid + 1;
			else									// else, return latest most compatible value ie. mid
				return mid;
		}
		else
			high = mid - 1;
	}

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