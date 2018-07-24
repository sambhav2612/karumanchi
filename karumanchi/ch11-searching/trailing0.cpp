#include "../headers.hpp"
using namespace std;

int find(int n)
{
    int count = 0;
    if (n < 0)
        return 0;
    for (int i = 5; n / i >= 0; i *= 5)
        count += n / i;
    return count;
}
int main(int argc, char **argv)
{
    int n = atoi(argv[1]);
    cout << endl
         << find(n);
    return 0;
}
