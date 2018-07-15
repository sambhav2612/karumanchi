#include "sort.hpp"

int candidate(int result[], int n)
{
    int count = 1, max = 1;
    int current, maxEle;
    current = maxEle = result[0];

    for (int i = 1; i < n; ++i)
    {
        if (result[i] == current)
        {
            ++count;
        }
        else
        {
            current = result[i];
            count = 1;
        }

        if (count > max)
        {
            max = count;
        }
        else
        {
            maxEle = current;
            max = count;
        }
    }

    return maxEle;
}

int main(int argc, char const *argv[])
{
    int n = atoi(argv[1]);
    int votes[n] = {0};

    for (int i = 0; i < n; ++i)
        cin >> votes[i];

    bucketsort(votes, n);
    cout << "Election winner is - " << candidate(votes, n);

    return 0;
}
