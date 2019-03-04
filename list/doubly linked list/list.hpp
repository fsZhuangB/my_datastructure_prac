#include "listNode.hpp"
#include <iostream>

template <typename T>
class List {

private:
    // 头尾哨兵节点
    ListNode<T>* header;
    ListNode<T>* trailer;

protected:
    void init();

public:
    List() { init() };
    int size();
};

template <typename T>
void List<T>::init() 
{
    header = new ListNode<T>;
    trailer = new ListNode<T>;
    header->succ = trailer;
    header->pred = nullptr;
    trailer->succ = nullptr;
    trailer->pred = header;
}

template <typename T>
int List<T>::size()
{
    ListNode<T>* current = header->next;
    int count = 0;
    while (current != trailer)
    {
        current = current->succ;
        count++;
    }
    return count;
}

