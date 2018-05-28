#include "../headers.h"

class node
{
  public:
	int data;
	node *next;
	node *prev;

	node()
	{
		data = 0;
		next = NULL;
		prev = NULL;
	}

	node(int ele)
	{
		data = ele;
		next = NULL;
		prev = NULL;
	}
};

class dll
{
	node *head;

  public:
	void insert(int ele, int pos);
	void remove(int pos);
	void print();
	int length();
};

void dll::insert(int ele, int pos)
{
	node *newNode = new node(ele);
	node *p = head;
	node *q = head;

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

void dll::remove(int pos)
{
	node *p = head;
	node *q = head;

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

void dll::print()
{
	node *p = head;

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

int dll::length()
{
	node *p = head;
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
