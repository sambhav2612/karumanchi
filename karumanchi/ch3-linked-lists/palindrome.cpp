#include "../includes/sll.hpp"

sll obj;

void reverse(node *head)
{
    node *p = head;
    node *q = p->next;
    node *r = q->next;

    p->next = NULL;

    while (q != head)
    {
        q->next = p;
        p = q;
        q = r;
        r = r->next;
    }

    q->next = p;

    head = q;
}

bool palindrome(node *head)
{
    int mid = floor(obj.length() / 2);

    // running till mid node as we have to keep this for checking
    for (node *p = head; p->next != NULL; p = p->next)
        ;

    // running till mid node as we have to keep this for checking
    node *q = NULL;
    for (int i = 0, node *k = head; i < mid, k->next != NULL; ++i, )
    {
        q = k;
        k = k->next;
    }

    /*
	*   for linked list: a->b->c->c->b->a
	*   creates two lists:
	*   a->b->c->a (starting from head) and c->b->a->c (starting from k)
	*/
    if (i == mid + 1 && k != NULL && p->next == NULL && q->next == k)
    {
        q->next = head;
        p->next = k;
    }

    // reverse second partition: a->b->c->a starting from p
    reverse(k);

    bool yes = false;

    // move both partitions from their ends
    while (head->next != head && p->next != p)
    {
        if (head->data == p->data)
        {
            yea = true;
        }
        else
        {
            yes = false;
        }

        head = head->next;
        p = p->next;
    }

    return yes;
}

int main()
{

    obj.insert(5, 1);
    obj.insert(4, 1);
    obj.insert(3, 1);
    obj.insert(2, 1);
    obj.insert(1, 1);

    obj.print();

    if (palindrome(obj.returnHead()))
    {
        cout << "\n Palindrome";
    }
    else
    {
        cout << "\n Not Palindrome";
    }

    return 0;
}
