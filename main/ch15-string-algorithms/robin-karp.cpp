#include "../headers.hpp"
using namespace std;

int string_match(int text[], int n, int pattern[], int m)
{
    int value = 0;
    for (int i = 0; i <= m - 1; ++i)
    {
        value *= 10;
        value += pattern[i];
    }
    int t[n - m + 1] = {0};
    for (int i = 0; i <= m - 1; ++i)
    {
        t[0] += text[i] * pow(10, m - i - 1);
    }
    for (int i = 0; i < n - m + 1; ++i)
    {
        t[i + 1] = 10 * (t[i] - pow(10, m - 1) * text[i]) + text[m + i];
        if (t[i] == value)
            return 1;
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