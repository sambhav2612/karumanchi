#include "../includes/queue.hpp"

int main()
{
    queue obj;

    obj.insert(1);
    obj.insert(2);
    obj.insert(3);

    cout << endl
         << obj.isEmpty() << endl;
    cout << endl
         << obj.remove() << endl;

    return 0;
}
