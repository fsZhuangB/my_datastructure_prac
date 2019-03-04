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
    // 默认构造函数
    List() { init(); };
    // 返回链表大小
    int size();
    // 重载[]操作符
    T& operator[] (Rank r) const;
    
};

template <typename T>
void List<T>::init() 
{
    header = new ListNode<T>;
    trailer = new ListNode<T>;
    header->succ = trailer;
    header->pre = nullptr;
    trailer->succ = nullptr;
    trailer->pre = header;
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

template <typename T>
T& List<T>::operator[] (Rank r) const
{
    ListNode<T>* current = header->next;
    int count = 0;
    while (current != trailer && count != r)
    {
        current = current->next;
        count++;
    }
    return current->data;
}


