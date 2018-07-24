#include "../headers.hpp"
using namespace std;

char *reverse(char *str, int size)
{
	char *str2 = (char *)malloc(sizeof(char) * size + 1);
	for (int i = 0, j = size - 1; i < size; ++i, --j)
		str2[i] = str[j];
	return str2;
}

int main(int argc, char **argv)
{
	char *str = argv[1];
	cout << endl
		 << reverse(str, strlen(str));
	return 0;
}
