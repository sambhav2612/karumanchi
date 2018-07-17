#include "../includes/tree.hpp"
#include <stack>

void reverse(node *root)
{
    stack<node *> stk;
    queue<node *> obj;
    node *temp;

    if (!root)
    {
        return;
    }

    obj.push(root);

    while (!obj.empty())
    {
        temp = obj.front();

        if (temp->left)
        {
            obj.push(temp->left);
        }

        if (temp->right)
        {
            obj.push(temp->right);
        }

        stk.push(temp);
    }

    while (!stk.empty())
    {
        cout << stk.top() << " ";
    }
}

int main(int argc, char const *argv[])
{
    tree obj;

    /**
	 * Building this tree:
	 *
	 * 			1
	 * 		   / \
	 *  	  2   3
	 *		 /\   /\
	 *		4  5 6  7
	 * */

    obj.insert(1);
    obj.insert(2);
    obj.insert(3);
    obj.insert(4);
    obj.insert(5);
    obj.insert(6);
    obj.insert(7);

    reverse(obj.returnRoot());

    return 0;
}
