#include <iostream>

struct Node
{
    Node *prev = nullptr;
    Node *next = nullptr;
    int key = 0;
};

struct List
{
    Node *HEAD = nullptr;
    Node *TAIL = nullptr;
    Node *NIL = nullptr;
    size_t size = 0;
};

List *create_empty_list()
{
    List *list = new List;
    list->NIL = new Node;
    list->HEAD = list->NIL;
    list->TAIL = list->NIL;
    return list;
}

List *push_back(List *list_ptr, int new_key)
{
    if (list_ptr == nullptr)
    {
        list_ptr = new List;
        list_ptr->HEAD = new Node;
        list_ptr->HEAD->key = new_key;
        list_ptr->HEAD->next = list_ptr->NIL;
        list_ptr->HEAD->prev = list_ptr->NIL;
        list_ptr->TAIL = list_ptr->HEAD;
        list_ptr->size = 1;
        return list_ptr;
    }
    else if (list_ptr->size == 0)
    {
        list_ptr->HEAD = new Node;
        list_ptr->HEAD->key = new_key;
        list_ptr->HEAD->next = list_ptr->NIL;
        list_ptr->HEAD->prev = list_ptr->NIL;
        list_ptr->TAIL = list_ptr->HEAD;
        list_ptr->size = 1;
        return list_ptr;
    }
    else if (list_ptr->size == 1)
    {
        Node *ptr = new Node;
        ptr->key = new_key;
        ptr->next = list_ptr->NIL;
        ptr->prev = list_ptr->HEAD;
        list_ptr->TAIL = ptr;
        list_ptr->HEAD->next = list_ptr->TAIL;
        list_ptr->size = 2;
        return list_ptr;
    }
    else
    {
        Node *ptr = new Node;
        ptr->key = new_key;
        ptr->next = list_ptr->NIL;
        ptr->prev = list_ptr->TAIL;
        list_ptr->TAIL->next = ptr;
        list_ptr->TAIL = ptr;
        list_ptr->size++;
        return list_ptr;
    }
}

void remove_key(List *list_ptr, int key)
{
    if (list_ptr != nullptr)
    {
        if (list_ptr->HEAD != list_ptr->NIL)
        {
            Node *current = list_ptr->HEAD;
            while (current != nullptr)
            {
                if (current->key == key)
                {
                    if ((list_ptr->HEAD->next == nullptr) or (list_ptr->HEAD->next == list_ptr->NIL))
                    {
                        list_ptr->TAIL = list_ptr->NIL;
                        list_ptr->HEAD = list_ptr->NIL;
                    }
                    else
                    {
                        if ((current->prev == nullptr) or (current->prev == list_ptr->NIL))
                        {
                            list_ptr->HEAD = current->next;
                            current->next->next->prev = list_ptr->HEAD;
                            if ((list_ptr->HEAD->next == nullptr) or (list_ptr->HEAD->next == list_ptr->NIL))
                            {
                                list_ptr->TAIL = list_ptr->NIL;
                                list_ptr->HEAD = list_ptr->NIL;
                            }
                            else
                            {
                                list_ptr->HEAD->next->prev = list_ptr->HEAD;
                            }
                        }
                        else if ((current->next == nullptr) or (current->next == list_ptr->NIL))
                        {
                            current->prev->next = list_ptr->NIL;
                            list_ptr->TAIL = current->prev;
                        }
                        else
                        {
                            current->prev->next = current->next;
                            current->next->prev = current->prev;
                        }
                    }
                    delete current;
                    return;
                }
                current = current->next;
            }
        }
    }
}

using std::cout;
using std::endl;

int main()
{
    List *list = create_empty_list();
    push_back(list, 0);
    push_back(list, 1);
    push_back(list, 2);
    remove_key(list, 2);
    if (list->TAIL->key == 1)
    {
        cout << "OK" << endl;
    }
    return 0;
}