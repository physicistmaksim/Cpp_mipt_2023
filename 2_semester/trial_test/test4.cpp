#include <iostream>

using namespace std;

struct Node
{
    int key = 0;
    Node *next = nullptr;
};

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

void func(Node *head, int n)
{
    Node* head2 = nullptr;
    while (head != nullptr)
    {
        int max = head->key;
        Node* tmp = head;
        while (tmp != nullptr)
        {
            if(tmp->key > max)
                max = tmp->key;
            tmp = tmp->next;
        }
        remove_key(head, max);
        push_back(head2, max);
    }
    Node* tmp = head2;
    while (tmp != nullptr)
    {
        cout << tmp->key;
        tmp = tmp->next;
    }
    cout << endl;
    destroy_list(head2);
}

int main()
{
    int N;
    //cin >> N;
    N = 3;
    Node* head = nullptr;
    /*for(int i = 0; i < N; ++i)
    {
        int tmp;
        cin >> tmp;
        push_back(head, tmp);
    }*/
    push_back(head, 0);
    push_back(head, 0);
    push_back(head, 1);
    func(head, N);
    destroy_list(head);
    return 0;
}