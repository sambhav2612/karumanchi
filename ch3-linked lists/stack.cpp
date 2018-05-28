#include "../includes/stack.h"

int main()
{
	stack obj;
	char yes = 'y';
	char ch;

	int ele = 0, pos = 0;

	do
	{
		cout << endl
			 << "MENU" << endl;
		cout << "a) Push" << endl;
		cout << "b) Pop" << endl;
		cout << "c) Traverse" << endl;
		cout << "d) Exit" << endl;
		cout << "Enter a choice: ";
		cin >> ch;

		switch (ch)
		{
		case 'a':
			cout << "\nEnter element to insert and position to insert at: ";
			cin >> ele;

			obj.insert(ele);
			break;

		case 'b':
			cout << "Removed " << obj.remove() << " from top.";
			break;

		case 'c':
			obj.print();
			break;

		case 'd':
			exit(0);

		default:
			cout << "\n Wrong choice.";
		}

		cout << "\n Again? ";
		cin >> yes;
	} while (yes == 'y' || yes == 'Y');

	return 0;
}
