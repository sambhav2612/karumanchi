#include "../includes/sll.hpp"

sll obj;

node *findKPlusOne(node *head, int k)
{
    int i;
    node *kth;

    // should return null for no elements
    if (!head)
        return head;

    for (i = 0, kth = head; kth && (i < k); ++i, kth = kth->next)
        ;

    if (i == k && kth != NULL)
    {
        return kth;
    }

    return head->next;
}

int hasNodes(node *head, int k)
{
    int i;
    for (i = 0; head && (i < k); ++i, head = head->next)
        ;

    if (i == k)
    {
        return 1;
    }

    return 0;
}

void reverse(node *head, int k)
{
    node *cur = head, *temp, *next, *newHead;
    int i;

    if (k == 0 || k == 1)
    {
        cout << "\n-1";
        return;
    }

    if (hasNodes(head, k - 1))
    {
        newHead = findKPlusOne(head, k - 1);
    }
    else
    {
        newHead = head;
    }

    while (cur && hasNodes(cur, k))
    {
        i = 0;
        temp = findKPlusOne(cur, k);

        while (i++ < k)
        {
            next = cur->next;
            cur->next = temp;
            temp = cur;
            cur = next;
        }
    }

    obj.printHead(newHead);
}

int main()
{
    int k = 0;

    cout << "\nEnter k: ";
    cin >> k;

    obj.insert(5, 1);
    obj.insert(4, 1);
    obj.insert(3, 1);
    obj.insert(2, 1);
    obj.insert(1, 1);
    obj.insert(9, 1);
    obj.insert(8, 1);
    obj.insert(7, 1);
    obj.insert(6, 1);

    obj.print();

    reverse(obj.returnHead(), k);

    return 0;
}
