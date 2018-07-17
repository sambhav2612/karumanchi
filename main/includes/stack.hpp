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
class stack
{
    node<T> *head;

  public:
    stack()
    {
        head = NULL;
    }

    node<T> *returnHead()
    {
        return head;
    }

    void push(int ele);
    T pop();
    void print();
    int length();
    T top();
    bool isEmpty();
};

template <typename T>
bool stack<T>::isEmpty()
{
    if (head == NULL)
        return true;
    return false;
}

template <typename T>
T stack<T>::top()
{
    if (head != NULL)
    {
        return head->data;
    }
}

template <typename T>
void stack<T>::insert(int ele)
{
    node<T> *newNode = new node<T>(ele);

    if (!head)
    {
        head = newNode;
        head->next = NULL;
        return;
    }

    newNode->next = head;
    head = newNode;

    if (head && head == newNode)
    {
        cout << ele << " successfully inserted at top." << endl;
    }
}

template <typename T>
T stack<T>::remove()
{
    node<T> *p = head;

    if (head == NULL)
    {
        cout << "\nUnderflow detected." << endl;
        return -1;
    }

    int data = head->data;
    head = head->next;
    delete (p);

    if (p)
    {
        delete (p);
    }

    cout << "Node removed from head." << endl;

    return data;
}

template <typename T>
void stack<T>::print()
{
    node<T> *p = head;

    if (head == NULL)
    {
        cout << "\nUnderflow detected." << endl;
        return;
    }

    cout << "\n List content are: ";
    while (p->next != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

template <typename T>
int stack<T>::length()
{
    node<T> *p = head;
    int count = 0;

    if (head == NULL)
    {
        cout << "\nUnderflow detected." << endl;
        return -1;
    }

    while (p != NULL)
    {
        ++count;
        p = p->next;
    }

    return count;
}
