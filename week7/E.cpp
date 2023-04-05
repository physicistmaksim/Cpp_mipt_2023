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

void destroy_list(Node *&head_ptr)
{
    Node *ptr = head_ptr;
    while (ptr != nullptr)
    {
        Node *next = ptr->next;
        delete ptr;
        ptr = next;
    }
    head_ptr = nullptr;
}

using std::cout;
using std::endl;

int main()
{
    Node *HEAD = nullptr;
    push_back(HEAD, 0);
    push_back(HEAD, 1);
    push_back(HEAD, 2);
    destroy_list(HEAD);
    if (HEAD == nullptr)
    {
        cout << "OK" << endl;
    }
    return 0;
}