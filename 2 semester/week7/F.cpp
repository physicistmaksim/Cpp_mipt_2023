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
// void remove(Node*& head_ptr)

void print_list(Node *head_ptr)
{
    if (head_ptr == nullptr)
    {
        std::cout << std::endl;
    }
    else
    {
        Node *ptr = head_ptr;
        std::cout << ptr->key;
        ptr = ptr->next;
        while (ptr != nullptr)
        {
            std::cout << " " << ptr->key;
            ptr = ptr->next;
        }
        std::cout << std::endl;
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
    print_list(HEAD);
    // remove(HEAD);
    return 0;
}