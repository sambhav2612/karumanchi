#include "../headers.hpp"
using namespace std;

int *fail;

void prefix(int pattern[], int m)
{
    int i = 1, j = 0;
    fail = new int[m];
    fail[0] = 0;
    while (i < m)
    {
        if (pattern[i] == pattern[j])
        {
            fail[i] = j + 1;
            ++i;
            ++j;
        }
        else if (j > 0)
            j = fail[j - 1];
        else
        {
            fail[i] = 0;
            ++i;
        }
    }
}

int string_match(int text[], int n, int pattern[], int m)
{
    int i = 0, j = 0;
    prefix(pattern, m);

    while (i < m)
    {
        if (text[i] == pattern[j])
            if (j == m - 1)
                return i - j;
            else
            {
                ++i;
                ++j;
            }
        else if (j > 0)
            j = fail[j - 1];
        else
            ++i;
    }
    return -1;
}

int main(int argc, char **argv)
{
    int n = atoi(argv[1]), m = atoi(argv[2]), text[n] = {0}, pattern[m] = {0};

    for (int i = 0; i < n; ++i)
        cin >> text[i];
    for (int i = 0; i < m; ++i)
        cin >> pattern[i];

    cout << endl
         << string_match(text, n, pattern, m);

    return 0;
}