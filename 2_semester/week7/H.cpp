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

void remove_key(Node *&head_ptr, int key)
{
    if (head_ptr != nullptr)
    {
        Node *ptr = head_ptr;
        if (head_ptr->key == key)
        {
            head_ptr = ptr->next;
            delete ptr;
        }
        else
        {
            Node *temp = head_ptr;
            while (ptr->key != key)
            {
                temp = ptr;
                ptr = ptr->next;
                if (ptr == nullptr)
                {
                    return;
                }
            }
            temp->next = ptr->next;
            delete ptr;
        }
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
    remove_key(HEAD, 0);
    remove_key(HEAD, 1);
    remove_key(HEAD, 2);
    remove_key(HEAD, 3);
    if (HEAD == nullptr)
    {
        cout << "OK" << endl;
    }
    return 0;
}