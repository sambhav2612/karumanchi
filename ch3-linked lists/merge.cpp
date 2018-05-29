#include "../includes/sll.h"

void sllMerge(node *head1, node *head2)
{
	node *newNode = new node();
	node *temp = newNode;

	node *h1 = head1, *h2 = head2;
	node *start = NULL;

	while (head1 != NULL && head2 != NULL)
	{
		if (head1->data <= head2->data)
		{
			temp->next = head1;
			head1 = head1->next;
		}
		else
		{
			temp->next = head2;
			head2 = head2->next;
		}

		temp = temp->next;
	}

	// L2 traversed
	if (head1 != NULL)
	{
		temp->next = head1;
		start = h2;
	}
	else
	{
		temp->next = head2;
		start = h1;
	}

	temp = newNode->next;
	delete (newNode);

	// print
	while (start != NULL)
	{
		cout << start->data << " ";
		start = start->next;
	}
}

int main()
{

	sll obj, obj2;

	obj.insert(1, 1);
	obj.insert(2, 1);
	obj.insert(3, 1);
	obj.insert(4, 1);
	obj.insert(5, 1);
	// creates a sequence 5->4->3->2->1

	obj2.insert(5, 1);
	obj2.insert(4, 1);
	obj2.insert(3, 1);
	obj2.insert(2, 1);
	obj2.insert(1, 1);
	// creates a sequence 5<-4<-3<-2<-1

	sllMerge(obj.returnHead(), obj2.returnHead());

	return 0;
}
