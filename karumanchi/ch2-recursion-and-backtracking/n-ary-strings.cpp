#include "../headers.hpp"

string A;

void generateStrings(int n)
{
    if (n < 1)
    {
        cout << "\n"
             << A;
    }
    else
    {
        A[n - 1] = '0';
        generateStrings(n - 1);

        A[n - 1] = '1';
        generateStrings(n - 1);
    }
}

int main()
{
    int n = 0;
    cout << "Enter n: ";
    cin >> n;

    generateStrings(n);

    return 0;
}
