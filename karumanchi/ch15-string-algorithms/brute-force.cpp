#include "../headers.hpp"
using namespace std;

int string_match(int *text, int n, int *pattern, int m)
{
    for (int i = 0; i < n - m + 1; ++i)
    {
        int j = 0;
        while (j < m && pattern[j] == text[i + j])
            ++j;
        if (j == m)
            return 1;
    }
    return -1;
}

int main(int argc, char **argv)
{
    int n = atoi(argv[1]), m = atoi(argv[2]);
    int *text, *pattern;

    for (int i = 0; i < n; ++i)
        cin >> text[i];
    for (int i = 0; i < m; ++i)
        cin >> pattern[i];

    cout << endl
         << string_match(text, n, pattern, m);

    return 0;
}