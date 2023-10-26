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

Node* mergeTwoLists(Node* list1, Node* list2)
{
    Node* ptr_1 = list1;
    Node* ptr_2 = list2;
    Node* ptr_3 = nullptr;
    if(ptr_1 != nullptr and ptr_2 != nullptr)
    {
        if(ptr_1->key <= ptr_2->key)
        {
            ptr_3 = ptr_1;
            ptr_1 = ptr_1->next;
        }
        else
        {
            ptr_3 = ptr_2;
            ptr_2 = ptr_2->next;
        }
        Node* head = ptr_3;
        while(ptr_1 != nullptr or ptr_2 != nullptr)
        {
            if(ptr_2 == nullptr)
            {
                ptr_3->next = ptr_1;
                break;
            }
            else if(ptr_1 == nullptr)
            {
                ptr_3->next = ptr_2;
                break;
            }
            else
            {
                if(ptr_1->key <= ptr_2->key)
                {
                    Node* temp = ptr_1;
                    ptr_1 = ptr_1->next;
                    ptr_3->next = temp;
                    ptr_3 = ptr_3->next;
                }
                else
                {
                    Node* temp = ptr_2;
                    ptr_2 = ptr_2->next;
                    ptr_3->next = temp;
                    ptr_3 = ptr_3->next;
                }
            }
        }
        return head;
    }
    else if(ptr_1 != nullptr)
    {
        return ptr_1;
    }
    return ptr_2;
}

int main()
{
    Node* head_1 = nullptr;
    head_1 = read_list(head_1);
    Node* head_2 = nullptr;
    head_2 = read_list(head_2);
    Node* head = mergeTwoLists(head_1, head_2);
    print_list(head);
    destroy_list(head);
    return 0;
}