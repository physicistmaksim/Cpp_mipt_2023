#include <cassert>

struct Node
{
    double key;
    Node* next = nullptr;
    Node* prev = nullptr;
};

struct Queue 
{
    Node* first = nullptr;
    Node* last = nullptr;
};

Queue queue_new() 
{
    Queue q;
    return q;
}

Queue& queue_push(Queue &q, double val) 
{
    if(q.first == nullptr)
    {
        q.first = new Node;
        q.first->key = val;
        q.last = q.first;
    }
    else if(q.first == q.last)
    {
        q.first = new Node;
        q.first->key = val;
        q.first->next = q.last;
        q.last->prev = q.first;
    }
    else
    {
        Node* tmp = q.first;
        q.first = new Node;
        q.first->key = val;
        q.first->next = tmp;
        tmp->prev = q.first;
    }
    return q;
}

double queue_pop(Queue &q) 
{
    if(q.first == q.last)
    {
        double tmp = q.last->key;
        delete q.last;
        q.first = nullptr;
        q.last = nullptr;
        return tmp;
    }
    double tmp = q.last->key;
    Node* tmp2 = q.last->prev;
    delete q.last;
    q.last = nullptr;
    q.last = tmp2;
    return tmp;
}

bool queue_is_empty(Queue const &q) 
{
    if(q.first == nullptr and q.last == nullptr)
        return true;
    return false;
}

int main() 
{
    double *arr = new double[1000];
    {
        double begin = 1.1, step = 0.1;
        for (unsigned cnt = 0; cnt != 1000; ++cnt) {
            arr[cnt] = begin;
            begin += step;
        }
    }

    auto q = queue_new();
    assert(true == queue_is_empty(q));
    for (unsigned cnt = 0; cnt != 1000; ++cnt)
        queue_push(q, arr[cnt]);
    assert(false == queue_is_empty(q));
    for (unsigned cnt = 0; cnt != 1000; ++cnt)
        assert(arr[cnt] == queue_pop(q));
    assert(true == queue_is_empty(q));
    delete[] arr;
}