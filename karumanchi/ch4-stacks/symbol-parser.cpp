#include "../includes/stack.hpp"

int main()
{
    stack<char> obj;

    string abc = "";

    cout << "\nEnter a string with {}, [], and (): ";
    cin >> abc;

    char ele;

    node<char> *p = obj.returnHead();

    for (int i = 0; i < abc.length(); ++i)
    {
        if ((abc[i] == '{') || (abc[i] == '[') || (abc[i] == '('))
        {
            obj.insert(abc[i]);
        }

        if ((abc[i] == '}') || (abc[i] == ']') || (abc[i] == ')'))
        {
            if (abc[i] == obj.top())
            {
                ele = obj.remove();

                if (ele != abc[i])
                {
                    cout << "\nERROR";
                }
            }
        }
    }

    if (obj.length())
    {
        cout << "\nERROR";
    }
}
