#include <iostream>

struct Node
{
    int key = 0;
    Node *next = nullptr;
};

void insert_after(Node *&prev_ref, int new_key)
{
    if (prev_ref == nullptr)
    {
        return;
    }
    else
    {
        Node *new_node = new Node;
        Node *temp = prev_ref->next;
        prev_ref->next = new_node;
        new_node->key = new_key;
        new_node->next = temp;
    }
}

using std::cout;
using std::endl;

int main()
{
    Node *HEAD = new Node;
    insert_after(HEAD, 0);
    insert_after(HEAD, 1);
    insert_after(HEAD, 2);
    Node *ptr = HEAD;
    while (ptr->next != nullptr)
    {
        cout << ptr->key << ' ';
        ptr = ptr->next;
    }
    cout << ptr->key << endl;
    ptr = HEAD;
    while (ptr->next != nullptr)
    {
        ptr = HEAD->next;
        delete HEAD;
        HEAD = ptr;
    }
    delete HEAD;
    return 0;
}