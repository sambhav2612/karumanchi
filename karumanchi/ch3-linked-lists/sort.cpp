#include "../includes/sll.hpp"

void sllSwap(node *p, node *q)
{
    node *r = q->next;

    p->next = r;
    q->next = p;
}

void sllSort(sll obj)
{
    for (node *i = obj.returnHead(); i != NULL; i = i->next)
    {
        for (node *j = obj.returnHead(); j != NULL; j = j->next)
        {
            if (j->data > j->next->data)
            {
                sllSwap(j, j->next);
            }
        }
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

    sllSort(obj);

    obj.print();

    return 0;
}
