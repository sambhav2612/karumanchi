#include "../headers.h"

class node
{
  public:
	int data;
	node *next;

	node()
	{
		data = 0;
		next = NULL;
	}

	node(int ele)
	{
		data = ele;
		next = NULL;
	}
};

class cll
{
	node *head;

  public:
	node *returnHead()
	{
		return head;
	}

	void insert(int ele, int pos);
	void remove(int pos);
	void print();
	int length();
};

void cll::insert(int ele, int pos)
{
	node *newNode = new node(ele);
	node *p = head;
	node *q = head;

	if (pos == 1)
	{
		if (!head)
		{
			head = newNode;
			head->next = head;
			return;
		}

		while (p->next != head)
		{
			p = p->next;
		}

		newNode->next = head;
		head = newNode;
		p->next = head;

		if (head && head == newNode)
		{
			cout << "New node successfully inserted at head." << endl;
		}

		return;
	}

	int k = 1;

	while (k < pos && p != head)
	{
		k++;
		q = p;
		p = p->next;
	}

	q->next = newNode;
	newNode->next = p;

	cout << "New node successfully inserted at " << pos << endl;
}

void cll::remove(int pos)
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

		while (p->next != head)
		{
			p = p->next;
		}

		head = head->next;
		p->next = head;

		delete (q);

		if (q)
		{
			delete (q);
			cout << "Node removed from head." << endl;
		}

		return;
	}

	int k = 1;

	while (k < pos && p != head)
	{
		k++;
		q = p;
		p = p->next;
	}

	q->next = p->next;
	delete (p);

	if (p)
	{
		delete (p);
		cout << "Node removed from " << pos << endl;
	}
}

void cll::print()
{
	node *p = head;

	if (!head)
	{
		cout << "\nUnderflow detected." << endl;
		return;
	}

	cout << "\n List content are: ";
	while (p != head)
	{
		cout << p->data << " ";
		p = p->next;
	}

	return;
}

int cll::length()
{
	node *p = head;
	int count = 0;

	if (!head)
	{
		cout << "\nUnderflow detected." << endl;
		return -1;
	}

	while (p != head)
	{
		++count;
		p = p->next;
	}

	return count;
}
