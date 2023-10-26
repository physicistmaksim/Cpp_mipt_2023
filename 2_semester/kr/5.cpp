#include <cassert>
struct JumpList 
{ 
    JumpList *next, *jump; unsigned id; 
};
void erase_jump_list(JumpList *head) 
{
	if (nullptr == head) return;
    erase_jump_list(head->next);
    delete head;
}

JumpList* clone_jump_list(JumpList *head)
{
    JumpList* list = new JumpList;
    list->id = head->id;
    list->next = nullptr;
    JumpList *prev = list;
    JumpList* tmp = head;
    while(tmp != nullptr)
    {
        JumpList* ptr_ref = tmp->jump;
        JumpList* ptr = tmp;
        JumpList* ptr_real = prev;
        while(ptr->next != ptr_ref)
        {
            if(ptr_real->next == nullptr)
            {
                JumpList* q = new JumpList;
                q->id = ptr->next->id;
                q->next = nullptr;
                ptr_real->next = q;  
            }
            ptr_real = ptr_real->next;
            ptr = ptr->next;
        }
        JumpList* q = new JumpList;
        q->id = ptr->next->id;
        prev->jump = q;
        ptr_real->next = q;
        next->id = tmp->id;
        prev->next = next;
        prev = next;
        tmp = tmp->next;
    }
    return list;
}


int main() 
{
    JumpList *elements = new JumpList[6];
    elements[0] = JumpList{.next = &elements[1], .jump = &elements[3], .id = 1u};
    elements[1] = JumpList{.next = &elements[2], .jump = &elements[4], .id = 2u};
    elements[2] = JumpList{.next = &elements[3], .jump = &elements[5], .id = 3u};
    elements[3] = JumpList{.next = &elements[4], .jump = &elements[5], .id = 4u};
    elements[4] = JumpList{.next = &elements[5], .jump = nullptr, .id = 5u};
    elements[5] = JumpList{.next = nullptr, .jump = nullptr, .id = 6u};
    JumpList *clone = clone_jump_list(elements);

    JumpList *a = elements, *b = clone;
    while (nullptr != a) 
    {
        assert(a->id == b->id and a != b);
        if (nullptr != a->jump) 
        assert(a->jump->id == b->jump->id and a->jump != b->jump);
        a = a->next;
        b = b->next;
    }
    assert(nullptr == b);
    delete[] elements;
    erase_jump_list(clone);
	return 0;
}