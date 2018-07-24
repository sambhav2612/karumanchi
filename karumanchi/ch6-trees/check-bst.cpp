#include "../includes/tree.hpp"

int checkBST(node *root)
{
    if (!root)
        return 1;
    if (root->left && root->left->data > root->data)
        return 0;
    if (root->right && root->right->data < root->data)
        return 0;
    if (!checkBST(root->left) && !checkBST(root->right))
        return 0;
    return 1;
}

int isBST(node *root, int prev)
{
    if (!root)
        return 1;
    if (!isBST(root->left, prev))
        return 0;
    prev = root->data;

    return isBST(root->right, prev);
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

    cout << endl
         << checkBST(obj.returnRoot())
         << endl
         << isBST(obj.returnRoot(), INT_MIN);

    return 0;
}
