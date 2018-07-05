#include "../headers.h"
#define BUCKETS 10

void bucketsort(int array[], int size)
{
	int bucket[BUCKETS] = {0}, i;

	for (i = 0; i < size; ++i)
		++bucket[array[i]];

	for (int j = 0, i = 0; j < BUCKETS; ++j)
		for (int k = bucket[j]; k > 0; --k)
			array[i++] = j;
}

void countingsort(int array[], int array2[], int size, int k)
{
	int array3[k] = {0}, i;

	for (i = 0; i < size; ++i)
		array3[array[i]] += 1;

	for (i = 1; i < k; ++i)
		array3[i] += array3[i - 1];

	for (i = size - 1; i >= 0; --i)
	{
		array2[array3[array[i]] - 1] = array[i];
		array3[array[i]] -= 1;
	}
}

void bubblesort(int array[], int n)
{
	int swapped = 1;
	for (int i = n - 1; i >= 0 && swapped; --i)
	{
		swapped = 0;
		for (int j = 0; j < i; ++j)
			if (array[j] > array[j + 1])
			{
				swap(array[j], array[j + 1]);
				swapped = 1;
			}
	}
}

void insertionsort(int array[], int n)
{
	int x, j;
	for (int i = 1; i < n; ++i)
	{
		x = array[i];
		j = i;

		while (array[j - 1] > x && j >= 0)
		{
			array[j] = array[j - 1];
			--j;
		}

		array[j] = x;
	}
}

void merge(int array[], int low, int mid, int high)
{
	int l, temp;
	l = mid - 1;

	while (low <= l && mid <= high)
	{
		if (array[low] <= array[mid])
			array[++temp] = array[++low];
		else
			array[++temp] = array[++mid];
	}

	while (low <= l)
		array[++temp] = array[++low];

	while (mid <= high)
		array[++temp] = array[++mid];
}

void mergesort(int array[], int low, int high)
{
	int mid;

	if (low < high)
	{
		mid = (high + low) / 2;
		mergesort(array, low, mid);
		mergesort(array, mid + 1, high);
		merge(array, low, mid + 1, high);
	}
}

int partition(int array[], int low, int high)
{
	int l, r, item = array[low];
	l = low;
	r = high;

	while (l < r)
	{
		while (array[l] <= item)
			++l;

		while (array[r] > item)
			--r;

		if (left < right)
			swap(array[l], array[r]);
	}

	array[low] = array[r];
	array[r] = item;

	return r;
}

void quicksort(int array[], int low, int high)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high);
		quicksort(array, low, pivot - 1);
		quicksort(array, pivot + 1, high);
	}
}

void shellsort(int array[], int n)
{
	int x, j, h;
	for (h = 0; h < n / 4; h = 2 * h + 1)
		;

	for (; h > 0; h = h / 2)
	{
		for (int i = h + 1; i < n; ++i)
		{
			x = array[i];
			j = i;

			while (j > h && array[j - h] > x)
			{
				array[j] = array[j - h];
				j -= h;
			}

			array[j] = x;
		}
	}
}