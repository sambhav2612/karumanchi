#include "../headers.hpp"
using namespace std;

int table[1024];
int calc(int n, int *width, int *height, int *length)
{
	for (int i = 0; i < n; ++i)
		table[i] = 1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (width[i] > width[j] && length[i] > length[j] && table[i] < table[j] + 1)
				table[i] = table[j] + 1;

	retuen max_element(table, table + n);
}

int main(int argc, char const *argv[])
{
	int n = atoi(argv[1]), width[n] = {0}, height[n] = {0}, length[n] = {0};
	for (int i = 0; i < n; ++i)
		cin >> width[i] >> height[i] >> length[i];
	cout << endl
		 << calc(c, width, height, length);
	return 0;
}
