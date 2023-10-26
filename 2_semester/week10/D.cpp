#include <iostream>

using namespace std;

struct Node
{
    int key;
    Node* next = nullptr;
};

void insert(Node *&head_ref, int new_data)
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

int main()
{
    int M;
    cin >> M;
    Node* root = new Node;
    int N;
    cin >> N;
    if(N > 1)
    {
        cin >> root->key;
        for(int i = 0; i < N - 1; ++i)
        {
            int m;
            cin >> m;
            insert(root, m);
        }
    }
    else if(N == 1)
    {
        cin >> root->key;
    }
    int counter = 0;
    while(true)         
    {
        Node* tmp = root;
        int free_memory = 0;
        int key_to_delete = -1;
        while(tmp != nullptr)
        {
            if(M - tmp->key >= free_memory)
            {
                free_memory = M - tmp->key;
                key_to_delete = tmp->key;
            }
            tmp = tmp->next;
        }
        if(key_to_delete == -1)
            break;
        else if(M == 0)
        {
            counter++;
            break;
        }
        else
        {
            counter++;
            M = free_memory;
            remove_key(root, key_to_delete);
        }
    }
    delete_arr(root);
    cout << counter << endl;
    return 0;
}