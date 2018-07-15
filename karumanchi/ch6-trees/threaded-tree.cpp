#include "../headers.hpp"

struct node
{
    int data;
    int lval;
    struct node *left;
    int rval;
    struct node *right;
};

void insert(struct node *p, struct node *q)
{
    struct node *temp;

    q->right = p->right;
    q->rval = p->rval;
    q->left = p;
    q->lval = 0; // points to the predecessor
    p->right = q;
    p->rval = 1; // points to the child

    // if p has a right child
    if (p->rval == 1)
    {
        temp = q->right;
        while (temp->lval)
            temp = temp->left;
        temp->left = q;
    }
}

int main(int argc, char const *argv[])
{

    return 0;
}
