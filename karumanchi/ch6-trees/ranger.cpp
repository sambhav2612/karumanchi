#include "../includes/tree.hpp"

void ranger(node *root, int a, int b)
{
    if (!root)
        return;
    if (root->data >= a)
        ranger(root->left, a, b);
    if (root->data >= a && root->data <= b)
        cout << root->data << " ";
    if (root->data <= b)
        ranger(root->right, a, b);
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

    obj.inorderRe(obj.returnRoot());

    cout << endl;
    ranger(obj.returnRoot(), 1, 7);

    return 0;
}
