#include "../headers.h"

template <typename T>
class node
{
  public:
	T data;
	node *next;

	node()
	{
		data = 0;
		next = NULL;
	}

	node(T val)
	{
		data = val;
		next = NULL;
	}
};

template <typename T>
class queue
{
	node<T> *head;

  public:
	void insert(T ele);
	T remove();
	bool isEmpty();
};

bool queue<T>::isEmpty()
{
}
