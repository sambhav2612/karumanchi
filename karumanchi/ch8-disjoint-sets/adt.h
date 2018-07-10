#include "../headers.h"

void make_set(int s[], int size)
{
	for (int i = size - 1; i >= 0; i--)
		s[i] = i;
}

// runtime depends on union_set()
int find_set(int s[], int size, int x)
{
	if (!(x >= 0 && x < size))
		return -1;
	if (s[x] == x)
		return x;
	return find_set(s, size, s[x]);
}

// compatible with union_by_size() not with union_by_height()
int find_set_by_path_compression(int s[], int size, int x)
{
	if (!(x >= 0 && x < size))
		return -1;
	if (s[x] <= 0)
		return x;
	return (s[x] = find_set_by_path_compression(s, size, s[x]));
}

// creates skewed tree, find_set() become O(n)
void union_set(int s[], int size, int r1, int r2)
{
	if (find_set(s, size, r1) == find_set(s, size, r2))
		return;
	if (!((r1 >= 0 && r1 < size) && (r2 >= 0 && r2 < size)))
		return;
	s[r1] = r2;
}

// find_set() takes O(logn)
void union_by_size(int s[], int size, int r1, int r2)
{
	if (find_set(s, size, r1) == find_set(s, size, r2))
		return;
	if (s[r1] < s[r2])
	{
		s[r1] = r2;
		s[r2] += s[r1];
	}
	else
	{
		s[r2] = r1;
		s[r1] += s[r2];
	}
}

// find_set() takes O(logn)
void union_by_height(int s[], int size, int r1, int r2)
{
	if (find_set(s, size, r1) == find_set(s, size, r2))
		return;
	if (s[r1] < s[r2])
		s[r1] = r2;
	else
	{
		if (s[r2] == s[r1])
		{
			s[r1]--;
			s[r2] = r1;
		}
	}
}