#include <iostream>

using std::cin;
using std::cout;
using std::endl;

struct Node 
{
    int key;
    Node* next;
};

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
    return head;
}

int find_middle(Node* head){
    Node* slow = head;
    Node* fast = head;        
    while(fast!=nullptr && fast->next!=nullptr)
    {
        fast = fast->next->next;                      
        slow = slow->next;
    }       
    return slow->key; 
}

int main()
{
    Node* head = nullptr;
    head = read_list(head);
    cout << find_middle(head) << endl;
    destroy_list(head);
    return 0;
}