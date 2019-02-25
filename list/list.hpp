// 单向链表类
#include "ListNode.hpp"
#include <iostream>

template <class T>
class List {

    private:
    // 头尾哨兵节点
    int _size;
    ListNode<T> * header;
    ListNode<T> * trailer;

    public:
    List();
    ~List();

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
        if header->next != nullptr
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
    header = new ListNode;
    trailer = new ListNode;
    header->next = trailer;
    trailer->next = nullptr;
}

template <typename T>
T& operator[] (Rank r) const
{

}