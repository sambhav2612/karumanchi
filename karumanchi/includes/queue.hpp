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

	node(int val)
	{
		data = val;
		next = NULL;
	}
};

class queue
{
	node *front;
	node *rear;

  public:
	queue()
	{
		front = NULL;
		rear = NULL;
	}

	void insert(int ele);
	int remove();
	bool isEmpty();
};

bool queue::isEmpty()
{
	if (front == NULL)
	{
		return true;
	}

	return false;
}

void queue::insert(int ele)
{

	node *newNode = new node(ele);
	newNode->next = NULL;

	if (rear)
	{
		rear->next = newNode;
	}

	rear = newNode;

	if (isEmpty())
	{
		front = rear;
	}

	if (rear == newNode)
	{
		cout << endl
			 << ele << " inserted at rear successfully";
	}
}

int queue::remove()
{
	node *temp = front;

	if (isEmpty())
	{
		cout << endl
			 << "Unable to dequeue: empty queue found!";
		exit(0);
	}

	int data = front->data;
	front = front->next;

	delete (temp);

	if (!temp)
	{
		cout << endl
			 << data << " dequeued successfully from front.";
		return data;
	}
}
