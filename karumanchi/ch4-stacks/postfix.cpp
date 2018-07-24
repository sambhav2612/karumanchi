#include "../includes/stack.hpp"

bool checkOp(char ch)
{
    char arr[] = {'^', '%', '*', '/', '-', '+'};

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
    {
        if (ch == arr[i])
        {
            return true;
            break;
        }
    }

    return false;
}

int convert(int a, int b, char ch)
{
    int res = 0;

    switch (ch)
    {
    case '^':
        res = b ^ a;
        break;
    case '%':
        res = b % a;
        break;
    case '*':
        res = b * a;
        break;
    case '/':
        res = b / a;
        break;
    case '-':
        res = b - a;
        break;
    case '+':
        res = b + a;
        break;
    }

    return res;
}

int main()
{
    stack<int> obj;

    string exp = "";
    cout << "Enter expression: ";
    cin >> exp;

    for (int i = 0; i < exp.length(); ++i)
    {
        if (exp[i] >= '0' && exp[i] <= '9')
        {
            obj.insert(exp[i]);
        }
        else if (checkOp(exp[i]))
        {
            int a = (int)obj.remove();
            int b = (int)obj.remove();
            obj.insert(convert(a, b, exp[i]));
        }
    }

    cout << "Answer: " << obj.top();

    return 0;
}
