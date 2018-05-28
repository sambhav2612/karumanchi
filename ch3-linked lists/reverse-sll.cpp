#include "../includes/sll.h"

int main()
{
	sll obj;
	
	obj.insert(5, 1);
	obj.insert(4, 1);
	obj.insert(3, 1);
	obj.insert(2, 1);
	obj.insert(1, 1);

	obj.reverse();

	return 0;
}
