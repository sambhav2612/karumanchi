#include "../includes/stack.h"

void insertAtBottom(stack<int> obj, int data)
{
	int temp;

	if (obj.isEmpty())
	{
		obj.insert(data);
		return;
	}

	temp = obj.remove();
	insertAtBottom(obj, data);
	obj.insert(temp);
}

void reverse(stack<int> obj)
{
	int data;

	if (obj.isEmpty())
	{
		return;
	}

	data = obj.remove();
	reverse(obj);
	insertAtBottom(obj, data);
}

int main()
{
	stack<int> obj;

	obj.insert(5);
	obj.insert(4);
	obj.insert(3);
	obj.insert(2);
	obj.insert(1);

	reverse(obj);

	return 0;
}
