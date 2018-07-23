#include "../headers.hpp"
using namespace std;

char *reverse(char *str, int size)
{
	for (int i = 0, j = size - 1; i < j; ++i, --j)
	{
		str[i] ^= str[j];
		str[j] ^= str[i];
		str[i] ^= str[j];
	}
	return str;
}

int main(int argc, char **argv)
{
	char *str = argv[1];
	cout << endl
		 << reverse(str, strlen(str));
	return 0;
}
