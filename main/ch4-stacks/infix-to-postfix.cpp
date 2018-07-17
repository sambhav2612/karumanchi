#include "../includes/stack.hpp"

int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

int main()
{
    stack<char> obj;

    obj.insert('N');

    string exp = "";
    cout << "Enter expression: ";
    cin >> exp;

    for (int i = 0; i < exp.length(); ++i)
    {
        if ((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z'))
        {
            cout << exp[i] << " ";
        }
        else if (exp[i] == ')')
        {
            while (obj.top() != ')')
            {
                cout << obj.remove() << " ";
            }
        }
        else
        {
            while (prec(exp[i]) <= prec(obj.top()))
            {
                cout << obj.remove() << " ";
            }
        }
    }

    while (obj.top() != 'N')
    {
        cout << obj.remove() << " ";
    }

    return 0;
}
