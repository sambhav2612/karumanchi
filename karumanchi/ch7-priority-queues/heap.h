#include "../headers.h"

struct heap
{
	int *array;
	int count;
	int capacity;
};

void resize_heap(struct heap *h);
void heapify(struct heap *h, int i);
int left_child(struct heap *h, int index);
int right_child(struct heap *h, int index);

struct heap *create_heap(int capacity)
{
	struct heap *h = (struct heap *)malloc(sizeof(struct heap));
	if (h == nullptr)
		return nullptr;
	h->count = 0;
	h->capacity = capacity;
	h->array = (int *)malloc(sizeof(int) * h->capacity);
	if (h->array == nullptr)
		return nullptr;
	return h;
}
void insert(struct heap *h, int data)
{
	int i;
	if (h->count >= h->capacity)
		resize_heap(h);
	h->count++;
	i = h->count - 1;
	while (i >= 0 && data > h->array[(i - 1) / 2]) // data is greater than parent, percolate up
	{
		h->array[i] = h->array[(i - 1) / 2];
		i = (i - 1) / 2;
	}
	h->array[i] = data;
}
int del(struct heap *h) // by default the root element (max) gets deleted
{
	int data;
	if (h->count <= 0)
		return -1;
	data = h->array[0];
	h->array[0] = h->array[h->count - 1];
	h->count--;
	heapify(h, 0);
	return data;
}
int delete_ith(struct heap *h, int i)
{
	int key;
	if (h->count < i)
		return -1;
	key = h->array[i];
	h->array[i] = h->array[h->count - 1];
	h->count--;
	heapify(h, i);
	return key;
}
void print_k(struct heap *h, int k, int index)
{
	if (h->array[index] < k)
	{
		cout << h->array[index] << " ";
		print_k(h, k, left_child(h, index));
		print_k(h, k, right_child(h, index));
	}
	else
		return;
}
void del_heap(struct heap *h)
{
	if (h == nullptr)
		return;
	free(h->array);
	free(h);
	h = nullptr;
}
int parent(struct heap *h, int i)
{
	if (i <= 0 || i >= h->count)
		return -1;
	return (i - 1) / 2;
}
int left_child(struct heap *h, int i)
{
	int left = 2 * i + 1;
	if (left >= h->count)
		return -1;
	return left;
}
int right_child(struct heap *h, int i)
{
	int right = 2 * i + 2;
	if (right >= h->count)
		return -1;
	return right;
}
int max(struct heap *h)
{
	if (h->count <= 0)
		return -1;
	return h->array[0];
}
void resize_heap(struct heap *h)
{
	int *old = h->array;
	h->array = (int *)malloc(sizeof(int) * h->capacity * 2);
	if (h->array == nullptr)
		return;
	for (int i = 0; i < h->capacity; i++)
		h->array[i] = old[i];
	h->capacity += 2;
	free(old);
}
void heapify(struct heap *h, int i)
{
	int left, right, max = i;
	left = left_child(h, i);
	right = right_child(h, i);

	if (left != -1 && h->array[left] > h->array[i])
		max = left;
	else
		max = i;

	if (right != -1 && h->array[right] > h->array[max])
		max = right;

	if (max != i)
	{
		swap(h->array[i], h->array[max]);
		heapify(h, max);
	}
}
void build_heap(struct heap *h, int arr[], int size)
{
	if (h == nullptr)
		return;
	while (size > h->capacity)
		resize_heap(h);
	for (int i = 0; i < size; ++i)
		h->array[i] = arr[i];
	h->count = size;
	for (int i = (size - 1) / 2; i >= 0; i--)
		heapify(h, i);
}
void print_heap(struct heap *h)
{
	if (h->count <= 0)
		return;
	for (int i = 0; i < h->count; i++)
		cout << h->array[i] << " ";
}