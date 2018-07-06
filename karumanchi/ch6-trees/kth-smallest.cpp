#include "../includes/tree.h"

int kth(node *root, int k, int size)
{
	if (!root)
		return 0;

	int left = kth(root->left, k, size);

	if (left)
		return left;
	if (++size == k)
		return root->data;

	return kth(root->right, k, size);
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
		 << kth(obj.returnRoot(), atoi(argv[1]), 7);

	return 0;
}
