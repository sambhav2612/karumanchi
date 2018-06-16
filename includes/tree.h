/**
 * Implmeentation of Tree ADT
 * Optimisations required: add a sub-routine for remove() that returns both the pointer to element to be deleted after finding it and it's parent as while deletion I think both it's link to parent and itself should be deleted and it'd not be cool otherwise.
 * */

#include "../headers.h"
#include <queue>

class node
{
  public:
	int data;
	node *left;
	node *right;

	node()
	{
		data = INT_MIN;
		left = NULL;
		right = NULL;
	}

	node(int value)
	{
		data = value;
		left = NULL;
		right = NULL;
	}
};

class tree
{
	node *root;

  public:
	tree()
	{
		root = NULL;
	}

	node *returnRoot()
	{
		return root;
	}

	void insert(int ele);
	int remove(int ele);

	void deleteTree(node *root)
	{
		if (!root)
		{
			return;
		}

		deleteTree(root->left);
		deleteTree(root->right);

		delete (root);

		if (!root)
		{
			cout << endl
				 << "Tree deleted successfully!";
		}
	}

	int search(int ele);
	void traverse();

	int size(node *root)
	{
		if (!root)
		{
			return 0;
		}
		else
		{
			return (size(root->left) + 1 + size(root->right));
		}
	}

	int height(node *root)
	{
		if (!root)
		{
			return 0;
		}
		else
		{
			int leftSub = height(root->left);
			int rightSub = height(root->right);

			if (leftSub > rightSub)
			{
				return (leftSub + 1);
			}
			else
			{
				return (rightSub + 1);
			}
		}
	}

	int leaves(node *root);

	void lca();

	// sub-routines of traverse()
	void inorder(node *root);
	void inorderIt(node *root);
	void inorderRe(node *root)
	{
		inorderRe(root->left);
		cout << root->data << " ";
		inorderRe(root->right);
	}

	void preorder(node *root);
	void preorderIt(node *root);
	void preorderRe(node *root)
	{
		cout << root->data << " ";
		preorderRe(root->left);
		preorderRe(root->right);
	}

	void postorder(node *root);
	void postorderIt(node *root);
	void postorderRe(node *root)
	{
		postorderRe(root->left);
		postorderRe(root->right);
		cout << root->data << " ";
	}
};

void tree::insert(int ele)
{
	queue<node *> obj;

	node *newNode = new node(ele);
	/*node *p = root;
	node *q = NULL;*/

	node *temp;

	if (!newNode)
	{
		cout << "\n New node could not be created!";
		return;
	}

	if (!root)
	{
		root = newNode;
		root->left = NULL;
		root->right = NULL;

		cout << "\n New Node " << ele << " inserted at root successfully!";

		return;
	}

	obj.push(root);

	// this the the old routine
	/*
	if (newNode->data < p->data)
	{
		// go to left while correct position not reached
		while (newNode->data < p->data)
		{
			q = p;
			p = p->left;
		}

		newNode = p;
		q->left = newNode;

		cout << "\n New node inserted at left of " << q->data << " successfully!";

		return;
	}
	else
	{
		// go to right while correct position not reached
		while (newNode->data >= p->data)
		{
			q = p;
			p = p->right;
		}

		newNode = p;
		q->right = newNode;

		cout << "\n New node inserted at right of " << q->data << " successfully!";

		return;
	}*/

	// this is the new routine that uses queue STL
	while (!obj.empty())
	{
		temp = obj.front();
		obj.pop();

		if (temp->left)
		{
			obj.push(temp->left);
		}
		else
		{
			temp->left = newNode;
			cout << "\n New node " << ele << " inserted at left of " << temp->data << " successfully!";

			return;
		}

		if (temp->right)
		{
			obj.push(temp->right);
		}
		else
		{
			temp->right = newNode;
			cout << "\n New node " << ele << " inserted at right of " << temp->data << " successfully!";

			return;
		}
	}
}

// this sequnce is completely wrong and will be solved soon
int tree::remove(int ele)
{
	node *p = root;
	node *q = NULL;

	int val = INT_MIN; // setting to a macro to check if value was changed

	if (ele < p->data)
	{
		// go to left while correct position not reached
		while (ele < p->data)
		{
			q = p;
			p = p->left;
		}

		val = p->data;
		q->left = NULL; // remove link from parent
	}
	else
	{
		// go to right while correct position not reached
		while (ele >= p->data)
		{
			q = p;
			p = p->right;
		}

		val = p->data;
		q->right = NULL; // remove link from parent
	}

	delete (p);

	if (p)
	{
		delete (p);
		cout << endl
			 << ele << "deleted.";
	}

	if (val != INT_MIN)
	{
		return val;
	}
	else
	{
		return -1; // error code
	}
}

int tree::search(int ele)
{
	node *p = root;

	if (ele < p->data)
	{
		// go to left while correct position not reached
		while (ele < p->data)
		{
			p = p->left;
		}
	}
	else
	{
		// go to right while correct position not reached
		while (ele >= p->data)
		{
			p = p->right;
		}
	}

	if (p)
	{
		return 1;
	}
	else if (!p)
	{
		return 0; // not found
	}
	else
	{
		return -1; // error code
	}
}

int tree::leaves(node *root)
{
	queue<node *> obj;
	node *temp;

	int count = 0;

	if (!root)
	{
		return 0;
	}

	obj.push(root);

	while (!obj.empty())
	{
		temp = obj.front();
		obj.pop();

		if (!temp->left && !temp->right)
		{
			++count;
		}
		else
		{
			if (temp->left)
			{
				obj.push(temp->left);
			}

			if (temp->right)
			{
				obj.push(temp->right);
			}
		}
	}

	return count;
}

void tree::lca()
{
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

		cout << " " << temp->data;
		obj.pop();

		if (temp->left)
		{
			obj.push(temp->left);
		}

		if (temp->right)
		{
			obj.push(temp->right);
		}
	}
}

void tree::traverse()
{
	// now traverse will have both recursive and iterative routines

	char ch = '\0';

	cout << endl
		 << "Traverse using? - Inorder(i) or Preorder(p) or Postorder(o): ";
	cin >> ch;

	switch (ch)
	{
	case 'i':
		cout << endl
			 << "Executing Inorder Traversal...";
		inorder(root);
		break;

	case 'p':
		cout << endl
			 << "Executing Preorder Traversal...";
		preorder(root);
		break;

	case 'o':
		cout << endl
			 << "Executing Postorder Traversal...";
		postorder(root);
		break;

	default:
		cout << endl
			 << "Wrong traversal method entered, try again...";
		break;
	}
}

void tree::inorder(node *root)
{
	switch (rand() % 2)
	{
	case 0: //recursive
		inorderRe(root);
		break;

	case 1: //iterative
		//inorderIt(root);
		break;

	default:
		break;
	}
}
/*
void tree::inorderIt(node *root)
{
	stack obj;
	node *p = root;

	while (1)
	{
		while (p)
		{
			obj.push(p->data);
			p = root->left;
		}

		if (obj.isEmpty())
		{
			break;
		}

		p = obj.pop();

		cout << p->data << " ";

		p = p->right;
	}
}
*/
void tree::preorder(node *root)
{
	switch (rand() % 2)
	{
	case 0: //recursive
		preorderRe(root);
		break;

	case 1: //iterative
		//preorderIt(root);
		break;

	default:
		break;
	}
}
/*
void tree::preorderIt(node *root)
{
	stack obj;
	node *p = root;

	while (1)
	{
		while (p)
		{
			cout << p->data << " ";
			obj.push(p->data);
			p = root->left;
		}

		if (obj.isEmpty())
		{
			break;
		}

		p = obj.pop();

		p = p->right;
	}
}
*/
void tree::postorder(node *root)
{
	switch (rand() % 2)
	{
	case 0: //recursive
		postorderRe(root);
		break;

	case 1: //iterative
		//postorderIt(root);
		break;

	default:
		break;
	}
}
/*
void tree::postorderIt(node *root)
{
	stack obj;
	node *p = root;
	node *q = NULL;

	while (1)
	{
		if (p)
		{
			obj.push(p->data);
			p = p->left;
		}
		else
		{
			if (obj.isEmpty())
			{
				cout << endl
					 << "Stack is empty > underflow!";
				break;
			}
			else if (obj.top()->right == NULL)
			{
				p = obj.pop();
				cout << p->data << "";

				if (p == obj, top()->right)
				{
					cout << p->data << "";
					// put in an unused object
					q = obj.pop();
				}
			}

			if (!obj.isEmpty())
			{
				p = obj.top()->right;
			}
			else
			{
				p = NULL;
			}
		}
	}
}
*/