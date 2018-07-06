#include "../headers.h"

int main()
{
	string abc = "";
	cin >> abc;

	cout << "Before\t" << abc;

	int i = 0;
	int strptr = -1;
	int len = abc.length();

	while (i < len)
	{
		if (strptr == -1 || abc[strptr] != abc[i])
		{
			++strptr;
			abc[strptr] = abc[i];
			++i;
		}
		else
		{
			while (i < len && abc[strptr] == abc[i])
			{
				++i;
			}

			--strptr;
		}
	}

	while (strptr < len)
	{
		abc[strptr + 1] = '\0';
		++strptr;
	}

	cout << endl
		 << "After\t" << abc;

	return 0;
}
