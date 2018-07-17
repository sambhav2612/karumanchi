#include "../includes/sll.hpp"
using namespace std;

int main()
{
    sll obj;

    bool checkForStartNode = false;
    bool checkForLengthOfLoop = false;

    obj.insert(5, 1);
    obj.insert(4, 1);
    obj.insert(3, 1);

    cout << "\n Check for start node? and Check for length of the loop? ";
    cin >> checkForStartNode >> checkForLengthOfLoop;

    obj.cycle(checkForStartNode, checkForLengthOfLoop);

    return 0;
}
