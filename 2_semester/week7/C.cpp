#include <iostream>

struct Node
{
    int key = 0;
    Node *next = nullptr;
};

void push_back(Node *&head_ref, int new_data)
{
    if (head_ref == nullptr)
    {
        Node *new_node = new Node;
        new_node->key = new_data;
        head_ref = new_node;
    }
    else
    {
        Node *ptr = head_ref;
        while (ptr->next != nullptr)
        {
            ptr = ptr->next;
        }
        Node *new_node = new Node;
        ptr->next = new_node;
        new_node->key = new_data;
    }
}

using std::cout;
using std::endl;

int main()
{
    Node *HEAD = nullptr;
    push_back(HEAD, 0);
    push_back(HEAD, 1);
    push_back(HEAD, 2);
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