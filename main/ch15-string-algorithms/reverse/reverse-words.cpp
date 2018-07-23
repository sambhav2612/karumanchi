#include "../../headers.hpp"
using namespace std;

char *reverse_string(char *str, int begin, int end)
{
	for (int i = begin, j = end - 1; i < j; ++i, --j)
		swap(str[i], str[j]);
	return str;
}

char *reverse(char *text)
{
	text = reverse_string(text, 0, strlen(text));
	for (int i = 0, j = 0; j < strlen(text); ++j)
	{
		if (text[j] != '-')
		{
			i = j;
			while (text[j] != '-' && j < strlen(text))
				++j;
			reverse_string(text, i, j);
		}
	}
	return text;
}

int main(int argc, char **argv)
{
	// instead of space I'll take hyphen (-) as an identifier to same
	char *str = argv[1];
	cout << endl
		 << "Before - "
		 << str
		 << "\nAfter - "
		 << reverse(str);
	return 0;
}
