#include "../includes/tree.hpp"

node *buildBST(int array[], int left, int right)
{
	int mid = 0;

	if (left > right)
	{
		cout << endl
			 << "nope. 1 ";
		return nullptr;
	}

	node *newNode = new node(0);

	if (!newNode)
	{
		cout << endl
			 << "nope. 2 ";
		return nullptr;
	}

	if (left == right)
	{
		newNode->data = array[left];
		newNode->left = newNode->right = nullptr;
	}
	else
	{
		mid = left + (right - left) / 2;
		newNode->data = array[mid];
		newNode->left = buildBST(array, left, mid - 1);
		newNode->left = buildBST(array, mid + 1, right);
	}

	return newNode;
}

int main(int argc, char const *argv[])
{
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	cout << endl
		 << buildBST(array, 0, 10);

	return 0;
}
