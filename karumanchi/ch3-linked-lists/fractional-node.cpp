#include "../includes/sll.h"

void nod(node *head, int k)
{
	int i = 0;
	node *frac = NULL;

	if (k <= 0)
	{
		return;
	}

	for (; head != NULL; head = head->next)
	{
		if (i % k == 0)
		{
			if (frac == NULL)
			{
				frac = head;
			}
			else
			{
				frac = frac->next;
			}
		}

		++i;
	}

	cout << "\n"
		 << frac->data;
}

int main()
{

	sll obj;

	obj.insert(5, 1);
	obj.insert(4, 1);
	obj.insert(3, 1);
	obj.insert(2, 1);
	obj.insert(1, 1);

	obj.print();

	int k = 0;
	cout << "\nEnter k: ";
	cin >> k;

	nod(obj.returnHead(), k);

	return 0;
}
