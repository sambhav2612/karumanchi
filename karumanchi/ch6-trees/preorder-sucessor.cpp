#include "../includes/tree.hpp"

node *preorderSucessor(node *head)
{
    static node *p;
    static stack<node *> stk;

    if (head != nullptr)
        p = head;

    if (p->left != nullptr)
    {
        stk.push(p);
        p = p->left;
    }
    else
    {
        while (p->right == nullptr)
        {
            p = stk.top();
            stk.pop();
        }
        p = p->right;
    }

    return p;
}

int main()
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

    return 0;
}
