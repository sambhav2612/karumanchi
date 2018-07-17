#include "../headers.hpp"

#define INT_MIN 1

int main()
{
    int n = 0;
    cin >> n;

    int array[n] = {0};
    for (int i = 0; i < n; ++i)
    {
        cin >> array[i];
    }

    int bigger = INT_MIN;

    for (int i = 0; i < n; ++i)
    {
        bigger = -INT_MIN;

        for (int j = i + 1; j < n; ++j)
        {
            if (array[i] < array[j])
            {
                bigger = array[j];
                break;
            }
        }

        cout << "For " << array[i] << ", the nearest greatest element is: " << bigger << endl;
    }

    return 0;
}
