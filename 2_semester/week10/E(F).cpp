#include <iostream>

using namespace std;

struct Node
{
    int begin;
    int end;
    Node* next = nullptr;
};

void insert(Node *&head_ref, int begin, int end)
{
    if (head_ref == nullptr)
    {
        Node *new_node = new Node;
        new_node->begin = begin;
        new_node->end = end;
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
        new_node->begin = begin;
        new_node->end = end;
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

int main()
{
    Node* root = new Node;
    int S;
    cin >> S;
    if(S > 1)
    {
        cin >> root->begin;
        cin >> root->end;
        for(int i = 0; i < S - 1; ++i)
        {
            int begin, end;
            cin >> begin;
            cin >> end;
            insert(root, begin, end);
        }
    }
    else if(S == 1)
    {
        cin >> root->begin;
        cin >> root->end;
    }

    int counter = 1;
    int flag = 0;
    Node* tmp = root;
    Node* ptr = root;
    while(flag == 0)
    {
        flag = 1;
        ptr = root;
        while(ptr != nullptr)
        {
            if(tmp->begin == ptr->begin and (ptr->end < tmp->end))
            {
                tmp = ptr;
            }
            ptr = ptr->next;
        }
        int end_tmp = tmp->end;
        ptr = root;
        while(ptr != nullptr)
        {
            if(ptr->begin >= end_tmp)
            {
                counter++;
                flag = 0;
                tmp = ptr;
                break;
            }
            ptr = ptr->next;
        }
        ptr = root;
        while(ptr != nullptr)
        {
            if(ptr->begin >= end_tmp and ptr->begin < tmp->begin)
            {
                tmp = ptr;
            }
            ptr = ptr->next;
        }
    }
    destroy_list(root);
    cout << counter << endl;
    return 0;
}