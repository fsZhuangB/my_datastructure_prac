// 单向链表类
#include "ListNode.hpp"
#include <iostream>

template <class T>
class List {
friend void BuildOneTwoThree(List<T>& mylist);

    public:
    // 头尾哨兵节点
    int _size;
    ListNode<T> * header;
    ListNode<T> * trailer;

    public:
    List();
    //~List();

    // 重载[]接口
    T& operator[] (Rank r) const
    {
        ListNode<T> * current = header;
        int count = 0;
        while (count != r)
        {
            current = current->next;
            count++;
        }
        return current->next->data;
    }

    Rank size() const
    {
        return _size;
    }

    bool isEmpty() const
    {
        if (header->next != nullptr)
            return true;
        else
            return false;
    }

    ListNode<T>* first() const
    {
        return header->next;
    }
    ListNode<T>* last() const
    {
        ListNode<T>* current = header;
        ListNode<T>* firstNode;
        while (current != trailer)
        {
            firstNode = firstNode->next;
            current = current->next;
        }
        return firstNode;
    }
};

template <typename T>
List<T>::List()
{
    header = new ListNode<T>;
    trailer = new ListNode<T>;
    header->next = trailer;
    trailer->next = nullptr;
    _size = 0;
}

template <typename T>
void BuildOneTwoThree(List<T>& mylist)
{
    ListNode<T>* One;
    ListNode<T>* Two; 
    ListNode<T>* Three;

    One = new ListNode<T>;
    Two = new ListNode<T>;
    Three = new ListNode<T>;

    One->data = 1;
    mylist->header->next = &One;
    One->next = mylist.trailer;

    Two->data = 2;
    One->next = &Two;
    Two->next = mylist.trailer;

    Three->data = 3;
    Two->next = &Three;
    Three->next = mylist.trailer;

    //return header;
}