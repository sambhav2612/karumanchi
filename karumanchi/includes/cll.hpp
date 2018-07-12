#include "../headers.hpp"

template <typename T>
class node
{
  public:
    T data;
    node *next;

    node()
    {
        data = 0;
        next = NULL;
    }

    node(T ele)
    {
        data = ele;
        next = NULL;
    }
};

template <typename T>
class cll
{
    node<T> *head;

  public:
    node<T> *returnHead()
    {
        return head;
    }

    void insert(int ele, int pos);
    void remove(int pos);

    void print();
    int length();
};

template <typename T>
void cll<T>::insert(int ele, int pos)
{
    node<T> *newNode = new node<T>(ele);
    node<T> *p = head;
    node<T> *q = head;

    if (pos == 1)
    {
        if (!head)
        {
            head = newNode;
            head->next = head;
            return;
        }

        while (p->next != head)
        {
            p = p->next;
        }

        newNode->next = head;
        head = newNode;
        p->next = head;

        if (head && head == newNode)
        {
            cout << "New node successfully inserted at head." << endl;
        }

        return;
    }

    int k = 1;

    while (k < pos && p != head)
    {
        k++;
        q = p;
        p = p->next;
    }

    q->next = newNode;
    newNode->next = p;

    cout << "New node successfully inserted at " << pos << endl;
}

template <typename T>
void cll<T>::remove(int pos)
{
    node<T> *p = head;
    node<T> *q = head;

    if (pos == 1)
    {
        if (!head)
        {
            cout << "\nUnderflow detected." << endl;
            return;
        }

        while (p->next != head)
        {
            p = p->next;
        }

        head = head->next;
        p->next = head;

        delete (q);

        if (q)
        {
            delete (q);
            cout << "Node removed from head." << endl;
        }

        return;
    }

    int k = 1;

    while (k < pos && p != head)
    {
        k++;
        q = p;
        p = p->next;
    }

    q->next = p->next;
    delete (p);

    if (p)
    {
        delete (p);
        cout << "Node removed from " << pos << endl;
    }
}

template <typename T>
void cll<T>::print()
{
    node<T> *p = head;

    if (!head)
    {
        cout << "\nUnderflow detected." << endl;
        return;
    }

    cout << "\n List content are: ";
    while (p != head)
    {
        cout << p->data << " ";
        p = p->next;
    }

    return;
}

template <typename T>
int cll<T>::length()
{
    node<T> *p = head;
    int count = 0;

    if (!head)
    {
        cout << "\nUnderflow detected." << endl;
        return -1;
    }

    while (p != head)
    {
        ++count;
        p = p->next;
    }

    return count;
}
