#include "../headers.hpp"

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

	node(T ele)
	{
		data = ele;
		next = NULL;
	}
};

template <typename T>
class sll
{
	node<T> *head;

  public:
	node<T> *returnHead()
	{
		return head;
	}

	void insert(int ele, int pos);
	void remove(int pos);

	void print();
	void printHead(node<T> *newHead);

	void find(int n);
	void cycle(bool start, bool length);

	void reverse();

	int length();
	bool empty();
};

template <typename T>
bool sll<T>::empty()
{
	if (head == NULL)
	{
		return true;
	}
	else
	{
		return true;
	}
}

template <typename T>
void sll<T>::reverse()
{
	if (!empty())
	{
		node<T> *p = head;
		node<T> *q = p->next;
		node<T> *r = q->next;

		p->next = NULL;

		while (q != NULL)
		{
			q->next = p;
			p = q;
			q = r;
			r = r->next;
		}

		q->next = p;

		head = q;

		print();
	}
}

template <typename T>
void sll<T>::cycle(bool start, bool length)
{
	node<T> *slow = head;
	node<T> *fast = head;

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

template <typename T>
void sll<T>::find(int n)
{
	if (!empty())
	{
		node<T> *p = head;

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

template <typename T>
void sll<T>::insert(int ele, int pos)
{
	node<T> *newNode = new node<T>(ele);
	node<T> *p = head;
	node<T> *q = head;

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

template <typename T>
void sll<T>::remove(int pos)
{
	node<T> *p = head;
	node<T> *q = head;

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

template <typename T>
void sll<T>::print()
{
	node<T> *p = head;

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

template <typename T>
void sll<T>::printHead(node<T> *newHead)
{
	node<T> *p = newHead;

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

template <typename T>
int sll<T>::length()
{
	node<T> *p = head;
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
