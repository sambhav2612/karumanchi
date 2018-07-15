#include "../headers.hpp"
#include <stack>

class node
{
  public:
    char data;
    node *left;
    node *right;

    node()
    {
        data = '\0';
        left = nullptr;
        right = nullptr;
    }

    node(char val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class tree
{
  public:
    node *buildTree(char postfix_exp[], int size);
};

node *tree::buildTree(char postfix_exp[], int size)
{
    stack<node *> stk;

    for (int i = 0; i < size; ++i)
    {
        if ((postfix_exp[i] >= 'a' && postfix_exp[i] <= 'z') && (postfix_exp[i] >= 'A' && postfix_exp[i] <= 'Z'))
        { // operand
            node *newNode = new node(postfix_exp[i]);

            if (!newNode)
            {
                cout << "Mmeory error!" << endl;
                return nullptr;
            }

            stk.push(newNode);
        }
        else
        { // operator
            node *t2 = stk.top();
            stk.pop();
            node *t1 = stk.top();
            stk.pop();

            node *newNode = new node(postfix_exp[i]);

            if (!newNode)
            {
                cout << "Mmeory error!" << endl;
                return nullptr;
            }

            newNode->left = t1;
            newNode->right = t2;

            stk.push(newNode);
        }
    }

    node *p = &stk;
    return p;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
