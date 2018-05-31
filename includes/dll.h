#include "../headers.h"

template <typename T>
class node
{
  public:
	T data;
	node *next;
	node *prev;

	node()
	{
		data = 0;
		next = NULL;
		prev = NULL;
	}

	node(T ele)
	{
		data = ele;
		next = NULL;
		prev = NULL;
	}
};

template <typename T>
class dll
{
	node<T> *head;

  public:
	void insert(int ele, int pos);
	void remove(int pos);

	void print();
	int length();
};

template <typename T>
void dll<T>::insert(int ele, int pos)
{
	node<T> *newNode = new node<T>(ele);
	node<T> *p = head;
	node<T> *q = head;

	if (pos == 1)
	{
		if (!head)
		{
			head = newNode;
			head->next = NULL;
			head->prev = NULL;
			return;
		}

		newNode->next = head;
		newNode->prev = NULL;
		head = newNode;

		if (head && head == newNode)
		{
			cout << "New node successfully inserted at head." << endl;
		}

		return;
	}

	int k = 1;

	while (k < pos && p != NULL)
	{
		k++;
		q = p;
		p = p->next;
	}

	q->next = newNode;
	newNode->prev = q;
	newNode->next = p;
	p->prev = newNode;

	cout << "New node successfully inserted at " << pos << endl;
}

template <typename T>
void dll<T>::remove(int pos)
{
	node<T> *p = head;
	node<T> *q = head;

	if (pos == 1)
	{
		if (!head)
		{
			cout << "\nUnderflow detected." << endl;
			return;
		}

		head = head->next;
		head->prev = NULL;
		delete (p);

		if (p)
		{
			delete (p);
			cout << "Node removed from head." << endl;
		}

		return;
	}

	int k = 1;

	while (k < pos && p != NULL)
	{
		k++;
		q = p;
		p = p->next;
	}

	q->next = p->next;
	p->next->prev = q;
	delete (p);

	if (p)
	{
		delete (p);
		cout << "Node removed from " << pos << endl;
	}
}

template <typename T>
void dll<T>::print()
{
	node<T> *p = head;

	if (!head)
	{
		cout << "\nUnderflow detected." << endl;
		return;
	}

	cout << "\n List content are: ";
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}

	return;
}

template <typename T>
int dll<T>::length()
{
	node<T> *p = head;

	int count = 0;

	if (!head)
	{
		cout << "\nUnderflow detected." << endl;
		return -1;
	}

	while (p != NULL)
	{
		++count;
		p = p->next;
	}

	return count;
}
