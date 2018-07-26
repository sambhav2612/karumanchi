#include "../headers.hpp"
using namespace std;

class node
{
  private:
	int data;
	int frequency;
	node *left;
	node *right;

  public:
	node()
	{
		this->data = -1;
		this->frequency = 0;
		this->left = nullptr;
		this->right = nullptr;
	}
	node(int value, int freq)
	{
		this->data = value;
		this->frequency = freq;
		this->left = nullptr;
		this->right = nullptr;
	}
};

class bin_tree
{
  private:
	node *root;

  public:
	void optimal_BST(int *array, int *frequency, int low, int high);
};

void bin_tree::optimal_BST(int *array, int *frequency, int low, int high)
{
	int r, min_time = 0;
	node new_node = new node();

	if (!new_node)
		return;

	for (r = 0, r <= high; ++r)
	{
		root->left = optimal_BST(array, frequency, low, r - 1);
		root->right = optimal_BST(array, frequency, r + 1, high);
		root->data = array[r];

		int s_root = root->left + root->right + root->data;

		if (min_time > s_root)
			min_time = s_root;
	}

	return min_time;
}