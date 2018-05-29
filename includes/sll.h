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

class sll
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
	void find(int n);
	void cycle(bool start, bool length);
	void reverse();
	bool empty();
};

bool sll::empty()
{
	if (head == NULL)
	{
		cout << "\n Underflow Detected.";
		return true;
	}
	else
	{
		return true;
	}
}

void sll::reverse()
{
	if (!empty())
	{
		node *p = head;
		node *q = head;
		node *r = head;

		p->next = NULL;

		while (q != NULL)
		{
			q->next = p;
			p = q;
			q = r;
			r = r->next;
		}

		q->next = p;

		print();
	}
}

void sll::cycle(bool start, bool length)
{
	node *slow = head;
	node *fast = head;
	bool loop = false;

	if (!empty())
	{

		while (slow && fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;

			if (slow == fast)
			{
				loop = true;
				break;
			}
		}

		if (!loop)
		{
			cout << "\n No cycle found.";
		}

		if (loop && start)
		{
			slow = head;

			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}

			cout << "\n Start node is " << slow->data;
		}

		if (loop && length)
		{
			int count = 0;
			fast = fast->next;

			while (slow != fast)
			{
				fast = fast->next;
				++count;
			}

			cout << "\n Length of loop is " << count;
		}
	}
}

void sll::find(int n)
{
	if (!empty())
	{
		node *p = head;

		int len = length();
		int k = 1;

		while (p != NULL && k < len - n + 1)
		{
			k++;
			p = p->next;
		}

		if (k >= n)
		{
			cout << "\nNode " << p->data << " found at " << n;
		}
		else
		{
			cout << "\nNode not found in the list.";
		}
	}
}

void sll::insert(int ele, int pos)
{
	node *newNode = new node(ele);
	node *p = head;
	node *q = head;

	if (pos == 1)
	{
		if (empty())
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
	newNode->next = p;

	cout << "New node successfully inserted at " << pos << endl;
}

void sll::remove(int pos)
{
	node *p = head;
	node *q = head;

	if (pos == 1)
	{
		if (empty())
		{
			cout << "\nUnderflow detected." << endl;
			return;
		}

		head = head->next;
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
	delete (p);

	if (p)
	{
		delete (p);
		cout << "Node removed from " << pos << endl;
	}
}

void sll::print()
{
	node *p = head;

	if (!empty())
	{
		cout << "\n List content are: ";
		while (p != NULL)
		{
			cout << p->data << " --> ";
			p = p->next;
		}

		return;
	}
}

int sll::length()
{
	node *p = head;
	int count = 0;

	if (!empty())
	{
		while (p->next != NULL)
		{
			++count;
			p = p->next;
		}

		return count;
	}
	else
		return -1;
}
