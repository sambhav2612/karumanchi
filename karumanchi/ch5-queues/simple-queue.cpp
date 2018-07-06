#include "../headers.h"

/**
*
*   we need both front and rear for pointing at both ends and size for the size of the queue to manage
*
*/

int main()
{
	int size = 0;

	cout << endl
		 << "Enter size of static queue: ";
	cin >> size;

	int queue[size] = {0};
	int front = -1, rear = -1;

	char ch = '\0';
	char yes = '\0';

	do
	{
		cout << endl
			 << "MENU";
		cout << endl
			 << "1. Enqueue";
		cout << endl
			 << "2. Dequeue";
		cout << endl
			 << "3. Traverse";
		cout << endl
			 << "4. Front";
		cout << endl
			 << "5. Rear";
		cout << endl
			 << "6. Current Size";
		cout << endl
			 << "7. Exit";
		cout << endl
			 << "Enter your choice to proceed with: ";
		cin >> ch;

		int ele = 0;

		switch (ch)
		{
		case '1':
			if ((rear + 1) % size == front)
			{
				cout << "Queue Overflow, full queue found!";
				exit(0);
			}
			cout << endl
				 << "Enter element to insert in queue: ";
			cin >> ele;

			rear = (rear + 1) % size;
			queue[rear] = ele;

			if (front == -1)
			{
				front = rear;
			}

			cout << endl
				 << ele << " enqueued at front.";

			break;

		case '2':
			if (front == -1)
			{
				cout << "Queue Underflow, empty queue found!";
				exit(0);
			}

			ele = queue[front];

			if (front == rear)
			{
				front = rear = -1;
			}
			else
			{
				front = (front + 1) % size;
			}

			cout << endl
				 << "Removed element is " << ele;

			break;

		case '3':
			if (front == -1)
			{
				cout << "Queue Underflow, empty queue found!";
				exit(0);
			}

			cout << endl
				 << "FRONT->";
			for (int i = front; i <= rear; ++i)
			{
				cout << queue[i] << "->";
			}
			cout << "REAR";

			break;

		case '4':
			cout << endl
				 << "Element at front is: " << queue[front];
			break;

		case '5':
			cout << endl
				 << "Element at rear is: " << queue[rear];
			break;

		case '6':
			cout << endl
				 << "Current queue size is: " << (size + rear + 1 - front) % size;
			break;

		case '7':
			cout << endl
				 << "Exiting...";
			exit(0);

		default:
			cout << endl
				 << "Wrong choice... enter again!";
			break;
		}

		cout << endl
			 << endl
			 << "AGAIN?";
		cin >> yes;

	} while (yes == 'y' || yes == 'Y');

	return 0;
}
