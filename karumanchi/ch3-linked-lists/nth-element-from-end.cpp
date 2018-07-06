#include "../includes/sll.h"

int main()
{
	sll obj;
	int n = 0;

	obj.insert(5, 1);
	obj.insert(4, 1);
	obj.insert(3, 1);

	cout << "\n Enter value to n (from end): ";
	cin >> n;

	obj.find(n);

	return 0;
}
