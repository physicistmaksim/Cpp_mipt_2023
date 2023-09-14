#include <iostream>

using std::cin;
using std::cout;
using std::endl;

struct Node 
{
    int key;
    Node* next;
};

void print_list(Node* head_ptr)
{
    if(head_ptr == nullptr)
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

Node* read_list(Node* head)
{
    int a;
    cin >> a;
    while (a != 0)
    {
        push_back(head, a);
        cin >> a;
    }
    push_back(head, a);
    return head;
}

Node* reverse(Node* head)
{
    Node* a = nullptr;
    Node* b = head;
    Node* c = new Node;
    while (b != nullptr)
    {
        c = b->next;
        b->next = a;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    Node* head = nullptr;
    head = read_list(head);
    head = reverse(head);
    print_list(head);
    destroy_list(head);
    return 0;
}