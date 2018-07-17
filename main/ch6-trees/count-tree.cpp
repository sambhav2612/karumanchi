#include "../includes/tree.hpp"

int countrees(int n)
{
    if (n <= 1)
        return 1;
    else
    {
        int sum = 0;
        int left, right, root;

        for (root = 1; root <= n; ++root)
        {
            left = countrees(root - 1);
            right = countrees(n - root);

            sum += left * right;
        }

        return sum;
    }
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
    obj.inorderRe(obj.returnRoot());

    countrees(5);

    return 0;
}
