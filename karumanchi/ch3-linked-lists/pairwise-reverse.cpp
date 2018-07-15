#include "../includes/sll.hpp"

node *reverse(node *head)
{
    if (!head || !head->next)
    {
        return NULL;
    }
    else
    {
        node *temp = head->next;
        head->next = temp->next;
        temp->next = head;
        head = temp;

        head->next->next = reverse(head->next->next);

        return head;
    }
}

int main()
{
    sll obj;

    obj.insert(1, 1);
    obj.insert(2, 1);
    obj.insert(3, 1);
    obj.insert(4, 1);
    obj.insert(5, 1);
    // creates a sequence 5->4->3->2->1

    obj.print();

    reverse(obj.returnHead());

    obj.print();

    return 0;
}
