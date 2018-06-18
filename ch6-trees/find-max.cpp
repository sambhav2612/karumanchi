#include "../includes/tree.h"

int findmax(node *root)
{
	int root_value = 0, left_value = 0, right_value = 0, max_value = INT_MIN;

	if (root)
	{
		root_value = root->data;
		left_value = findmax(root->left);
		right_value = findmax(root->right);

		if (left_value > right_value)
		{
			max_value = left_value;
		}
		else
		{
			max_value = right_value;
		}

		if (root_value > max_value)
		{
			max_value = root_value;
		}
	}

	return max_value;
}

int main()
{
	int x = 5;
	int array[1] = {0};
	int length = 0;

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

	cout << endl
		 << endl
		 << " Max element is: " << findmax(obj.returnRoot())
		 << endl
		 << " And, size of tree is: " << obj.size(obj.returnRoot())
		 << endl
		 << " And, height of tree (# levels) is: " << obj.height(obj.returnRoot())
		 << endl
		 << " And, # leaves is: " << obj.leaves(obj.returnRoot())
		 << endl
		 << " And, level with max sum is: " << obj.maxLevelSum(obj.returnRoot())
		 << endl
		 << " And, diameter of tree is: " << obj.diameter(obj.returnRoot(), &x)
		 << endl
		 << " And, Path length to every root->leaf path is: "
		 << endl
		 << obj.pathLength(obj.returnRoot(), array, length)
		 << endl;

	return 0;
}
