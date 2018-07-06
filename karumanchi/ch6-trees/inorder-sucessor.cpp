/**
 * 
 * Refer: https://www.geeksforgeeks.org/inorder-successor-in-binary-search-tree/ 
 * 
 */

#include "../includes/tree.h"

node *inorderSucessor(node *head)
{
	static node *p;
	static stack<node *> stk;

	if (head != nullptr)
		p = head;

	if (p->right == nullptr) // on of the ancestor is the sucessor
	{
		p = stk.top();
		stk.pop();
	}
	else // lies in right, get the min value
	{
		p = p->right;
		while (p->left != nullptr)
		{
			stk.push(p);
			p = p->left;
		}
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
