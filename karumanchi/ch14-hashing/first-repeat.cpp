/**
 *	checks for the latest repeatitions in the sent string
 */

#include "../headers.h"

char symmetric(char *arr, int len)
{
	int hash_table[256] = {0}, i;

	for (i = 0; i < len; ++i)
		if (hash_table[arr[i]] == 1)
			return arr[i];
		else
			hash_table[arr[i]]++;

	return '\0';
}

int main(int argc, char **argv)
{
	char *arr = argv[1];
	int len = strlen(arr);

	cout << endl
		 << "String - " << arr << endl;

	cout << endl
		 << "First repeated element is - " << symmetric(arr, len);

	return 0;
}
