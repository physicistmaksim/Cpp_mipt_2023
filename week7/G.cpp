#include <iostream>

// TODO: место для реализации вашей структуры Node
struct Node
{
    int key = 0;
    Node *next = nullptr;
};
// функций void push_back(Node*& head_ref, int new_key)
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

Node *find(Node *head_ref, int key)
{
    if (head_ref == nullptr)
    {
        return nullptr;
    }
    else
    {
        Node *ptr = head_ref;
        while (ptr != nullptr)
        {
            if (ptr->key == key)
                return ptr;
            else
            {
                ptr = ptr->next;
            }
        }
        return nullptr;
    }
}

using std::cout;
using std::endl;

int main()
{
    Node *HEAD = nullptr, *current = nullptr;
    push_back(HEAD, 0);
    push_back(HEAD, 1);
    push_back(HEAD, 2);
    current = find(HEAD, 2);
    if (current->key == 2)
    {
        cout << "OK" << endl;
    }
    return 0;
}