#include "../includes/cll.hpp"

void split(cll obj)
{
    node *head = obj.returnHead();
    node *head1 = NULL, *head2 = NULL;

    node *slow = head, *fast = head;

    if (!head)
    {
        return;
    }

    while (fast->next != head && fast->next->next != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // if fast is now on second last element
    if (fast->next->next == head)
    {
        // move to list end
        fast = fast->next;
    }

    head1 = head;

    // more than one element
    if (head->next != head)
    {
        // slow sits on the end of the first list (left split)
        head2 = slow->next;
    }

    fast->next = head2;
    slow->next = head1;

    cll obj2, obj3;

    while (head1->next != head1)
    {
        obj2.insert(head1->data, 1);
        head1 = head1->next;
    }

    while (head2->next != head2)
    {
        obj2.insert(head2->data, 1);
        head2 = head2->next;
    }

    obj2.print();
    obj3.print();
}

int main()
{
    cll obj;

    obj.insert(1, 1);
    obj.insert(2, 1);
    obj.insert(3, 1);
    obj.insert(4, 1);
    obj.insert(5, 1);

    obj.print();

    split(obj);

    return 0;
}
