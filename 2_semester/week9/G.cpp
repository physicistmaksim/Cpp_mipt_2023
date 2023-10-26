#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

struct Node
{
    string key;
    Node* next;
};

void push_back(Node *&head_ref, string new_data)
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

int main()
{
    std::string token;
    Node* head = new Node;
    while(true) 
    {
        std::getline(std::cin, token, ' ');
        if (token == "stop") 
            break;
        push_back(head, token);
    }
    
    return 0;
}