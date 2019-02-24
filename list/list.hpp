// list
#include "ListNode.hpp"
#include <iostream>

template <class T>
class List {

    private:
    // 头尾哨兵节点
    int size;
    ListNode * header;
    ListNode * trailer;

    public:
    List();
    ~List();

    // 重载[]接口
    T& operator[] (Rank r) const;

    Rank size() const
    {
        return size;
    }

    bool isEmpty() const
    {
        if header->next != nullptr
            return true;
        else
            return false;
    }

    ListNode * first() const
    {
        return header->next;
    }
    ListNode * last() const;
    {
        ListNode * current = header;
        ListNode * firsrNode;
        while (current != trailer)
        {
            firstNode = firstNode->next;
        }
        return firstNode;
    }
};

template <typename T>
List()
{
    header = new ListNode;
    trailer = new ListNode;
    header->next = trailer;
    trailer->next = nullptr;
}

template <typename T>
T& operator[] (Rank r) const
{
    ListNode * current = header;
    int count = 0;
    while (count != r)
    {
        current = current->next;
        count++;
    }
    return current->data;
}