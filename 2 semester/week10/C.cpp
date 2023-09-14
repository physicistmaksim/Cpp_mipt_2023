#include <iostream>

using namespace std;

struct Node
{
    int key;
    Node* prev = nullptr;
};


int main()
{
    int N;
    cin >> N;
    Node* root = new Node;
    Node* tmp = root;
    for(int i = 0; i< N; ++i)
    {
        cin >> tmp->key;
        Node* tmp_1 = new Node;
        tmp_1->prev = tmp;
        tmp = tmp_1;
    }
    Node* tmp_2 = tmp;
    tmp = tmp->prev;
    int M;
    cin >> M;
    int counter = 0;
    for(int i = 0; i < N; ++i)
    {
        while(M - tmp->key > 0)
        {
            M = M - tmp->key;
            counter++;
        }
        if(M - tmp->key == 0)
        {
            counter++;
            break;
        }
        else 
            tmp = tmp->prev;
    }
    while(tmp_2->prev != nullptr)
    {
        Node* tmp_3 = tmp_2->prev;
        delete tmp_2;
        tmp_2 = tmp_3;
    }
    delete tmp_2;
    cout << counter << endl;
    return 0;
}