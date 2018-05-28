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

class stack
{
	node *head;

  public:
	stack()
	{
		head = NULL;
	}

	void insert(int ele);
	int remove();
	void print();
	int length();
	int top();
};

int stack::top()
{
	if (head != NULL)
	{
		return head->data;
	}
}

void stack::insert(int ele)
{
	node *newNode = new node(ele);

	if (!head)
	{
		head = newNode;
		head->next = NULL;
		return;
	}

	newNode->next = head;
	head = newNode;

	if (head && head == newNode)
	{
		cout << "New node successfully inserted at head." << endl;
	}
}

int stack::remove()
{
	node *p = head;

	if (head == NULL)
	{
		cout << "\nUnderflow detected." << endl;
		return -1;
	}

	int data = head->data;
	head = head->next;
	delete (p);

	if (p)
	{
		delete (p);
		cout << "Node removed from head." << endl;
	}

	return data;
}

void stack::print()
{
	node *p = head;

	if (head == NULL)
	{
		cout << "\nUnderflow detected." << endl;
		return;
	}

	cout << "\n List content are: ";
	while (p->next != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
}

int stack::length()
{
	node *p = head;
	int count = 0;

	if (head == NULL)
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
