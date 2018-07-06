#include "seperate-chaining.h"

int main(int argc, char **argv)
{
	char *str = argv[1];
	int current = 0, last = 0;

	cout << endl
		 << "Before - " << str;

	struct hash_table *h;
	h = create_hash_table(10);

	for (; str[current] != '\0'; ++current)
		if (!hash_search(h, str[current]))
		{
			str[last++] = str[current];
			hash_insert(h, str[current]);
		}

	str[last] = '\0';

	cout << endl
		 << "After - " << str;

	return 0;
}
