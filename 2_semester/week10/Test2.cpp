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
void delete_arr(Node* root)
{
    while(root->next != nullptr)
    {
        Node* next = root->next;
        delete root;
        root = next;
    }
    delete root;
}

int main()
{
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
    delete_arr(root);
    return 0;
}