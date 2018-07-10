#include "pq.h"

int c = 0;

void push(int data)
{
	pq.insert(c, data);		// or pq.insert(-gettime(), data) to remove c
	c--;
}

int pop()
{
	return pq.delete_min();
	c++;
}

int top()
{
	return pq.min();
}

int size()
{
	return pq.size();
}

int isEmpty()
{
	return ppq.isEmpty();
}