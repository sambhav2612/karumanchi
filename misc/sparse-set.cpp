#include "sparse-set.h"

int main()
{
	SparseSet<unsigned> set;
	set.insert(5);
	set.insert(101);
	set.insert(9995);
	set.insert(34);
	set.insert(87);
	set.insert(9999999);

	cout << endl;

	for (auto &x : set)
	{
		cout << x << " ";
	}

	cout << endl;

	for (auto i = set.begin(); i != set.end(); ++i)
	{
		cout << *i << " ";
	}

	cout << endl;

	return 0;
}
