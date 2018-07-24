#include "../headers.hpp"
using namespace std;

int match_pattern(char *text, char *pattern)
{
	if (pattern == nullptr)
		return 1;
	if (text == nullptr)
		return (pattern == 0);
	if ('?' == *pattern)
		return (match_pattern(text + 1, pattern + 1) || match_pattern(text, pattern + 1));
	if ('*' == *pattern)
		return (match_pattern(text + 1, pattern) || match_pattern(text, pattern + 1));
	if (*pattern == *text)
		return match_pattern(text + 1, pattern + 1);
	return -1;
}

int main(int argc, char **argv)
{
	char *text = argv[1], *pattern = argv[2];
	cout << endl
		 << match_pattern(text, pattern);
	return 0;
}
